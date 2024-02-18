// Programa de prueba de la clase Lista.
#include <string.h>
#include <stdlib.h>

#include "Lista.h"
template < typename T >
void probarLista(Lista< T > &objetoLista, const string &nombreTipo)
{
	int opcion; 
	T valor; // almacena el valor de entrada

	do{ 
		system("cls");
		cout<<"\n Prueba de una Lista de valores tipo " << nombreTipo << "\n"
			<<"\n Escriba una de las siguentes opciones:"
			<<"\n 1. insertar al principio de la lista"
			<<"\n 2. insertar al final de la lista"
			<<"\n 3. eliminar del principio de la lista"
			<<"\n 4. eliminar del final de la lista"
			<<"\n 5. terminar el procesamiento de la lista"
			<<"\n >> ";
		cin >> opcion;
		
		switch (opcion)
		{
 			case 1: // inserta al principio
				cout << " Escriba " << nombreTipo << ": ";
 				cin >> valor;
 				objetoLista.insertarAlFrente(valor);
 				objetoLista.imprimir();
 			break;
 			
 			case 2: // inserta al final
 				cout << " Escriba " << nombreTipo << ": ";
 				cin >> valor;
 				objetoLista.insertarAlFinal(valor);
 				objetoLista.imprimir();
 			break;
 
 			case 3: // elimina del principio
 				if (objetoLista.eliminarDelFrente(valor))
 					cout <<" "<< valor << " se elimino de la lista\n";
				objetoLista.imprimir();
 			break;
 
 			case 4: // elimina del final
 				if (objetoLista.eliminarDelFinal(valor))
 					cout <<" "<<valor << " se elimino de la lista\n";
				objetoLista.imprimir()
 			break;
 		}
 	} while (opcion != 5); 
}


int main()
{
	int opc=0;
	do{
		system("cls");
		cout<< "\n tipos de listas: "<<endl
			<< " 1. entero"<<endl
			<< " 2. double"<<endl
			<< " 3. char(un caracter)"<<endl
			<< " 4. string(una palabra)"<<endl
			<< " 5. salir"<<endl
			<< " opcion? "; cin >> opc;
			
			if(opc == 1)
			{
				Lista< int > listaInt;
 				probarLista(listaInt, "entero"); 
			}
		
			else if(opc == 2)
			{
				Lista< double > listaDouble;
 				probarLista(listaDouble, "double");
			}
			
			else if(opc == 3)
			{
				Lista< char >listaChar;
 				probarLista( listaChar, "caracter"); 
			}
			
			else if(opc == 4)
			{
				Lista< string > listaString;
 				probarLista(listaString, "string");	
			}
			
			else
				cout<<"\n opcion invalida";
			
		cout<<"\n\n";
		system("pause");
	}while(opc != 5);
	
	return 0;
}