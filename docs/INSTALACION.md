# Instalación — GTA San Andreas: Mundo Expandido

## Requisitos
- Grand Theft Auto: San Andreas clásico para PC, versión 1.0 US.
- CLEO instalado y funcionando.
- El juego debe iniciar sin errores antes de añadir este proyecto.

## Instalación del módulo actual
1. Cierra GTA San Andreas.
2. Abre la carpeta donde está instalado el juego.
3. Abre la carpeta `CLEO` (debe existir por la instalación de CLEO).
4. Copia `ME_Core_Menu.cs` dentro de esa carpeta.
5. Inicia el juego y carga una partida de un jugador.

## Controles incluidos en este módulo
- F5: mostrar/cerrar el aviso del panel principal.
- F6: mostrar/cerrar el panel de administrador.
- Con el panel de administrador abierto: 1 añade $10,000; 2 añade $100,000; 3 restaura salud y chaleco; 4 elimina el nivel de búsqueda; 5 añade $1,000,000.
- ESC: cerrar los paneles.

## Importante
Este paquete inicial contiene únicamente el módulo de interfaz y administración. No representa todavía el mundo expandido completo: trabajos, economía persistente, propiedades, protagonistas, mapa ampliado y relaciones siguen pendientes de desarrollo.

Haz una copia de seguridad de tu partida antes de probarlo. Si el juego se cierra o aparece un error, elimina `ME_Core_Menu.cs` de la carpeta `CLEO` y revisa `CLEO\cleo.log` o `.cleo.log`, según la versión de CLEO instalada.

El archivo de configuración `data/mundo_expandido.ini` es una plantilla de ajustes; este módulo aún no la lee. No cambies sus valores esperando que modifiquen el comportamiento del script.
