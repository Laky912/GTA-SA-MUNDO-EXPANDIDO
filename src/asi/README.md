# Plugin ASI — Selector MODOS

## Objetivo
Añade la entrada **MODOS** al menú principal de GTA San Andreas clásico y abre una página propia con estas opciones:

- HISTORIA: guarda el modo 0 y abre la página nativa de nueva partida/cargar partida.
- MODO LIBRE: guarda el modo 1 y abre la misma página nativa.
- LIBRE + ADMIN: guarda el modo 2 y abre la misma página nativa. El script CLEO limita F6 a este modo.
- MUNDO EXPANDIDO: aparece deshabilitado mientras Costa Brava no tenga validación completa dentro del juego.

## Archivos
- `MenuModes.cpp`: hooks del frontend para GTA SA 1.0 US.
- `CMakeLists.txt`: build Win32 con MinHook 1.3.4.
- `ME_MODOS.fxt`: textos españoles para CLEO FXT.

## Requisitos
- GTA San Andreas clásico PC 1.0 US (no Definitive Edition).
- ASI Loader x86.
- CLEO 4 para los textos FXT y el panel administrativo.
- El plugin está compilado para Win32, nunca x64.

## Compilación
Desde una consola de desarrollador de Visual Studio:
```powershell
cmake -S src/asi -B build/asi -A Win32
cmake --build build/asi --config Release
```

El resultado es `MundoExpandido.asi`.

## Límites de la versión
El selector almacena el modo elegido en `CLEO/ME_MODE.ini` y conserva el flujo nativo de iniciar/cargar. La selección MODO LIBRE todavía no desactiva automáticamente las misiones de historia: para un mundo libre real hace falta un mecanismo seguro de cancelación/omisión de misión y una prueba en runtime. No se debe presentar como modo sin misiones terminado.
