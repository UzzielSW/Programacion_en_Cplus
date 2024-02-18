// Arbol.h
// Definición de la plantilla de clase Arbol.
#ifndef ARBOL_H
#define ARBOL_H

#include "NodoArbol.h"

// definición de la plantilla de clase Arbol
template <typename TIPONODO>
class Arbol
{
public:
  Arbol(); // constructor
  void insertarNodo(const TIPONODO &);
  void recorridoPreOrden() const;
  void recorridoInOrden() const;
  void recorridoPostOrden() const;

private:
  NodoArbol<TIPONODO> *raizPtr;
  // funciones utilitarias
  void ayudanteInsertarNodo(NodoArbol<TIPONODO> **, const TIPONODO &);
  void ayudantePreOrden(NodoArbol<TIPONODO> *) const;
  void ayudanteInOrden(NodoArbol<TIPONODO> *) const;
  void ayudantePostOrden(NodoArbol<TIPONODO> *) const;
};

// constructor
template <typename TIPONODO>
Arbol<TIPONODO>::Arbol()
{
  raizPtr = 0; // indica que al principio el árbol está vacío
}

// inserta el nodo en el Arbol
template <typename TIPONODO>
void Arbol<TIPONODO>::insertarNodo(const TIPONODO &valor)
{
  ayudanteInsertarNodo(&raizPtr, valor);
}

// función utilitaria llamada por insertarNodo; recibe un apuntador
// a un apuntador, para que la función pueda modificar el valor del apuntador
template <typename TIPONODO>
void Arbol<TIPONODO>::ayudanteInsertarNodo(NodoArbol<TIPONODO> **ptr, const TIPONODO &valor)
{
  // el subárbol está vacío; crea nuevo NodoArbol que contiene el valor
  if (*ptr == 0)
    *ptr = new NodoArbol<TIPONODO>(valor);
  else
  { // el subárbol no está vacío
    // los datos a insertar son menores que los datos en el nodo actual
    if (valor < (*ptr)->datos)
      ayudanteInsertarNodo(&((*ptr)->izquierdoPtr), valor);
    else
    {
      // los datos a insertar son mayores que los datos en el nodo actual
      if (valor > (*ptr)->datos)
        ayudanteInsertarNodo(&((*ptr)->derechoPtr), valor);
      else // se ignora el valor de datos duplicado
        cout << valor << " dup" << endl;
    }
  }
}

// empieza el recorrido preorden del Arbol
template <typename TIPONODO>
void Arbol<TIPONODO>::recorridoPreOrden() const
{
  ayudantePreOrden(raizPtr);
}

// función utilitaria para realizar el recorrido preorden del Arbol
template <typename TIPONODO>
void Arbol<TIPONODO>::ayudantePreOrden(NodoArbol<TIPONODO> *ptr) const
{
  if (ptr != 0)
  {
    cout << ptr->datos << ' ';           // procesa el nodo
    ayudantePreOrden(ptr->izquierdoPtr); // recorre el subárbol izquierdo
    ayudantePreOrden(ptr->derechoPtr);   // recorre el subárbol derecho
  }
}

// empieza el recorrido inorden del Arbol
template <typename TIPONODO>
void Arbol<TIPONODO>::recorridoInOrden() const
{
  ayudanteInOrden(raizPtr);
}

// función utilitaria para realizar el recorrido inorden del Arbol
template <typename TIPONODO>
void Arbol<TIPONODO>::ayudanteInOrden(NodoArbol<TIPONODO> *ptr) const
{
  if (ptr != 0)
  {
    ayudanteInOrden(ptr->izquierdoPtr); // recorre el subárbol izquierdo
    cout << ptr->datos << ' ';          // procesa el nodo
    ayudanteInOrden(ptr->derechoPtr);   // recorre el subárbol derecho
  }
} // fin de la función ayudanteInOrden

// empieza el recorrido postorden del Arbol
template <typename TIPONODO>
void Arbol<TIPONODO>::recorridoPostOrden() const
{
  ayudantePostOrden(raizPtr);
}

// función utilitaria para realizar el recorrido postorden del Arbol
template <typename TIPONODO>
void Arbol<TIPONODO>::ayudantePostOrden(NodoArbol<TIPONODO> *ptr) const
{
  if (ptr != 0)
  {
    ayudantePostOrden(ptr->izquierdoPtr); // recorre el subárbol izquierdo
    ayudantePostOrden(ptr->derechoPtr);   // recorre el subárbol derecho
    cout << ptr->datos << ' ';            // procesa el nodo
  }
}

#endif