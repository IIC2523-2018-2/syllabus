# Tarea 2

Fecha de entrega: viernes 3 de noviembre, 23:59 hrs.

Crea una carpeta llamada "tarea2" en tu repositorio y dentro de ella todos los archivos de tu solución. Incluye, además, un archivo que explique al ayudante cómo debe corregir tu tarea.

**NOTA:** Esta tarea puede tomar tiempo en completarla.

## Problema

Deberá implementar el problema presentado en la [Tarea 1](../tarea1/README.md) pero, ahora utilizando `MPI` (*Message Passing Interface*).

## Detalles de la tarea

Deberás desarrollar un programa utilizando `MPI` que permita verificar los errores que existan en los distintos archivos. Para esto tienes que:

1. Implementar la versión en lenguaje `C (MPI)`.
2. Responder las preguntas que se detallan en la siguiente sección (Archivo markdown o PDF).

Para tu programa debes considerar:

* Permitir un parámetro con la ruta del archivo, debes indicar cuando no puedes abrir un archivo.
* Esperamos que sea un programa bien implementado, con un código que sea fácil de seguir y que idealmente esté comentado.
* Los errores **NO** deben mostrarse de forma incremental. Si el archivo no presenta ninguno, debes indicarlo en consola.
* Tu programa debe poder reaccionar ante distintas infraestructuras (problema de heterogeneidad). Recuerde que no puede lanzar una cantidad infinita de procesos en un sistema.
* Puedes suponer que el formato de 8 columnas y 8 letras cada una se cumple siempre.

En cuanto a la implementación:

* Tu programa deberá compilar utilizando `OpenMPI`. Indica claramente, en el archivo de descripción de tu tarea, la versión y cómo se construye tu programa. Incluye un *makefile* si lo deseas.

* Debes suponer que **tu programa puede correr en uno o más nodos**.

Si deseas probar en alguna plataforma, nosotros habilitaremos una para que puedas correr (y compilar) tu código. Algunos detalles de la plataforma:
* S.O: `Ubuntu 18.04 (bionic)`
* Paquetes instalados: `openmpi-bin` y `libopenmpi-dev` versión `2.1.1-8` (o similar).
* Cores: 2

Si deseas acceso, puedes solicitarlo a través del foro del curso.

## Preguntas a contestar

1. ¿Cómo se compara esta implementación con la anterior realizada en `Python`? Indicar claramente qué elementos, que permiten el distribuir el procesamiento, se utilizan en cada caso y cual/es es/son la/las limitantes de uno u otro.

2. Incluye un diagrama que explique de forma gráfica tu arquitectura (quién hace cada paso, cuáles son los mensajes que se envían, etc.). ¿Cambia tu diagrama si corre en uno o varios nodos? ¿Por qué?

## Pauta de corrección

* (2 pts) Preguntas a contestar (0.5 pts la primera pregunta, 1.5 pts la segunda - solo si está implementado el código)
* (4 pts) Programa versión `MPI`

**Descuentos**

* Código poco legible (-0.5 pts)
* Bajo ciertas condiciones (ej. archivo con muchas líneas) el equipo de pruebas queda inutilizable y debe ser reiniciado (-0.5 pts)
