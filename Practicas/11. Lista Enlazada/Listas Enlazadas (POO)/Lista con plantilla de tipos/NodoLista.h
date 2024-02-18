//: NodoLista.h
// Definicion de la plantilla de clase NodoLista.
#ifndef NODOLISTA_H
#define NODOLISTA_H
// declaracin anticipada de la clase Lista, requerida para anunciar que la clase
// Lista existe y poder utilizarla en la declaracin friend de la linea 13
template< typename TIPONODO > class Lista;

template< typename TIPONODO >
class NodoLista
{
	friend class Lista< TIPONODO >; // hace de Lista una amiga
	public:
 		NodoLista(const TIPONODO &); // constructor
 		TIPONODO obtenerDatos() const; // devuelve los datos en el nodo
 	private:
 		TIPONODO datos; 
 		NodoLista< TIPONODO > *siguientePtr; // siguiente nodo en la lista
 };

 // constructor
 template< typename TIPONODO >
 NodoLista< TIPONODO >::NodoLista(const TIPONODO &info): datos(info), siguientePtr(0){} 

 // devuelve una copia de los datos en el nodo
 template< typename TIPONODO >
 TIPONODO NodoLista< TIPONODO >::obtenerDatos() const { return datos; }

#endif