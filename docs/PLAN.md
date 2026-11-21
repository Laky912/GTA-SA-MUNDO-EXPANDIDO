# Plan de desarrollo

La prioridad principal del proyecto es **agrandar el mundo explorable de GTA San Andreas**. Los menús, trucos y trabajos son secundarios y no deben desplazar el desarrollo del mapa.

## Orden real de trabajo

1. **Expansión geográfica:** diseñar nuevas zonas conectadas al mapa original, construir terreno y costa propios, crear colisiones, colocar carreteras y accesos, e integrar los archivos IDE/IPL mediante Mod Loader.
2. **Prueba de mapa:** comprobar carga de modelos, colisiones, límites, agua, radar, puentes/accesos y rendimiento en GTA SA 1.0 US.
3. **Modo libre:** conectar el menú F5 a sistemas reales; mantener F6 como herramienta administrativa opcional.
4. **Vehículos y actividades:** taxi, transporte, reparto, policía y carreras dentro del mapa ampliado.
5. **Economía y guardado:** pagos, progreso, propiedades y negocios persistentes.
6. **Protagonistas:** dos personajes originales intercambiables, con comprobaciones de carga y guardado.
7. **Relaciones opcionales:** citas y escenas sugeridas no explícitas.
8. **Integración:** ZIP único, documentación, instalación/desinstalación y pruebas de regresión.

## Fases de la expansión

- **Mapa A — primera zona nueva:** una región insular costera conectada por carretera y/o ferry, con terreno propio, playas, vías y un pequeño núcleo urbano.
- **Mapa B — ampliación:** añadir una segunda zona solo después de validar la primera.
- **Mapa C — pulido:** señalización, límites, radar, ambientación, tráfico y puntos de interés.

La ubicación y las coordenadas definitivas se fijarán sobre la cartografía real de GTA SA en un editor de mapas; no se inventarán coordenadas sin verificar que estén libres y dentro de los límites del mundo.

## Criterios de salida

- El juego inicia sin errores.
- La nueva tierra tiene geometría y colisión reales; no basta con poner objetos decorativos sobre el agua.
- Los accesos conectan con el mapa original y no dejan al jugador atrapado.
- IDE/IPL, DFF, TXD y COL coinciden y se cargan desde Mod Loader.
- Se revisan streaming, LOD, radar, agua y rendimiento en el equipo objetivo de 4 GB.
- No se declara terminada una zona hasta probarla dentro del juego.

## Estado honesto

El repositorio todavía no contiene una expansión geográfica jugable. El módulo CLEO existente solo aporta un menú, acciones administrativas y un prototipo de reparto. La expansión del mapa pasa a ser el primer bloque de implementación y es el trabajo pendiente prioritario.
