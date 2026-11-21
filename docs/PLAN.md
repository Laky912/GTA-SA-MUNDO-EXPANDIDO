# Plan de desarrollo

La prioridad principal del proyecto es **agrandar el mundo explorable de GTA San Andreas**. Los menús, trucos y trabajos son secundarios y no deben desplazar el desarrollo del mapa.

## Orden real de trabajo

1. **Expansión geográfica — primera entrega construida:** Costa Brava, con 60 instancias principales, 13 modelos LOD y cinco tramos de puente que conectan con la costa de Los Santos. Falta validación dentro del juego y ajuste de alturas/uniones.
2. **Prueba y pulido del mapa:** comprobar terreno, colisiones, agua, puente, accesos, LOD, radar, streaming y rendimiento en GTA SA 1.0 US.
3. **Mejora del terreno:** reemplazar piezas de terreno de prueba por geometría propia optimizada donde sea necesario; crear costa y relieve coherentes.
4. **Ampliación de la región:** terminar carreteras, puerto, asentamiento y puntos de interés.
5. **Segunda región:** solo después de validar Costa Brava.
6. **Modo libre:** conectar el menú F5 a sistemas reales; mantener F6 como herramienta administrativa opcional.
7. **Vehículos y actividades:** taxi, transporte, reparto, policía y carreras dentro del mapa ampliado.
8. **Economía y guardado:** pagos, progreso, propiedades y negocios persistentes.
9. **Protagonistas:** dos personajes originales adultos intercambiables.
10. **Relaciones opcionales:** citas y escenas sugeridas no explícitas.
11. **Integración final:** ZIP único, documentación, instalación/desinstalación y pruebas de regresión.

## Criterios de salida

- El juego inicia sin errores.
- La nueva tierra tiene geometría y colisión reales; no basta con poner objetos decorativos sobre el agua.
- Los accesos conectan con el mapa original y no dejan al jugador atrapado.
- IDE/IPL, DFF, TXD y COL coinciden y se cargan desde Mod Loader.
- Se revisan streaming, LOD, radar, agua y rendimiento en el equipo objetivo de 4 GB.
- No se declara terminada una zona hasta probarla dentro del juego.

## Estado honesto

Existe una primera versión estructural de Costa Brava en `src/maps/costa_brava.ipl`, además de un proyecto editable para SA Map Studio. Aún no se ha probado dentro del juego. La expansión completa continúa en desarrollo.
