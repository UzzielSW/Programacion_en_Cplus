// : Lista.h
// Definicion de la plantilla de clase Lista.
#ifndef LISTA_H
#define LISTA_H
#include <iostream>
#include "NodoLista.h" // definicion de la clase NodoLista
using namespace std;

template< typename TIPONODO >
class Lista
{
	public:
		Lista(); 
	   ~Lista(); 
		void insertarAlFrente(const TIPONODO &);
		void insertarAlFinal(const TIPONODO &);
		bool eliminarDelFrente(TIPONODO &);
		bool eliminarDelFinal(TIPONODO &);
		bool estaVacia() const;
		void imprimir() const;
	private:
		NodoLista< TIPONODO > *primeroPtr; // apuntador al primer nodo
		NodoLista< TIPONODO > *ultimoPtr; // apuntador al ultimo nodo
		// funcion utilitaria para asignar un nuevo nodo
		NodoLista< TIPONODO > *obtenerNuevoNodo(const TIPONODO &);
};

// constructor predeterminado
template< typename TIPONODO >
Lista< TIPONODO >::Lista(): primeroPtr(0), ultimoPtr(0){}

 // destructor
template< typename TIPONODO >
Lista< TIPONODO >::~Lista()
{
 	if (!estaVacia()) // la Lista no esta vacia
	{ 
 		cout << " Destruyendo nodos ...\n";

 		NodoLista< TIPONODO > *actualPtr = primeroPtr;
 		NodoLista< TIPONODO > *tempPtr;

 		while (actualPtr != 0) // elimina los nodos restantes
 		{ 
 			tempPtr = actualPtr;
 			cout << " " <<tempPtr->datos << '\n';
 			actualPtr = actualPtr->siguientePtr;
 			delete tempPtr;
 		} 
 	} 
	
	cout << "\n  Se destruyeron todos los nodos\n";
}

 // inserta un nodo al frente de la lista
template< typename TIPONODO >
void Lista< TIPONODO >::insertarAlFrente( const TIPONODO &valor )
{
 	NodoLista< TIPONODO > *nuevoPtr = obtenerNuevoNodo(valor); // nuevo nodo

 	if (estaVacia()) // la Lista esta vacia
		primeroPtr = ultimoPtr = nuevoPtr; // la nueva lista solo tiene un nodo
 	else // la Lista no esta vacia
 	{ 
 		nuevoPtr->siguientePtr = primeroPtr; // apunta el nuevo nodo al nodo que antes era el primero
		primeroPtr = nuevoPtr; // orienta primeroPtr hacia el nuevo nodo
 	}
} 

// inserta un nodo al final de la lista
template< typename TIPONODO >
void Lista< TIPONODO >::insertarAlFinal(const TIPONODO &valor)
{
 	NodoLista< TIPONODO > *nuevoPtr = obtenerNuevoNodo(valor); // nuevo nodo

 	if (estaVacia()) // la Lista esta vacia
 		primeroPtr = ultimoPtr = nuevoPtr; // la nueva lista solo tiene un nodo
 	else	// la Lista no esta vacia
 	{ 
 		ultimoPtr->siguientePtr = nuevoPtr; // actualiza el nodo que antes era el ultimo
 		ultimoPtr = nuevoPtr; // nuevo ultimo nodo
 	}
}

 // elimina un nodo de la parte frontal de la lista
template< typename TIPONODO >
bool Lista< TIPONODO >::eliminarDelFrente(TIPONODO &valor)
{
	if (estaVacia()) // la Lista esta vacia
 		return false; // la eliminacion no tuvo exito
 	else
 	{
 		NodoLista< TIPONODO > *tempPtr = primeroPtr; // contiene tempPtr a eliminar

 		if (primeroPtr == ultimoPtr)
 			primeroPtr = ultimoPtr = 0; // no hay nodos despues de la eliminacion
 		else
 			primeroPtr = primeroPtr->siguientePtr; // apunta al nodo que antes era el segundo

 		valor = tempPtr->datos; // devuelve los datos que se van a eliminar
 		delete tempPtr; // reclama el nodo que antes era el primero
 		return true; // la eliminacion tuvo exito
 	}
} 

// elimina un nodo de la parte final de la lista
template< typename TIPONODO >
bool Lista< TIPONODO >::eliminarDelFinal( TIPONODO &valor )
{
	if (estaVacia()) // la Lista esta vacia
 		return false; // la eliminacion no tuvo exito
 	else
 	{
 		NodoLista< TIPONODO > *tempPtr = ultimoPtr; // contiene tempPtr a eliminar

 		if (primeroPtr == ultimoPtr) // la Lista tiene un elemento
 			primeroPtr = ultimoPtr = 0; // no hay nodos despues de la eliminacion
 		else
 		{
 			NodoLista< TIPONODO > *actualPtr = primeroPtr;
 			// localiza el penultimo elemento
 			while (actualPtr->siguientePtr != ultimoPtr)
 				actualPtr = actualPtr->siguientePtr; // se desplaza al siguiente nodo

 			ultimoPtr = actualPtr; // elimina el ultimo nodo
 			actualPtr->siguientePtr = 0; // ahora este es el ultimo nodo
 		}

 		valor = tempPtr->datos; // devuelve el valor del nodo que antes era el ultimo
 		delete tempPtr; // reclama el nodo que antes era el ultimo
 		return true; // la eliminacion tuvo exito
 	}
}

 // esta la Lista vacia?
template< typename TIPONODO >
bool Lista< TIPONODO >::estaVacia() const { return primeroPtr == 0; }

// devuelve el apuntador al nodo recien asignado
template< typename TIPONODO >
NodoLista< TIPONODO > *Lista< TIPONODO >::obtenerNuevoNodo( const TIPONODO &valor )
{
 	return new NodoLista< TIPONODO >(valor);
}

// muestra el contenido de la Lista
template< typename TIPONODO >
void Lista< TIPONODO >::imprimir() const 
{
 	if (estaVacia())// la Lista esta vacia
 	{ 
 		cout << " La lista esta vacia\n\n";
 		return;
 	}

 	NodoLista< TIPONODO > *actualPtr = primeroPtr;
	cout << " La lista es: ";
	while (actualPtr != 0)// obtiene los datos del elemento
	{ 
		if(actualPtr->siguientePtr != NULL)
			cout << actualPtr->datos << "->";
		else
			cout << actualPtr->datos ;

		actualPtr = actualPtr->siguientePtr;
 	}
 	
 	cout << "\n\n";
}

#endif