# Pauta Ex

## Pregunta 1 (25 pts): Preguntas teóricas

Responde las siguientes preguntas:

1. (2 pts) Según la taxonomía de Flynn ¿Cuál es la clasificación de las GPUs?

**R:** SIMD

2. (2 pts) En la presentación sobre Titan, Hernán nos indicó que podía servir para recomendar ciertas cosas a un usuario ¿Cómo era posible esto?

**R:** Dado que era una base de datos en grafos, se podía revisar a que usuarios "les gustaba" lo mismo y qué otras cosas les gustaba.

3. (2 pts) Guillermo nos presentó acerca de funciones lambda (en AWS) ¿Cómo se relacionan estas con el teorema CAP? Realiza el análisis suponiendo que una función tiene acceso a una base de datos replicada.

**R:** AWS entrega disponibilidad de la función y toleracia a particiones. Si la función tiene acceso a una base de datos replicada podría no entregar consistencia.

4. (2 pts) Jaime nos habló sobre Eventual Consistency ¿Qué implica? ¿Cómo afecta al teorema CAP? Indica una ejemplo de dónde se aplica.

**R:** Se relaja la c en el teorema CAP (de hecho Jaime lo escribió con minúscula en sus diapositivas - cAP). Ejemplos: Redes sociales.

5. (2 pts) Alejandro e Iván nos presentaron sobre OpenMP ¿Cuál es la diferencia con MPI (además de la I)?

**R:** Está enfocado a realizar multi procesamiento en una máquina, en contraste a MPI que intenta ser una interfaz para conectar varios nodos.

6. (3 pts) Nicolás y Sebastián nos presentaron sobre Kademlia ¿Cuál es la diferencia del routing que implementa esa solución con respecto al revisado en Pastry?

**R:** Kademlia ocupa distancia XOR para calcular qué nodo está más cerca. En el caso de Patry, teníamos el *leaf set* y la routing table. En este caso se busca aquella que comparte mayor prefijo con el recurso buscado.


Responde con respecto a la presentación del profesor Christopher Cooper de la USM:


7. (3 pts) ¿A qué se debe la diferencia de precios entre las distintas GPUs?

**R:** Las GPUs más caras son aquellas que tienen mayor precisión.

8. (3 pts) ¿Por qué los sistemas basados en GPUs son más rápidos que la CPU para ciertas tareas?

**R:** Debido a la gran cantidad de cores que poseen en comparación a la CPU, lo que lleva a que puede hacer una operación en varios conjuntos de datos de forma simultánea

9. (3 pts) ¿Cuál era la recomendación (en base a la memoria ocupada) para que los algoritmos corrieran más rápido?

**R:** Aumentar el acceso a memoria compartida y disminuir el acceso a memoria global

10. (3 pts) ¿Cuál era el tipo de problema que tenía mejor rendimiento con GPUs?

**R:** El problema de N cuerpos (N body)



## Pregunta 2 (15 pts): Transacciones

Se tienen las siguientes transacciones:

| T1 | T2 |
| :- | :- |
|a.deposit(150) | aTotal = a.getBalance() |
|a.withdraw(100) | b.deposit(aTotal) |
|bTotal = b.getTotal() | a.setBalance(0) |
|    | a.deposit(200) |


1. (5 pts) Escriba un ejemplo de ejecución que tenga una (o varias) lectura(s) inconsistente(s)

**R:** Basta con que se ejecute:

```
[T2] aTotal = a.getBalance()
[T1] a.deposit(150)
[T2] b.deposit(aTotal)
```

Ahí hay una lectura inconsistente.

2. (5 pts) Escribe una serialización correcta para ambas transacciones

**R:**
```
[T1] a.deposit(150)
[T1] a.withdraw(100)
[T2] aTotal = a.getBalance()
[T2] b.deposit(aTotal)
[T2] a.setBalance(0)
[T1] bTotal = b.getTotal()
[T1] a.deposit(200)
```


3. (5 pts) Si estas transacciones se dan en un ambiente distribuido ¿Qué protocolo de commit utilizaría y por qué?

**R:** Si estamos en un ambiente distribuido, debería ser un *two-phase commit*, para asegurar que todos los nodos puedan llevar a cabo la operación y no dejar algunos de ellos en un estado inconsistente.


## Pregunta 3 (20 pts): Avísenme si se publica una nota

Actualmente, cuando el profesor publica una nota en SIDING, los alumnos no tienen cómo enterarse; a menos que se envíe un aviso a todos los alumnos. Sin embargo, se está estudiando la posibilidad que los alumnos que deseen recibir estas alertas puedan hacerlo. También se debe poder dejarlas de recibir.

1. (5 pts) ¿Qué modelo de comunicación indirecta usarías en este caso? ¿Por qué?

**R:** Aquí podrías ocupar el modelo de *publish/subscribe*, donde los alumnos que quieren las alertas pueden suscribirse o dejar de recibirlas a gusto. Si bien, en este caso también aplica un modelo de comunicación en grupos, el problema de ese modelo es que todos pueden publicar y no es esa la idea.

2. (10 pts) Indica cuales serían los pasos para implementar esta solución. Tu respuesta debe estar orientada a indicar lo que necesita el modelo de comunicación indirecta aplicado a este problema, incluyendo pre requisitos (si es necesario) y ambos casos de uso (recibir y dejar de recibir alertas).

**R:** 

Para este caso:

* Debería existir un tema (*topic*) que defina las notas para un cierto curso (debería ejecutarse un *advertise* con ese tema).

* El que publica debería ser SIDING, una vez que el profesor actualiza las notas (realiza las operaciones de *publish*). 

* Los alumnos se suscriben(*subscribe*)/cancelan(*unsubscribe*) recibir las alertas (para ese tema).

* Cuando una nota es publicada, se debe notificar (*notify*) a todos aquellos que están suscritos.

-------

3. (5 pts) Si ahora quisiéramos enviar alertas por las publicaciones en el foro. Indica qué cambios debieses hacer para que, los alumnos que quieran, puedan recibir estas alertas.

**R:** Deberíamos *advertise* otro tema que sería para eventos del foro. Los alumnos se suscriben(*subscribe*)/cancelan(*unsubscribe*) a ese tema y todo seguiría funcionando igual.