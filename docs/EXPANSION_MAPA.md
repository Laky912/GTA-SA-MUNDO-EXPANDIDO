# Expansión geográfica — Costa Brava

## Primera región construida

Se preparó un primer paquete de mapa para GTA San Andreas PC 1.0 US: una región insular costera situada aproximadamente al sur de Los Santos, centrada en X=225, Y=-2600.

Incluye **53 instancias** de modelos del juego base: cuatro plataformas arenosas conectadas, una loma verde con borde de tierra, una terraza costera, piezas de costa y playa, carretera, cabañas, embarcadero, palmeras, mobiliario y rocas de orilla. El terreno y la colisión los aportan los DFF/COL ya presentes en la instalación original; no se redistribuyen esos archivos.

## Archivos fuente
- `src/maps/costa_brava.ipl`: IPL textual que añade las instancias.
- `src/maps/Costa-Brava.sa-map-studio.json`: proyecto editable para SA Map Studio en modo Singleplayer.
- `docs/INSTALACION_MAPA.md`: instalación y desinstalación.

## Integración
El paquete coloca el IPL bajo `objects/` y usa la directiva `IPL DATA\\MAPS\\SAMSP_MUNDO_EXPANDIDO_CBRV.IPL` en su README para que Mod Loader lo incorpore a `gta.dat`. No se reemplaza `gta.dat` ni se editan los mapas originales.

## Estado honesto
El IPL se validó estructuralmente: 53 registros, 11 campos por instancia y cuaterniones normalizados. Los IDs y nombres se contrastaron con el catálogo de modelos de GTA SA. **No se ha ejecutado el juego en este entorno**; por tanto, la colocación, colisiones, uniones visuales, acceso en barco, LOD y FPS aún requieren prueba runtime y ajustes.
