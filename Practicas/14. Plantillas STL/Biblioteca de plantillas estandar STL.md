---
title: Biblioteca de plantillas estandar (STL)
author: Brayan Puyol
description: Introduccion a los conceptos basicos a conocer sobre las plantillas.
---

# Plantillas Estandar (STL)

Componentes:

- Contenedores [Plantillas de estructuras de datos populares]

  - Vector

    > arreglo que puede cambiar de tamaño de forma dinamica

  - List

    > listas doblemente enlazadas

  - Deque
    > cola con doble terminacion

- Iteradores

  > son para manipular los elementos de los contenedores

- algoritmos
  > son funciones que realizan manipulaciones de datos comunes como: busqueda, ordenamiento, comparacion de elementos y mucho mas.

## Tipos de excepciones de la STL [libreria "stdexcept"]

- **out_of_range**

  > Indica cuando el indice esta fuera de rango. Ejemplo cuando se especifica un subindice invalido en la funcion **at** de vector.

- **invalid_argument**

  > Indica que se paso un argumento invalido a una funcion.

- **length_error**

  > Indica un intento de crear un contenedor demaciado largo, un objeto string, etc.

- **bad_alloc**
  > Indica un intento de asignar memoria con new (o con un asignador) fallo debido a que no habia suficiente memoria disponible.
