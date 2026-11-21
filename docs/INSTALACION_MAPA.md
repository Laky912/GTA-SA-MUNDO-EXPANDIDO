# Instalación de Costa Brava

1. Cierra GTA San Andreas.
2. Extrae el ZIP completo directamente en la carpeta principal de GTA San Andreas, donde está `gta_sa.exe`.
3. Mod Loader cargará el IPL desde `modloader/GTA-SA-Mundo-Expandido-Costa-Brava/data/maps/` usando la línea `IPL DATA\MAPS\SAMSP_MUNDO_EXPANDIDO_CBRV.IPL` del `README.txt` incluido.
4. Para el selector del menú inicial, instala `MundoExpandido.asi` en la carpeta principal del juego y `CLEO/CLEO_TEXT/ME_MODOS.fxt` en esa ruta. Para el panel de funciones opcional, copia `CLEO/ME_Core_Menu.cs` a la carpeta CLEO.

**Desinstalación:** elimina `modloader/GTA-SA-Mundo-Expandido-Costa-Brava`. Si instalaste el menú opcional, elimina también `MundoExpandido.asi`, `CLEO/CLEO_TEXT/ME_MODOS.fxt` y `CLEO/ME_Core_Menu.cs`.

## Qué incluye el mapa

- 60 instancias principales y 13 modelos LOD enlazados.
- Cinco tramos de puente con colisión original conectan Costa Brava con la costa de Los Santos.
- Terreno arenoso, loma verde, terraza de playa, costa, carretera, cabañas y embarcadero.
- El proyecto editable de SA Map Studio contiene las 60 instancias principales.

## Requisitos
- GTA San Andreas clásico PC 1.0 US.
- Mod Loader para la expansión geográfica.
- ASI Loader x86 para el selector del frontend.
- CLEO 4 para el panel opcional.

## Validación y límites
El IPL contiene 73 registros y pasó validación estructural: 11 campos por instancia, cuaterniones normalizados y enlaces LOD dentro del archivo. No se ha ejecutado GTA SA en este entorno; todavía hay que comprobar alturas, uniones, colisiones, agua, puente, streaming y rendimiento dentro del juego. Haz copia de seguridad de tus partidas.
