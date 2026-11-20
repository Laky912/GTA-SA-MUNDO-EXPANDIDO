# Plan de desarrollo

El usuario quiere una entrega integrada, no una sucesión de paquetes que tenga que instalar manualmente. El trabajo interno puede avanzar por etapas, pero la distribución final será un ZIP único.

## Bloques de implementación
1. Base técnica: estructura Mod Loader/CLEO, configuración, registro de errores y detección de dependencias.
2. Menú de Modo Libre: interfaz en español, apertura con F5, navegación y cierre seguros.
3. Economía y guardado: dinero adicional, estadísticas y persistencia sin corromper partidas.
4. Actividades: taxi, reparto, transporte, policía y carreras.
5. Propiedades y negocios.
6. Protagonistas y cambio de personaje.
7. Relaciones opcionales.
8. Expansión del mapa y vehículos originales/licenciados.
9. Integración, pruebas de regresión y empaquetado ZIP.

## Criterios de salida
- El juego inicia sin errores.
- El menú se abre/cierra de forma consistente.
- No se bloquean controles al cerrar menús o actividades.
- Los datos sobreviven a guardar/cargar.
- Los sistemas no generan entidades duplicadas ni scripts huérfanos.
- La instalación y desinstalación están documentadas.
- El ZIP final contiene solo recursos necesarios y una guía clara.

## Estado
Los bloques anteriores son planificación, no funcionalidades ya implementadas. Cada función se marcará como terminada solo después de contar con código, compilación y pruebas.
