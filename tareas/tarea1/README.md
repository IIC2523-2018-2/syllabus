# Tarea 1

Fecha de entrega: miércoles 26 de septiembre, 23:59 hrs.

Crea una carpeta llamada "tarea1" en tu repositorio y dentro de ella todos los archivos de tu solución. Incluye, además, un archivo que explique al ayudante cómo debe corregir tu tarea.

## Contexto

Tu trabajas en una empresa que analiza distintas trazas de ADN y descubres que, para revisar las distintas muestras, es un proceso que se hace de forma manual: Una persona revisa un archivo de texto buscando anomalías en el ADN, lo cual toma mucho tiempo.

Con tus nuevos conocimientos de sistemas distribuidos, sabes que puedes realizar esta tarea de forma automatizada y más rápida que en la actualidad.

## Archivo de texto

El archivo revisado tiene la siguiente estructura (ejemplo):

```
ATGCCGTA TACGGCTA CGTAATCG GCTAATGC GCCGCGGC TAATTACG GCCGGCCG TAGCCGTA
TACGGCTA ATGCCGTA CGTAATCG TAATTACG GCCGCGGC TAATTACG GCCGGCCG TAGCCGTA
ATGCCGTA TACGGCTA ATGCCGTA GCTAATGC GCCGCGGC TAATTACG GCCGGCCG GCCGGCCG
ATGCCGTA GCCGGCCG CGTAATCG GCTAATGC GCCGCGGC TAATTACG GCCGGCCG TAGCCGTA
ATGCCGTA TACGGCTA CGTAATCG GCTAATGC ATGCCGTA GCCGGCCG TAGCCGTA GCTAATGC
ATGCCGTA TACGGCTA TAATTACG GCTAATGC GCCGCGGC TAATTACG GCCGGCCG TAGCCGTA
ATGCCGTA TACGGCTA CGTAATCG GCCGGCCG GCCGCGGC ATGCCGTA TAATTACG TAGCCGTA
ATGCCGTA GCCGGCCG CGTAATCG GCTAATGC GCCGCGGC TAATTACG GCCGGCCG TAGCCGTA
[...]
```

Cada archivo tiene 8 columnas y cada una de ellas tiene 8 letras. El archivo puede tener un número indeterminado de líneas.

## Proceso de revisión

Para verificar que el archivo esté correcto, debe cumplir con lo siguiente (para cada columna):

* Sólo pueden aparecer las letras A, T, G y C. Estas representan las cuatro [bases nucleares](https://en.wikipedia.org/wiki/Nucleobase) del ADN: Adenina, Timina, Guanina y Citocina.

* Siempre deben aparecer en pares AT y GC, pueden estar como TA y CG. No pueden mezclarse entre estos pares (ej. GT).

## Detalles de la tarea

Deberás desarrollar un programa en `Python` que permita verificar los errores que existan en los distintos archivos. Para esto deberás:

1. Implementar una versión que realice esta tarea de forma secuencial
2. Implementar una versión que utilice multiprocesamiento (a nivel de procesos y *threads*)
3. Responder las preguntas que se detallan en la siguiente sección (Archivo markdown o PDF).

Para las implementaciones debes considerar:

* Debes permitir un parámetro con la ruta del archivo, debes indicar cuando no puede abrir un archivo.
* Esperamos que sea un programa bien implementado, con un código que sea fácil de seguir y que idealmente esté comentado.
* Los errores deben mostrarse de forma incremental, para facilitar la revisión manual posterior. Esto quiere decir que los errores deben mostrarse por línea y columna (en ese orden). Si el archivo no presenta errores, debe indicarlo también. Si presenta, los errores deben ser descriptivos.
* Tu programa debe poder reaccionar ante distintas infraestructuras (problema de heterogeneidad). Recuerde que no puede lanzar una cantidad infinita de procesos o *threads* en un sistema.
* Puedes suponer que el formato de 8 columnas y 8 letras cada una se cumple siempre.

## Preguntas a contestar

1. Con los archivos de prueba que están disponible para la tarea 1 ¿Cuál es el *speedup* que se logra con una versión con operaciones distribuidas para su implementación? Indique una pequeña descripción del computador en que realizó la prueba.
2. ¿Existe un punto en que, al lanzar una cierta cantidad de *threads*/procesos, el análisis se vuelve ineficiente (más lento que el sequencial)? ¿Por qué?
3. Si el archivo tiene pocas líneas ¿Existe un punto en que la versión secuencial es mejor que la versión que calcula en paralelo? ¿Por qué?
4. Si se elimina la restricción de mostrar los errores en orden, y usando el archivo de prueba, ¿Cuál es el *speedup* que se obtiene esta vez? ¿Tiene sentido comparando con el resultado obtenido en la primera pregunta?

## Rápido y furioso!

Para que esto sea más entretenido, y demostrar que son unos dignos miembros del equipo de [Dominic Toreto](https://en.wikipedia.org/wiki/Dominic_Toretto) de la computación (quizás no manejen autos a gran velocidad pero pueden escribir el algoritmo más rápido), es que probaremos todos los algoritmos que implementen en una arquitectura misteriosa. Los tres primeros (en rapidez) tendrán premio:

* **Primer lugar:** + 0.5 pts en su tarea
* **Segundo lugar:** + 0.3 pts en su tarea
* **Tercer lugar:** + 0.1 pts en su tarea

Si tu siguiente pregunta es: ¿Puedo terminar con una nota 7.5 en esta tarea? La respuesta es sí.

**Solo podrán acceder** aquellos que hayan completado ambas versiones del código (y esté bien implementado).

## Pauta de corrección

* (1 pts) Preguntas a contestar (0.25 pts cada una)
* (1.5 pts) Versión secuencial
* (3.5 pts) Versión distribuida

**Descuentos**

* Código poco legible (-0.5 pts)
* Bajo ciertas condiciones (ej. archivo con muchas líneas) el equipo de pruebas queda inutilizable y debe ser reiniciado (-0.5 pts)
