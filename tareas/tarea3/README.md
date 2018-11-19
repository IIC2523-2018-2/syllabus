# Tarea 3

Fecha de entrega: viernes 30 de noviembre, 23:59 hrs.

Crea una carpeta llamada "tarea3" en tu repositorio y dentro de ella todos los archivos de tu solución. Incluye, además, un archivo que explique al ayudante cómo debe corregir tu tarea.

## Problema

Tiens que implementar simulaciones para el proceso de sincronización de relojes.

## Detalles de la tarea

Deberás desarrollar un programa utilizando `Python` que permita que dos sistemas (simulados) puedan sincronizar sus relojes, para esto:

1. Implementa una versión del algoritmo de Cristian.
2. Implementa un algoritmo basado en NTP, en donde modifiques la parte de asignación del reloj.

Para tu programa debes considerar:

* Los relojes iniciales deben tener al menos 1 día de separación.
* Para cada uno de los algoritmos debes hacer 15 simulaciones que involucren 10 ejecuciones del algoritmo. Debe haber un tiempo (1 o 2 minutos) entre las ejecuciones.
* Deberás simular retrasos en la red, para esto debes incluir una latencia entre 500 y 3200 milisegundos entre que se envía y llega el mensaje.

Para el caso particular de su versión de reloj basada en NTP:

* En clases vimos un ejemplo de cómo era el algoritmo NTP y que existía una parte matemática para determinar el valor del reloj. Puedes modificar esa parte.
* Tu algoritmo debe considerar información histórica.
* Debes incluir un pequeño documento que indique el proceso de tu algoritmo y sus consideraciones.

En cuanto a la implementación:

* La salida del programa debe ser de esta forma (ejemplo):

```
***********************************
* Algoritmo de Cristian
***********************************

Reloj inicial:
Reloj sistema 1: 12345
Reloj sistema 2: 75434

Simulación 1:
Reloj sistema 1: 3456789
Reloj sistema 2: 5678906
Diferencia: 4556

Simulación 2:
Reloj sistema 1: 3454789
Reloj sistema 2: 5674906
Diferencia: 6556

[...]

***********************************
* Mi algoritmo NTP
***********************************

[...]
```

## Pauta de corrección

* (2 pts) Implementación de algortimo de Cristian
* (4 pts) Implementación de su algoritmo basado en NTP
  * Si en una simulación la diferencia de relojes finales es mayor a 3 segundos, puede obtener un máximo de 2 puntos
  * Si no incluye el documento explicando el algoritmo (-1 pts)

**Descuentos**

* Código poco legible (-1 pts)
* No respetar output de salida (-1 pts)
* Bajo ciertas condiciones el equipo de pruebas queda inutilizable y debe ser reiniciado (-1 pts)
