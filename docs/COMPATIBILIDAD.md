# Compatibilidad y criterios técnicos

## Entorno detectado
- GTA San Andreas: SA 1.0 US (confirmado por el registro CLEO compartido).
- CLEO está cargando CLEO+ y plugins de operaciones de archivos/INI.
- Mod Loader está instalado.
- SilentPatchSA.asi está presente.

El registro no permite determinar por sí solo si la instalación usa CLEO 4 o CLEO 5. No se debe asumir una versión exacta sin verificar el archivo binario o la pantalla de versión.

## Perfil de rendimiento
- Objetivo de memoria: equipo con 4 GB de RAM.
- Evitar ENB, reshade pesado, texturas 2K/4K y reemplazos masivos.
- Preferir texturas pequeñas, modelos de bajo/medio poligonaje y streaming por zonas.
- Limitar procesos permanentes y bucles de alta frecuencia.
- Guardar datos solo cuando cambien, no cada frame.

## Reglas de calidad
1. Cada sistema debe poder desactivarse por configuración.
2. No sobrescribir archivos originales del juego si Mod Loader puede montar el recurso.
3. Validar rutas, archivos INI y datos guardados antes de usarlos.
4. Probar carga, guardado, cambio de zona y reinicio de partida.
5. No publicar una compilación como estable hasta probarla en GTA SA 1.0 US.
