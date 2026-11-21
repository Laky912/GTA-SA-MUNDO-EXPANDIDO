# Instalación - GTA San Andreas: Mundo Expandido

## Requisitos
- Grand Theft Auto: San Andreas clásico para PC, versión **1.0 US**.
- CLEO instalado y funcionando.
- Mod Loader es recomendado para futuras fases, pero este módulo se instala directamente en CLEO.

## Instalar
1. Haz una copia de seguridad de tu partida guardada.
2. Extrae el ZIP.
3. Copia `CLEO/ME_Core_Menu.cs` a la carpeta `CLEO` de tu instalación de GTA San Andreas.
4. Inicia el juego y carga una partida.

## Controles
- **F5:** menú principal.
  - 1: recuperar salud.
  - 2: restaurar chaleco.
  - 3: eliminar estrellas.
  - 4: recibir $5,000.
- **F6:** panel de administrador.
  - 1: +$10,000.
  - 2: +$100,000.
  - 3: salud y chaleco.
  - 4: quitar estrellas.
  - 5: +$1,000,000.
- **ESC:** cerrar los paneles.

## Alcance real de este paquete
Este es un **módulo inicial**, no el Mundo Expandido completo. Incluye el menú de acciones rápidas y el panel de administrador. Todavía no incluye el mapa ampliado, protagonistas intercambiables, trabajos, economía persistente, propiedades, negocios, vehículos nuevos ni sistema de relaciones.

La compilación CLEO se verifica automáticamente en GitHub Actions. Eso confirma que el script se genera, pero no sustituye una prueba dentro del juego. Si el juego se cierra o las teclas no responden, retira temporalmente `ME_Core_Menu.cs` de la carpeta CLEO y comparte el archivo `cleo.log`.
