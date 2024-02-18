// : NodoArbol.h
// Definición de la plantilla de clase NodoArbol.
#ifndef NODOARBOL_H
#define NODOARBOL_H

// declaración anticipada de la clase Arbol
template <typename TIPONODO>
class Arbol;
// definición de la plantilla de clase NodoArbol
template <typename TIPONODO>
class NodoArbol
{
  friend class Arbol<TIPONODO>;

public:
  NodoArbol(const TIPONODO &d) : izquierdoPtr(0), // apuntador al subárbol izquierdo
                                 datos(d),        // datos del nodo del árbol
                                 derechoPtr(0)    // apuntador al subárbol derecho
  {
  }

  // devuelve una copia de los datos del nodo
  TIPONODO obtenerDatos() const { return datos; }

private:
  NodoArbol<TIPONODO> *izquierdoPtr; // apuntador al subárbol izquierdo
  TIPONODO datos;
  NodoArbol<TIPONODO> *derechoPtr; // apuntador al subárbol derecho
};

#endif