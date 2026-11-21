# Expansión geográfica — Costa Brava

## Primera región construida

Se preparó un primer paquete de mapa para GTA San Andreas PC 1.0 US: una región insular costera situada aproximadamente al sur de Los Santos, centrada en X=225, Y=-2600.

El IPL contiene **60 instancias principales y 13 modelos LOD enlazados**: cuatro plataformas arenosas conectadas, una loma verde, una terraza costera, seis tramos de costa, carretera interior, cinco tramos de puente hacia la costa de Los Santos, cabañas, embarcadero, palmeras, mobiliario y rocas de orilla.

El terreno y las colisiones los aportan los DFF/COL ya presentes en la instalación original; no se redistribuyen esos archivos.

## Archivos fuente
- `src/maps/costa_brava.ipl`: IPL textual con LOD enlazados.
- `src/maps/Costa-Brava.sa-map-studio.json`: proyecto editable para SA Map Studio en modo Singleplayer (60 instancias principales).
- `docs/INSTALACION_MAPA.md`: instalación y desinstalación.

## Integración
El paquete coloca el IPL bajo `data/maps/` y usa la directiva `IPL DATA\\MAPS\\SAMSP_MUNDO_EXPANDIDO_CBRV.IPL` en su README para que Mod Loader lo incorpore a `gta.dat`. No se reemplaza `gta.dat` ni se editan los mapas originales.

## Estado honesto
El IPL se validó estructuralmente: 73 registros, 11 campos por instancia, cuaterniones normalizados y enlaces LOD dentro del rango del propio IPL. Los IDs y nombres se contrastaron con el catálogo de modelos de GTA SA. **No se ha ejecutado el juego en este entorno**; por tanto, la colocación, colisiones, uniones visuales, alturas del puente, agua, streaming y FPS aún requieren prueba runtime y ajustes.
