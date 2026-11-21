#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <cstdint>
#include <cstring>
#include <cstdio>
#include <MinHook.h>

namespace {
constexpr uintptr_t kMenuManagerAddress = 0x00BA6748;
constexpr uintptr_t kScreensAddress = 0x008CE008;
constexpr uintptr_t kInitialiseAddress = 0x005744D0;
constexpr uintptr_t kProcessMenuOptionsAddress = 0x00576FE0;
constexpr uintptr_t kSwitchToNewScreenAddress = 0x00573680;

constexpr int kMainMenuPage = 34;
constexpr int kModesPage = 43; // MENUPAGE_EMPTY in GTA SA 1.0 US
constexpr int kNewGamePage = 1;

enum MenuAction : uint8_t {
    ACTION_NOTHING = 0,
    ACTION_CHANGEMENU = 5,
    ACTION_SKIP = 20
};

struct MenuEntry {
    uint8_t action;
    char name[8];
    uint8_t saveSlot;
    int8_t targetMenu;
    uint8_t pad;
    uint16_t x;
    uint16_t y;
    uint8_t align;
    uint8_t tailPad;
};
struct MenuScreen {
    char screenName[8];
    int8_t previousPage;
    int8_t parentEntry;
    MenuEntry entries[12];
};

static_assert(sizeof(MenuEntry) == 18, "Unexpected CMenuEntry layout");
static_assert(sizeof(MenuScreen) == 0xE2, "Unexpected CMenuScreen layout");

using InitialiseFn = void(__thiscall*)(void*);
using ProcessMenuOptionsFn = void(__thiscall*)(void*, char, char*, char);
using SwitchToNewScreenFn = char(__thiscall*)(void*, char);

InitialiseFn g_originalInitialise = nullptr;
ProcessMenuOptionsFn g_originalProcessMenuOptions = nullptr;
SwitchToNewScreenFn SwitchToNewScreen =
    reinterpret_cast<SwitchToNewScreenFn>(kSwitchToNewScreenAddress);

bool g_patched = false;

void WriteSelectedMode(int mode) {
    char path[MAX_PATH]{};
    GetCurrentDirectoryA(MAX_PATH, path);
    const size_t len = std::strlen(path);
    if (len + sizeof("\\CLEO\\ME_MODE.ini") >= MAX_PATH)
        return;
    std::strcat(path, "\\CLEO\\ME_MODE.ini");
    char value[8]{};
    std::snprintf(value, sizeof(value), "%d", mode);
    WritePrivateProfileStringA("mode", "selected", value, path);
}

void SetEntryText(MenuEntry& entry, const char* key) {
    std::memset(entry.name, 0, sizeof(entry.name));
    std::strncpy(entry.name, key, sizeof(entry.name) - 1);
}

void PatchFrontend() {
    if (g_patched)
        return;

    auto* screens = reinterpret_cast<MenuScreen*>(kScreensAddress);
    MenuScreen& main = screens[kMainMenuPage];
    MenuScreen& modes = screens[kModesPage];

    // Do not patch a page that does not resemble the expected main menu.
    if (main.entries[0].name[0] == '\0' ||
        main.entries[0].action == ACTION_NOTHING)
        return;

    if (std::strncmp(main.entries[1].name, "MEMODOS", 7) == 0) {
        g_patched = true;
        return;
    }

    // Keep the native Start Game / Options / Quit entries intact.
    // The original main page uses the first three slots; shift Options and Quit.
    for (int i = 11; i >= 2; --i)
        main.entries[i] = main.entries[i - 1];

    MenuEntry modesEntry = main.entries[0];
    modesEntry.action = ACTION_CHANGEMENU;
    modesEntry.targetMenu = static_cast<int8_t>(kModesPage);
    modesEntry.saveSlot = 0;
    modesEntry.pad = 0;
    SetEntryText(modesEntry, "MEMODOS");
    modesEntry.y = static_cast<uint16_t>(main.entries[0].y + 22);
    main.entries[1] = modesEntry;

    // Move the displaced native entries down by one row.
    for (int i = 2; i <= 3; ++i) {
        if (main.entries[i].name[0] != '\0')
            main.entries[i].y = static_cast<uint16_t>(main.entries[i].y + 22);
    }

    std::memset(&modes, 0, sizeof(modes));
    std::memcpy(modes.screenName, "MEMODOS", 7);
    modes.previousPage = static_cast<int8_t>(kMainMenuPage);
    modes.parentEntry = 1;

    const MenuEntry layout = main.entries[0];
    const char* keys[] = { "MEHIST", "MELIBRE", "MEADMIN", "MEPRONTO" };
    for (int i = 0; i < 4; ++i) {
        MenuEntry& entry = modes.entries[i];
        entry = layout;
        entry.action = (i == 3) ? ACTION_SKIP : ACTION_NOTHING;
        entry.targetMenu = 0;
        entry.saveSlot = 0;
        entry.pad = 0;
        SetEntryText(entry, keys[i]);
        entry.y = static_cast<uint16_t>(layout.y + i * 22);
    }

    g_patched = true;
}

void __fastcall HookInitialise(void* self, void*) {
    g_originalInitialise(self);
    PatchFrontend();
}

void __fastcall HookProcessMenuOptions(
    void* self, void*, char input, char* exit, char enter) {

    const auto currentPage = *reinterpret_cast<int8_t*>(
        reinterpret_cast<uintptr_t>(self) + 0x15D);
    if (currentPage != kModesPage) {
        g_originalProcessMenuOptions(self, input, exit, enter);
        return;
    }

    const int selected = *reinterpret_cast<int*>(
        reinterpret_cast<uintptr_t>(self) + 0x54);

    if (exit && *exit) {
        *exit = 0;
        SwitchToNewScreen(self, static_cast<char>(kMainMenuPage));
        return;
    }

    if (!enter)
        return;

    if (selected == 0) {
        WriteSelectedMode(0); // Historia
        SwitchToNewScreen(self, static_cast<char>(kNewGamePage));
    } else if (selected == 1) {
        WriteSelectedMode(1); // Libre
        SwitchToNewScreen(self, static_cast<char>(kNewGamePage));
    } else if (selected == 2) {
        WriteSelectedMode(2); // Libre + administrador
        SwitchToNewScreen(self, static_cast<char>(kNewGamePage));
    }
    // The expanded-world entry is intentionally skipped until the map
    // has real geometry/collision and has passed an in-game validation.
}

DWORD WINAPI InstallHooks(void*) {
    // GTA SA 1.0 US is a 32-bit process. Never install fixed-address hooks
    // into another executable layout.
    if (sizeof(void*) != 4 || GetModuleHandleA("gta_sa.exe") == nullptr)
        return 0;

    if (MH_Initialize() != MH_OK)
        return 0;

    if (MH_CreateHook(reinterpret_cast<void*>(kInitialiseAddress),
                      &HookInitialise,
                      reinterpret_cast<void**>(&g_originalInitialise)) != MH_OK)
        return 0;

    if (MH_CreateHook(reinterpret_cast<void*>(kProcessMenuOptionsAddress),
                      &HookProcessMenuOptions,
                      reinterpret_cast<void**>(&g_originalProcessMenuOptions)) != MH_OK)
        return 0;

    if (MH_EnableHook(reinterpret_cast<void*>(kInitialiseAddress)) != MH_OK)
        return 0;
    if (MH_EnableHook(reinterpret_cast<void*>(kProcessMenuOptionsAddress)) != MH_OK)
        return 0;

    return 0;
}
} // namespace

BOOL APIENTRY DllMain(HMODULE module, DWORD reason, LPVOID) {
    if (reason == DLL_PROCESS_ATTACH) {
        DisableThreadLibraryCalls(module);
        HANDLE thread = CreateThread(nullptr, 0, InstallHooks, nullptr, 0, nullptr);
        if (thread)
            CloseHandle(thread);
    }
    return TRUE;
}
