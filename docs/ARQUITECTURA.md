# Arquitectura técnica

## Objetivo de ejecución

- GTA San Andreas clásico para PC, ejecutable 1.0 US.
- CLEO como capa principal de scripting.
- Mod Loader para distribuir archivos sin sobrescribir los originales.
- SilentPatch se mantiene como dependencia externa del usuario.
- Recursos propios y ligeros; no se redistribuyen archivos del juego.

## Organización prevista

- `src/cleo/`: fuentes Sanny Builder de los scripts CLEO.
- `data/`: configuración editable y datos del mundo.
- `assets/`: recursos originales del proyecto, separados por tipo.
- `docs/`: compatibilidad, controles, instalación y notas técnicas.
- `build/`: salida generada; nunca se considera fuente editable.

## Reglas de implementación

1. Cada sistema debe poder desactivarse desde configuración cuando sea razonable.
2. Los scripts deben esperar al estado de juego adecuado antes de crear actores, vehículos o marcadores.
3. No se deben crear bucles de espera activa sin `wait`.
4. Evitar spawns masivos, texturas grandes y carga simultánea de modelos.
5. Los datos persistentes deben validarse antes de usarse; si faltan, se usan valores iniciales seguros.
6. Las funciones que dependan de recursos externos deben comprobar que esos recursos existan.
7. No declarar una función terminada hasta compilarla y probarla en GTA SA 1.0 US.

## Interfaz

El plugin ASI añade MODOS al frontend inicial y conserva el flujo nativo de iniciar/cargar partida. F5 abre el panel general CLEO y F6 el panel administrativo, restringido al modo Libre + Admin. El modo libre todavía no cancela misiones automáticamente y Mundo Expandido permanece bloqueado hasta validar Costa Brava dentro del juego.

## Estado de verificación

El código actual es fuente Sanny Builder y requiere compilación para convertirse en un script CLEO ejecutable. La compilación y las pruebas dentro del juego siguen pendientes; este repositorio no etiqueta la fuente como una versión instalable.


## Compilación automatizada

El workflow `.github/workflows/compile-cleo.yml` descarga la versión oficial de Sanny Builder 4.2.0 y compila las fuentes CLEO en un runner Windows. El artefacto resultante sirve para comprobar que el código fuente puede convertirse en un script binario; no equivale a una prueba dentro del juego.

La documentación oficial confirma el uso de `--compile` en la CLI y la directiva `{$CLEO .cs}` para generar scripts CLEO independientes:
- https://docs.sannybuilder.com/editor/cli
- https://tutorial.sannybuilder.com/cleo-directive/

## Pruebas que todavía requieren el juego

La compilación automática no puede verificar el comportamiento real de GTA SA. Antes de una versión final habrá que probar inicio, carga de partida, apertura/cierre del panel, controles, guardado y rendimiento en la instalación SA 1.0 US del usuario.


## Panel de administrador

La fuente principal reserva F6 para un panel separado del menú F5. En esta primera iteración incluye acciones directas de modo libre: añadir dinero en dos cantidades, restaurar salud y chaleco, y quitar el nivel de búsqueda policial. ESC cierra ambos paneles. El panel es local para un jugador; no implementa autenticación ni permisos de servidor.
