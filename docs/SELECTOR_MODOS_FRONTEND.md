# Integración del selector de modos en el frontend

## Objetivo visual

Añadir una opción **MODOS** en el flujo inicial del juego, junto a las opciones de nueva partida y carga de partida. No sustituye el menú nativo ni el selector de archivos guardados.

Al entrar en MODOS, la propuesta es:
1. Historia: conserva el comportamiento nativo de nueva partida y carga.
2. Libre: inicia el mundo sin iniciar la cadena de misiones.
3. Libre + administrador: mismo modo libre y habilita las herramientas administrativas del proyecto.
4. Mundo expandido: solo se habilita cuando la región geográfica esté integrada y validada dentro del juego.

## Investigación técnica confirmada

El frontend de GTA SA clásico expone una estructura interna de páginas:
- `CMenuManager` administra el frontend.
- `aScreens` apunta al arreglo de `CMenuScreen`.
- Cada página contiene hasta 12 entradas.
- Las entradas almacenan acción, clave GXT, slot de guardado, página destino y posición.
- `MENUPAGE_NEW_GAME` es la página nativa que agrupa Nueva partida, Cargar partida y Borrar partida.
- `MENUPAGE_EMPTY` existe como página reservada/vacía.
- `MENUACTION_CHANGEMENU` es una acción nativa para navegar a otra página.

Referencias de ingeniería consultadas:
- https://github.com/DK22Pac/plugin-sdk/blob/master/plugin_sa/game_sa/CMenuManager.h
- https://github.com/DK22Pac/plugin-sdk/blob/master/plugin_sa/game_sa/CMenuManager.cpp

## Direcciones y estructuras de referencia

En el Plugin-SDK para GTA SA 1.0 US:
- `FrontEndMenuManager`: dirección global `0xBA6748`.
- `aScreens`: dirección global `0x8CE008`.
- `CMenuManager::SwitchToNewScreen`: dirección de función `0x573680`.
- `CMenuManager::ProcessPCMenuOptions`: dirección de función `0x57CD50`.
- `CMenuManager::ProcessMenuOptions`: dirección de función `0x576FE0`.

Estas direcciones son referencias del ejecutable soportado por Plugin-SDK; no deben usarse a ciegas en otras versiones, ejecutables modificados o GTA SA Definitive Edition.

## Por qué todavía no se inserta una entrada a ciegas

Cambiar una entrada de `aScreens` no basta para entregar una función segura. También hay que:
- proporcionar claves GXT válidas para el texto español;
- comprobar qué página exacta se muestra en el flujo inicial en el ejecutable objetivo;
- interceptar la selección de MODOS y despachar una acción propia;
- evitar sobrescribir entradas o páginas usadas por el juego u otros plugins;
- conservar intactos los flujos de guardado/carga;
- validar el resultado en GTA SA 1.0 US con ASI Loader y Mod Loader.

Una entrada que solo se dibuje pero no tenga una acción válida sería un falso avance y no se incluirá como función terminada.

## Diseño de la acción

La acción del selector debe guardar la elección del modo y luego delegar en el flujo nativo de nueva partida o carga. La selección no debe ejecutar trucos mientras el usuario está en el frontend.

- `HISTORY`: flujo original.
- `FREE_ROAM`: carga de mundo y desactivación controlada de disparadores de misión; no se debe borrar progreso ni bloquear guardados por defecto.
- `FREE_ROAM_ADMIN`: igual que libre, con el panel administrativo habilitado.
- `EXPANDED_WORLD`: solo seleccionable cuando la región tenga geometría, colisiones, streaming y accesos verificados.

## Estado

Investigación de estructuras y puntos de entrada: **documentada**.
Implementación ASI del selector: **pendiente**.
Compilación del plugin: **pendiente**.
Prueba dentro del juego: **pendiente**.

No se debe presentar este documento como un menú ya instalado ni como una expansión del mapa terminada.
