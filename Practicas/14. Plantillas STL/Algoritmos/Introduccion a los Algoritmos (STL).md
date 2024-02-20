---
title: Biblioteca de plantillas estandar (STL)
author: Brayan Puyol
description: Introduccion a los algoritmos.
---

# Introduccion a los Algoritmos

## Algoritmos de secuencia cambiantes

|               |                |                 |                  |
| ------------- | -------------- | --------------- | ---------------- |
| copy          | random_shuffle | replace_copy_if | swap_ranges      |
| copy_backward | remove         | replace_if      | transform        |
| fill          | remove_copy    | reverse         | unique           |
| fill_n        | remove_copy_if | reverse_copy    | unique_copy      |
| generate      | remove_if      | rotate          | partition        |
| generate_n    | replace        | rotate_copy     | stable_partition |
| iter_swap     | replace_copy   | swap            |                  |

- fill, fill_n

  > establecen todos los elementos en un rango de elementos del contenedor a un valor especifico.

- generate, generate_n

  > usan una funcion generadora para crear valores para cada elemento en un rango de elementos del contenedor.

- remove, remove_if, remove_copy, remove_copy_if

  > se utiliza **remove** para eliminar todos los elementos con el valor asignado. **remove_copy es para copiar todos los elementos que no tengan el valor asignado y se colocan en un vector de copia. **remove_if** para eliminar todos aquellos elementos en el rango indicado. **remove_copy_if\*\* para cipiar todos aquellos elementos en el rango indicado, en un vector copia.

- replace, replace_if, replace_copy, replace_copy_if
  > tienen la misma funcionalidad que las funciones **remove** solo que estas modifican los elementos por un valor indicado.

## Algoritmos de busqueda

|               |               |          |
| ------------- | ------------- | -------- |
| adjacent_find | find          | find_if  |
| count         | find_each     | mismatch |
| count_if      | find_end      | search   |
| equal         | find_first_of | search_n |

- equal, mismatch y lexicographical_compare

  > se demuestra la comparacion de secuencias de valores para ver si son iguales.

- algoritmos de busqueda y ordenamiento de la libreria `<algorithm>`

  > find, find_if, sort, binary_search, min, max

- algoritmos para copiar
  > copy_backward, merge, unique, reverse, inplace_merge, unique_copy, reverse_copy

## Algoritmos numericos del archivo de la libreria `<numeric>`

|              |                     |
| ------------ | ------------------- |
| accumulate   | partial_sum         |
| innerproduct | adjacent_difference |

## Algoritmos matematicos de la libreria `<numeric>`

> random_shuffle, count, count_if, min_element, max_element, accumulate, for_each y transform

## Algoritmos para operaciones Set, libreria `algorithm`

> includes, set_difference, set_intersection, set_symmetric_difference, set_union

## Algoritmos de busqueda

> lower_bound, upper_bound, equal_range

## Algoritmos de ordenamiento heapsort

> push_heap, pop_heap, make_heap, sort_heap
