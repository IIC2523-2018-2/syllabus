# Ejemplo Routing Pastry

A continuación se presentan ejemplos de routing.

## Ejemplo 1

En este caso abordaremos el caso más simple, que tiene relación con que el nodo buscado está dentro del *leaf set*.

Supongamos que estamos en el nodo A4D2 y queremo buscar el nodo A4D6.

Sea L el *leaf set* del nodo A4D2 y está formado por:

* A4CC
* A4CD
* A4CE
* A4CF
* A4D1
* A4D2
* A4D3
* A4D5
* A4D6

El procedimiento es como sigue:

1. ¿Está el nodo buscado (A4D6) en el *leaf set*?

*R:* Sí, por lo tanto da el salto hacia ese nodo.


## Ejemplo 2

En este caso abordaremos la siguiente situación: El nodo no esta en el *leaf set*, pero sí está dentro de la vecindad.

Supongamos que estamos en el nodo C511 y queremo buscar el nodo C555.

Sea L el *leaf set* del nodo C511 y está formado por:

* C501
* C502
* C511
* C536
* C545 
* C553
* C558
* C560

El procedimiento es como sigue:

1. ¿Está el nodo buscado (C555) en el *leaf set*?

*R:* No, no está en el *leaf set*

2. ¿Está el nodo buscado (C555) dentro de la vecindad?

*R:* Sí, dado que el menor GUID en el *leaf set* es C501 y el mayor C560, sí está dentro de la vecindad. ¿A dónde debe saltar? Al nodo más cercano a C555, que en este caso es C553.

## Ejemplo 3

Revisaremos el caso en que no está dentro de la vecindad.

Supongamos que estamos en el nodo BA31 y queremo buscar el nodo D5A4.

Sea L el *leaf set* del nodo BA31 y está formado por:

* BA10
* BA12
* BA25
* BA29 
* BA31
* BA35
* BA38
* BA41

El procedimiento es como sigue:

1. ¿Está el nodo buscado (D5A4) en el *leaf set*?

*R:* No, no está en el *leaf set*

2. ¿Está el nodo buscado (D5A4) dentro de la vecindad?

*R:* No, dado que el nodo de mayor GUID es BA41.

3. La única opción es que esté en otra porción de la circunferencia de los GUID.

Como no está en la vecindad debo ir a buscarlo a la tabla de routing que se forma al unirse a la red. En este caso saltará al nodo que encuentre que esté más cerca en la tabla y repetirá los mismos pasos.
