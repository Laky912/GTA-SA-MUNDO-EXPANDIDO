# Costa Brava - primera región

La primera zona del mapa ya tiene un IPL con **53 instancias** de modelos originales de GTA San Andreas: cuatro plataformas de terreno conectadas, una loma verde con borde de tierra, una terraza costera, tramos de costa, carretera, cabañas, embarcadero, palmeras, mobiliario y rocas de orilla.

La ubicación prevista es el mar al sur de Los Santos, centrada aproximadamente en X=225, Y=-2600.

## Instalación
1. Cierra el juego.
2. Extrae el ZIP completo en la carpeta principal de GTA San Andreas.
3. Mod Loader cargará `modloader/GTA-SA-Mundo-Expandido-Costa-Brava`.
4. Para el menú opcional, copia `CLEO/ME_Core_Menu.cs` a la carpeta CLEO.

## Archivos
- `src/maps/costa_brava.ipl`: IPL textual.
- `src/maps/Costa-Brava.sa-map-studio.json`: proyecto editable de SA Map Studio.
- `docs/INSTALACION_MAPA.md`: guía del mapa.

## Validación
El IPL tiene 53 registros, 11 campos por instancia y cuaterniones normalizados. Los modelos utilizados existen en el juego base y conservan sus colisiones originales. No se distribuyen DFF/TXD/COL del juego.

No se ha ejecutado GTA SA en este entorno. La altura y unión de piezas, colisiones, agua, streaming, LOD, acceso por barco y rendimiento necesitan validación dentro del juego. Esta es la primera región, no la expansión completa.
