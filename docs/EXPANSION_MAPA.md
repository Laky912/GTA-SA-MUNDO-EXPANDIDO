# Expansión geográfica — Mundo Expandido

## Objetivo principal

Añadir territorio explorable real a GTA San Andreas clásico PC 1.0 US, conservando Los Santos, San Fierro, Las Venturas y el campo original. La expansión no consistirá en agrandar el radar ni en colocar decoraciones sobre el océano: debe incluir terreno visible, colisión, costa, carreteras y accesos funcionales.

## Primera región: Costa Brava

Concepto de trabajo: una región insular costera de tamaño moderado, situada en una zona marítima libre del mapa original y conectada al continente mediante un puente o una ruta de ferry. El nombre es provisional.

### Contenido previsto

- Costa rocosa, playas y elevaciones suaves.
- Carretera principal que recorra la isla y enlace sus puntos de interés.
- Pequeño núcleo urbano con gasolinera, talleres, tiendas y viviendas.
- Zona portuaria para carga y ferry.
- Miradores, caminos secundarios y áreas naturales.
- Puntos de aparición y rutas de acceso para el modo libre.

La región se construirá con recursos originales o con recursos cuya licencia permita su distribución. No se extraerán mapas ni modelos de GTA VI.

## Restricciones técnicas

- Juego objetivo: GTA San Andreas PC 1.0 US.
- Instalación: Mod Loader; CLEO solo para sistemas interactivos que lo necesiten.
- PC objetivo: 4 GB de RAM. Priorizar modelos ligeros, texturas pequeñas, LOD y carga por sectores.
- No sobrescribir archivos originales cuando exista una alternativa mediante Mod Loader.
- No modificar el mapa base de forma destructiva.

## Archivos que compondrán la región

- IDE: definición de los modelos y sus distancias de dibujo.
- IPL: colocación de objetos y sectores del mapa.
- DFF: geometría 3D de terreno, edificios y elementos propios.
- COL: colisión correspondiente a cada modelo.
- TXD: texturas optimizadas.
- LOD: modelos simplificados para distancia, cuando corresponda.
- Configuración Mod Loader y guía de instalación.

Un IPL con objetos del juego base no sustituye el terreno nuevo. La isla necesita geometría y colisión propias para ser realmente transitable.

## Flujo de producción

1. Abrir la cartografía original de GTA SA en un editor compatible y localizar una zona marítima libre.
2. Definir la huella de la isla y comprobar límites del mundo, profundidad del agua y distancia a la costa.
3. Construir el terreno y generar su colisión.
4. Crear carreteras, edificios y puntos de interés usando primero recursos ligeros.
5. Exportar IDE/IPL y los modelos asociados.
6. Integrar el paquete en Mod Loader.
7. Probar conducción, caminata, colisiones, agua, streaming, LOD y radar en SA 1.0 US.
8. Optimizar antes de comenzar la segunda región.

## Herramienta de edición

Se evaluará SA Map Studio en modo Singleplayer, que documenta exportación de proyectos para Mod Loader, edición de IPL, modelos propios DFF/TXD/COL y trabajo sobre la cartografía completa del juego. La herramienta es externa; no se incluirá como dependencia obligatoria del jugador final.

Referencia: https://github.com/Walter-Correa/SA-Map-Studio

## Estado actual

**Diseño técnico iniciado; región aún no construida.** Este documento no representa una isla instalada ni un mapa jugable. No se publicará como expansión terminada hasta que existan los modelos, colisiones y datos IDE/IPL y se haya validado dentro del juego.
