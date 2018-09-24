# Google File System (GFS)

## Caracterisiticas del sistema

- Sistema de archivos distribuido
- Confiable
- Eficiente
- Maneja Grandes Flujos de datos
- Enfocado en busquedas
- Recuperación de errores
- Hardware de bajo costo
- Clusters gigantes de procesamiento de datos

## Versiones

### Antecesor

- Big Files

### Actual

- Colossus


## Arquitectura

### Dos tipos de nodos:
- Chunk Serves
- Nodos Maestro

#### Chunk server

- Almacenamiento
- Reportan estado a nodo maestro
- Bloques con capacidad de 64 MB
- En general reciben solo lectura y adición de información
- Al menos 3 replicas por cada bloque de datos

#### Nodo Maestro

- Rol de administrador
- Se dedica a procesar
- Guardan metadatos de los chunk
- Mantien tabla de direccionamiento
- Administran permisos sobre los chunk
- Registro de cambios criticos
- Mantienen copia de seguridad de bloques no replicados

## Funcionamiento

- Aplicaciones solicitan acceso a datos
- Nodos maestros responden dirección de los datos (Siempre que no este usado en escritura)
- Además se concede permiso necesario para la acción solicitada
- Cada permiso tiene tiempo finito de uso
- Por lo anterior un proceso puede terminar (dejar de usar) o agotar su tiempo de permiso antes de terminar y debe re solicitar el permiso
- Mientras dure el permiso se realiza la acción aprobada
- Luego el chunk server modificado propaga señal de actualización a todas las replicas
- Se espera la respuesta de todas las replicas
- Cuando se confirma se notifica el cambio como definitivo (en todas las replicas)
