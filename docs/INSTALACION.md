# Instalación - GTA San Andreas: Mundo Expandido

## Requisitos
- GTA San Andreas clásico para PC, versión **1.0 US**.
- Mod Loader para cargar Costa Brava.
- CLEO instalado para el menú opcional.

## Instalar el mapa
1. Haz una copia de seguridad de tu partida.
2. Extrae el ZIP completo directamente en la carpeta principal de GTA San Andreas, donde está `gta_sa.exe`.
3. Mod Loader cargará el IPL desde `modloader/GTA-SA-Mundo-Expandido-Costa-Brava`.
4. La isla se encuentra al sur de Los Santos, centrada aproximadamente en X=225, Y=-2600 y conectada por un puente.

## Instalar el menú opcional
Copia `CLEO/ME_Core_Menu.cs` a la carpeta `CLEO` del juego.

## Controles del módulo CLEO
- **F5:** menú principal (salud, chaleco, quitar estrellas, +$5,000).
- **F6:** panel de administrador (+$10,000, +$100,000, salud/chaleco, quitar estrellas, +$1,000,000).
- **F7:** prototipo de trabajo de reparto.
- **ESC:** cerrar paneles.

## Desinstalar
- Mapa: elimina `modloader/GTA-SA-Mundo-Expandido-Costa-Brava`.
- Menú opcional: elimina `CLEO/ME_Core_Menu.cs`.

## Estado real
Costa Brava contiene 60 instancias principales, cinco tramos de puente y 13 modelos LOD enlazados (73 registros IPL). El archivo pasa validación estructural, pero no se ha ejecutado GTA SA en este entorno. La colocación, colisiones, uniones, agua, alturas del puente y rendimiento aún necesitan prueba dentro del juego. El menú CLEO compila, pero tampoco se ha validado runtime aquí. Este paquete es una primera entrega, no el mod completo.
