# Selector de modos en el frontend

## Implementación actual

El plugin ASI añade la entrada **MODOS** a la página principal del frontend (página 34) y utiliza la página reservada `MENUPAGE_EMPTY` (43) como submenú. Se conservan las opciones nativas de iniciar partida y opciones; el flujo nativo de nueva partida/carga se abre después de seleccionar un modo.

- HISTORIA: guarda `selected=0`.
- MODO LIBRE: guarda `selected=1`.
- LIBRE + ADMIN: guarda `selected=2`.
- MUNDO EXPANDIDO: deshabilitado hasta que el mapa tenga geometría, colisión y validación runtime.

El modo elegido se escribe en `CLEO/ME_MODE.ini`. El script CLEO lee ese valor cuando se pulsa F6 y solo permite abrir el panel administrativo en el modo 2.

## Archivos de implementación

- `src/asi/MenuModes.cpp`: hooks del frontend y navegación del selector.
- `src/asi/CMakeLists.txt`: compilación Win32 con MinHook.
- `src/asi/ME_MODOS.fxt`: etiquetas de interfaz.
- `src/cleo/ME_Core_Menu.txt`: panel F5/F6; F6 queda restringido a Libre + Admin.
- `.github/workflows/compile-cleo.yml`: compila CLEO, construye el ASI x86 y empaqueta el proyecto.

## Puntos técnicos del ejecutable objetivo

El código se basa en las estructuras de Plugin-SDK para GTA SA:
- `FrontEndMenuManager`: `0xBA6748`.
- `aScreens`: `0x8CE008`.
- `CMenuManager::Initialise`: `0x5744D0`.
- `CMenuManager::ProcessMenuOptions`: `0x576FE0`.
- `CMenuManager::SwitchToNewScreen`: `0x573680`.
- `m_nCurrentMenuEntry`: offset `0x54`.
- `m_nCurrentMenuPage`: offset `0x15D`.

Fuentes: [CMenuManager.h](https://github.com/DK22Pac/plugin-sdk/blob/master/plugin_sa/game_sa/CMenuManager.h) y [CMenuManager.cpp](https://github.com/DK22Pac/plugin-sdk/blob/master/plugin_sa/game_sa/CMenuManager.cpp).

## Límites conocidos

**MODO LIBRE todavía no es un modo sin misiones.** El selector guarda el modo y continúa por el flujo nativo de nueva partida/carga. La cancelación segura de las misiones automáticas de historia no está implementada.

**MUNDO EXPANDIDO está bloqueado** porque Costa Brava todavía no se ha comprobado dentro de GTA SA. No se habilitará hasta verificar terreno, colisión, unión con la costa, agua, LOD y rendimiento.

La compilación del plugin no sustituye la prueba dentro del juego. Antes de instalar, conserva una copia de la carpeta del juego y de las partidas guardadas.
