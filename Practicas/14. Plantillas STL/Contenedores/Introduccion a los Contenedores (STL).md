---
title: Biblioteca de plantillas estandar (STL)
author: Brayan Puyol
description: Introduccion a los conceptos basicos a conocer sobre los contenedores.
---

# Introduccion a los Contenedores

Categorias:

- Contenedores de secuencia
- Contenedores asociativos
- Adaptadores de contenedores

## Clase contendora de la biblioteca estandar:

### Contenedores de secuencia

- Vector

  > Inserciones y eliminacion rapida en la parte final. Acceso directo a cualquier elemento.

- Deque

  > Inserciones y eliminacion rapida en la parte inicial o final. Acceso directo a cualquier elemento.

- List

  > Insercion y eliminacion rapida en cualquier parte.

### Contenedores asociativos

- Set

  > busqueda rapida, **no** se permiten duplicados

- multiSet

  > busqueda rapida, se permiten duplicados

- Map

  > asignacion de uno a uno, **no** se permiten duplicados y con busqueda rapida basada en claves.

- multiMap

  > asignacion de uno a varios, se permiten duplicados y con busqueda rapida basada en claves.

### Adaptadores de contenedores

- stack (Pila)

  > ultimo en entrar, primero en salir.

- queue (Cola)

  > primero en entrar, primero en salir.

- priority_queue

  > el elemento de mayor prioridad siempre es el primero en salir.

### " Casi contenedores "

Ellos exhiben capacidades similares a la de los contendores de primer clase pero no soportan sus capacidades.

- bitSet

  > para mantener conjunto de valores de bandera.

- valArray

  > para llevar a cabo operaciones vectoriales matematicas de alta velocidad

---

## Funciones miembro comunes para todos los contenedores de la STL

| Funcion                  | Uso                                                   |
| :----------------------- | :---------------------------------------------------- |
| empty                    | retorna **true** si no hay elementos en el contenedor |
| insert                   | insertar elementos en el contenedor                   |
| size                     | retorna el numero de elementos del contendor          |
| operator =               | asignar un contenedor a otro                          |
| operadores condicionales | operadores: "<, >, <=, >=, ==, !="                    |
| swap                     | intercambio de elementos de dos contenedores          |

## Funciones que solo se encuentran en contenedores de primera clase

| Funcion  | Uso                                                                                                                                                                   |
| -------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| max_size | retorna el numero maximo de elementos para un contendor                                                                                                               |
| begin    | las dos versiones de esta funcion retorna ya sea un **iterator** o un **const_iterator** que hace referencia al primer elemento del contenedor.                       |
| end      | las dos versiones de esta funcion retorna ya sea un **iterator** o un **const_iterator** que hace referencia a la siguiente posicion despues del final del contenedor |

## Funciones miembro comunes para todos los contenedores de la STL

| Funcion | Uso                                       |
| ------- | ----------------------------------------- |
| erase   | Elimina uno o mas elementos de contenedor |
| clear   | Elimina todos los elementos de contenedor |

---

## Los contenedores de secuencia tienen otras operaciones comunes

| funcion   | uso                                                                          |
| --------- | ---------------------------------------------------------------------------- |
| Front     | retorna una referencia al primer elemento de un contenedor que no este vacio |
| Back      | retorna una referencia al ultimo elemento de un contenedor que no este vacio |
| push_back | inserta un nuevo elemento al final del contenedor                            |
| pop_back  | quita el ultimo elemento del contenedor                                      |

## Contenedor de secuencia **_List_**

libreria `<list>`

algunas funciones miembro:

|            |           |         |
| ---------- | --------- | ------- |
| splice     | remove    | merge   |
| push_front | remove_if | reverse |
| pop_front  | unique    | sort    |

#### Contenedor de secuencia **_deque_**

libreria `<deque>`

- ofrece soporte para iteradores de acceso aleatorio, por lo que puede utilizarse con todos los algoritmos de la STL.

- El uso comun es el de mantener una cola de elementos (primero en entrar, primero en salir).
- funciones son iguales a la _list_.

## Contenedores asociativos (Set, MultiSet, Map, MultiMap)

libreria `<set`
libreria `<map>`

- ofrecen un acceso directo para almacenar y recuperar elementos mediante claves.
- todos soportan funciones miembros, incluyendo find, lower-bound, upper-bound y count

## Adaptadores de contenedores (stack, queue, priority_queue)

- Estos no son contenedores de primera clase y no soportan iteradores. El beneficio de un adaptador es que el programa puede elegir una estructura de dato subyacente apropiada.
