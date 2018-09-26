# Pauta I1

**Pauta General:** Se espera que los alumnos tomen decisiones en las distintas preguntas de esta prueba. Si las preguntas no son respondidas (por ejemplo, sólo describe una tecnología pero no responde a la pregunta) se debe asignar cero puntos a esa pregunta.

## Parte 1 (10 pts): Preguntas

1. (2 pts) Según la taxonomı́a de Flynn ¿Cuál es la clasificación de los procesadores modernos? ¿Qué paralelismo explota?

```
La clasificación es MIMD (Multiple Instruction Multiple Data) y explota el paralelismo a través de instrucciones y datos.
```

2. (2 pts) Indica a que corresponde la clasificación SPMD y MPMD. Menciona un ejemplo para cada uno de ellos.

```
Tanto SPMD (Single Program Multiple Data) y MPMD (Multiple Program Multiple Data) son derivados de la clasificación MIMD (Multiple Instruction Multiple Data). Ejemplos: Los vistos en clases. SPMD: Revisar si los pulsos de GPS de un bus han pasado por alguna zona. MPMD: Multiples programas corriendo sobre una grilla que representa un terreno.
```

3. (2 pts) ¿Por qué es necesario comunicar procesos en un sistema distribuido? ¿Qué rol cumple MPI en este caso?

```
Cuando estamos trabajando en un computador, podemos realizar tareas simultáneas mediante threads (y procesos), sin embargo, cuando tenemos multiples nodos tenemos que comunicar procesos para aprovechar la infraestructura (un nodo no puede lanzar threads en otro nodo, porque los threads corren dentro de procesos). MPI (o interfaz de paso de mensajes), permite utilizar una interfaz común para poder comunicar procesos ya sea en el mismo o en distintos nodos.
```

4. (2 pts) ¿En qué tecnologı́a se basan los proveedores de sistemas de IaaS (como AWS, Google, etc)? ¿Qué caracterı́sticas tiene que permite prestar servicio a distintos clientes?

```
Se basan en la tecnología de virtualización. La característica más importante es que cada máquina virtual (o contenedor) es un entorno aislado, por lo que un cliente no puede ver la información de otra máquina. Esto hace que se puedan tener múltiples clientes en una misma infraestructura.
```

5. (2 pts) ¿Cuál es el problema del mecanismo de coherencia basado en directorio?

```
En algunos casos el directorio podría crecer y tener un gran tamaño.
```


## Parte 2 (50 pts): Ayudando a un amigo
Uno de tus amigos está abriendo una empresa de 5 personas (en Chile) y quiere centralizar el almacenamiento de los archivos. Un de las cosas que ha detectado es que los archivos que utilizan son pequeños y, en general, siempre es modificado por una persona (por el momento). Él te dice que ha investigado un poco el tema y está convencido que GFS (Google File System) es una buena idea en este caso, ya que le permitirı́a tener respaldada la información, a bajo costo, y le permitirı́a crecer. También le menciona que Lustre podrı́a ser otra alternativa (de bajo costo), ya que su empresa va a crecer y necesita rapidez en el acceso a la información.

Para las siguientes preguntas considera relevante las siguientes caracterı́sticas: costo, rapidez, concurrencia, consistencia, seguridad, escalabilidad y replicación.

1. (4 pts) ¿Estás de acuerdo con la idea planteada por tu amigo? Justifica tu respuesta para ambos sistemas de archivos distribuidos y en relación a lo planteado por él.

```
No deberías estar de acuerdo con tu amigo, la respuesta más simple es que tanto GFS como Lustre requiren de más de un servidor (metadata + datos), por lo que en el tema del costo es un punto en contra (Si bien se pueden virtualizar en una máquina, finalmente el costo se traslada a la configuración). Ambos son sistemas rápidos, que escalan, manejan la concurrencia y escalabilidad, replican la información y tienen manejo de consistencia. Sin embargo, el objetivo de ambos sistemas no es brindar un sistema de archivos distribuidos a una oficina pequeña, en este caso sería *overkill*
```

2. (4 pts) Para este caso en particular ¿Cuál serı́a tu recomendación? ¿Por qué?

```
La descripción apunta a un sistema tipo AFS, ya que son archivos pequeños y modificados por una persona, por lo que serían más lecturas que escrituras. Sin embargo, NFS también es una recomendación válida, ya que también funciona en este entorno. Uno de los problemas de la pregunta anterior era el costo, para estas recomendaciones, sólo se necesita un servidor o ocupar una de las estaciones de trabajo como servidor; esto hace que el costo baje.
```

3. (4 pts) Si consideraramos un futuro crecimiento de la empresa (a 50 personas) ¿Cambia tu recomendación? ¿Cuáles son las razones?

```
Si en la respuesta anterior indicaste AFS, sí deberías cambiar tu respuesta a NFS (u otro), ya que con más personas la concurrencia debería tender a aumentar (indicado durante la evalación). Esto hace que las condiciones hayan cambiado y no se cumplan para este sistema de archivos. Si ya habías indicado NFS, entonces había que argumentar que NFS sigue siendo válido en esta nueva configuración.
```

Despues de un tiempo, tu amigo te vuelve a contactar porque su empresa ha crecido bastante
y tiene que abrir operaciones en Europa. Actualmente su sistema de archivos distribuido, que tu configuraste, ha funcionado bastante bien pero tu amigo quiere que este sistema esté accesible desde Europa también.

4. (3 pts) ¿Es una buena utilizar una VPN en este caso? Basa tu respuesta en los aspectos de rapidez y seguridad ¿Qué tipo de configuración habrı́a que realizar?

```
Es la tecnología que se utiliza para realizar conexiones entre sucursales. La configuración sería realizar una conexión VPN site-to-site, tal como explicó Maximiliano en su presentación. Si bien, la conexión sería algo más lenta que internet (ya que a las conexiones VPN se le añade una capa de seguridad - encriptación) es completamente usable e incluso, algunos proveedores como Amazon, ofrecen realizar este tipo de configuraciones para unir datacenters con la nube de AWS.
```

5. (3 pts) ¿Y utilizar la red TOR? Realiza el mismo análisis anterior.

```
Si bien, desde el punto de vista de seguridad es buena idea, la velocidad que alcanzan estos enlaces es mucho menor a la que se alcanzan con VPN. La red TOR es una *overlay network* sobre internet (que también es una red sobre otra red). Para este caso, no es una mejor idea que VPN.
```

Ahora, ya eres parte de la empresa de tu amigo como asesor técnico y, junto con el equipo de ingenierı́a, han decido organizar la aplicación principal como microservicios

6. (5 pts) Analiza el cumplimiento del teorema CAP para la arquitectura que se muestra en la imagen. Puedes hacer un supuesto en caso de que lo necesites.

```
Si se analiza el sistema completo tenemos:

Consistencia (Consistency): Sí, cada sistema tiene su base de datos única, y no están interconectado los servicios entre sí por lo que debería haber consistencia.

Disponibilidad (Availability): No, dado que hay enlaces únicos y solo una instacia de cada servicio, al eliminar ese servicio ya no estaría disponible.

Toleracia a particiones (Partition Tolerance): Sí, la arquitectura de microservicios ya está "particionada", por lo que aunque uno de los servicios no esté disponible, los otros siguen funcionando.
``` 
**Pauta:** Considerar supuestos de ser realistas o particionar el sistema, mientras no cambie la arquitectura.

7. (2 pts) Si agregamos replicación de las bases de datos de cada microservicio ¿Cómo se ve afectado el teorema CAP?

```
Aquí empieza a ocurrir temas de consistencia, ya que al tener más bases de datos debo asegurarme que ambas tengan la misma información y, podría ocurrir, que en un proceso de sincronización se corte la comunicación y una de las bases de datos quede inconsistente.
```

Actualmente la empresa cuenta con dos servidores fı́sicos y el equipo de ingenierı́a se encuentra dividido entre virtualizar o instalar el sistema directamente en los servidores. Finalmente, el objetivo principal es poder tener disponibilidad del servicio.

8. (5 pts) ¿Es posible lograr disponibilidad con ambas opciones (antes descritas)? ¿Cómo?

```
Sí, basta con instalar los mismos servicios en ambas máquinas físicas o instalar un hipervisor (o contenedores) y generar instancias en cada máquina, si se decide virtualizar.
```

9. (5 pts) Han decidido que virtualizar es el mejor camino para la empresa. Ahora la discusión
se centra en virtualizar basado en contenedores o en hipervisor ¿Cuál es la mayor diferencia
entre ambos? ¿Cuál utilizarı́as si otro de los objetivos es mayor rendimiento? ¿Por qué?

```
La mayor diferencia entre ambos es que en el caso de la virtualización por contenedores no require instalar un 'Guest OS' y eso implica que es una capa menos por la que deben pasar las instrucciones.

Si se requiere velocidad, debería ser una virtualización basada en contenedores.
```

Uno de los grandes problemas que está teniendo la empresa tiene relación con la compra de insumos. Por lo que han determinado que es prioritario poder determinar cuándo se require adquirir productos para la venta. Para esto se decidió:

* Estudiar la demanda de los ultimos 12 meses para cada producto
* Obtener el promedio de la demanda
* Si en los ultimos 3 meses está por sobre el promedio se debe adquirir ese producto.
* Sólo se realiza la compra si más de un cuarto de los productos requiere que se adquiran.

Para esto se entregará un archivo de texto que en la primera columna tendrá el identificador del producto y, en las siguientes, la demanda para los 12 meses anteriores.

10. (10 pts) Escribe (en pseudocódigo) un programa usando MPI para poder realizar lo anterior.

```
funcion programa(args):
    inicializar_mpi
    world_size = mpi_obtener_cantidad_procesos
    process_id = mpi_obtener_id_proceso_actual

    si process_id = 0:
      productos[] = leer_archivo
      n_product_process = obtener_productos_por_proceso

      para cada proceso:
        mpi_enviar_info(enviar_productos_para_ese_proceso, proceso_index)

      buy_products[]
      para cada proceso:
        info_proceso = mpi_recibir_info(proceso)
        agregar informacion de info_proceso a buy_product

      sum = 0
      para cada elemento en buy_products:
        si buy_products[index] == true:
           sum += 1

      si buy_products.size / sum > 0.25:
        para cada elemento en buy_products:
            si buy_products[index] == true:
                comprar_producto
      
    si no:
      productos[] = mpi_recibir_info
      productos_analizados[]

      para cada producto en productos[]:
        promedio_demanda = obtener_promedio(producto)
        
        // mes3 ,2 y 1 son ubicaciones del arreglo anterior
        si mes3 > promedio demanda y
        mes2 > promedio demanda y
        mes1 > promedio demanda
          productos_analizados[index] = true
    
      mpi_enviar_info(productos_analizandos, 0)

    mpi_finalizar
```
**Pauta:** 
  * No es relevante si efectivamente hizo el programa en C o en pseudocódigo
  * Tampoco si comete pequeños errores sintácticos, lo importante es que estén los pasos solicitados de forma clara.
  * Considerar que existe más de una solución
  * Sí es relevante:
    * (2 pts) Inicializar el entorno MPI
    * (2 pts) Tener un proceso que coordine y otros que actúen como workers
    * El proceso que coordina debe:
      * (0.5 pts) Leer el archivo
      * (1 pt) Enviar información a los otros procesos
      * (1 pt) Recibir la información de los otros procesos 
      * (0.5 pts) Ver si se debe comprar
    * Los procesos workers
      * (1 pt) Recibir la información
      * (1 pt) Revisar los productos
      * (1 pt) Enviar información a proceso coordinador
  * Es relevante que exista un proceso que coordine ya que, de no hacer esto, todos los procesos leerían el archivo.

11. (5 pts) ¿Cómo cambia tu programa si la compra se realiza por producto, sólo con el estudio de la demanda?

```
Habría que eliminar la sección final del código en el coordinador:

    buy_products[]
    para cada proceso:
      info_proceso = mpi_recibir_info(proceso)
      agregar informacion de info_proceso a buy_products
    sum = 0
      para cada elemento en buy_products:
        si buy_products[index] == true:
           sum += 1

      si buy_products.size / sum > 0.25:
        para cada elemento en buy_products:
            si buy_products[index] == true:
                comprar_producto

Y en el caso de los otros procesos, se debe comprar el producto directamente

    si mes3 > promedio demanda y
    mes2 > promedio demanda y
    mes1 > promedio demanda
      comprar_producto

```

**Pauta:** Revisar con criterio para cada implementación. (2.5 pts por cada cambio - en coordinador y workers). Es válido haber explicado esto solo con texto.