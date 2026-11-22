# GTA San Andreas — Mundo Expandido

Proyecto de modificación original para **GTA San Andreas clásico (PC), versión 1.0 US**.

## Prioridad principal: ampliar el mapa

La primera zona preparada es **Costa Brava**, con 60 instancias principales y 13 registros LOD. El paquete incorpora el IPL a través de Mod Loader, dentro de `data/maps`, sin reemplazar los archivos originales del juego.

- Guía: [docs/INSTALACION_MAPA.md](docs/INSTALACION_MAPA.md).
- IPL fuente: [src/maps/costa_brava.ipl](src/maps/costa_brava.ipl).
- Proyecto editable: [src/maps/Costa-Brava.sa-map-studio.json](src/maps/Costa-Brava.sa-map-studio.json).

## Selector de modos en el menú inicial

El plugin ASI añade **MODOS** al menú principal y abre un submenú con Historia, Modo libre, Libre + Admin y Mundo expandido (deshabilitado hasta validar el mapa). Mantiene el flujo nativo para iniciar y cargar partidas.

- Fuente del plugin: [src/asi/MenuModes.cpp](src/asi/MenuModes.cpp).
- Guía y límites: [docs/SELECTOR_MODOS_FRONTEND.md](docs/SELECTOR_MODOS_FRONTEND.md).
- Instalación: [src/asi/README.md](src/asi/README.md).

**Límite importante:** Modo libre todavía no cancela automáticamente las misiones de historia. El selector guarda la elección y continúa por la pantalla nativa de nueva partida/carga. Libre + Admin habilita el panel F6; Historia y Modo libre no lo habilitan. Mundo expandido permanece deshabilitado hasta probar la zona.

## Compilación y compatibilidad

- Objetivo: GTA San Andreas clásico PC 1.0 US, ejecutable de 32 bits.
- Plugin ASI compilado como Win32; requiere ASI Loader x86.
- CLEO 4 para textos FXT y panel administrativo opcional.
- Mod Loader para cargar el IPL.
- Rendimiento objetivo: equipo de 4 GB RAM; modelos/texturas ligeros y LOD.

## Estado real

El workflow de GitHub Actions compiló el script CLEO, construyó el plugin ASI x86 y validó los 73 registros del IPL. **Eso no equivale a una prueba dentro de GTA SA.** Todavía hay que comprobar que el menú aparezca y responda, y verificar alturas, colisiones, agua, puente, LOD y rendimiento de Costa Brava dentro del juego.

La expansión geográfica completa continúa en desarrollo; no se presenta Costa Brava como zona validada.

## Derechos

Proyecto de fans no oficial. GTA y sus elementos originales pertenecen a sus titulares. No se redistribuyen archivos originales del juego ni recursos extraídos de GTA u otros mods sin permiso.


## Telefono y misiones secundarias

El modulo CLEO opcional `ME_Phone_Missions.cs` añade un telefono de texto que se abre con **F8**. Incluye acceso a economia y una cadena de tres encargos de conduccion con pagos crecientes. No es una interfaz grafica 3D ni reemplaza el modelo de telefono original.

La compilacion automatica comprueba que el script se genere; sus controles y pagos aun requieren prueba dentro de GTA SA 1.0 US.
