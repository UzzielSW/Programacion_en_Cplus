/*Ejercicio 1: Hacer un programa para agregar numeros enteros a una pila,  hasta que el
usuario lo decida,  despues mostrar todos los numeros introducidos en la pila.*/
#include<iostream>
using namespace std;

struct Nodo
{
	int dato;
	Nodo *siguiente;
};

//Prototipos de Funcion
void agregarPila(Nodo *&, int); 
void sacarPila(Nodo *&, int &);

int main()
{
	Nodo *pila = NULL;	//Inicializamos pila
	int dato;
	char rpt;
	
	do{ //Pedimos todos los elementos de la pila
		cout<<"Digite un numero: "; cin>>dato;
		agregarPila(pila, dato);
	
		cout<<"\nDesea agregar otro numero a pila(s/n): "; cin>>rpt;
	}while((rpt == 's')||(rpt == 'S'));
	
	
	cout<<"\nMostrando los elementos de la pila: ";
	while(pila != NULL)
	{
		sacarPila(pila, dato);
		
		if(pila != NULL)
			cout<<dato<<" ,  ";
		else
			cout<<dato<<".";
	}
	
	return 0;
}

void agregarPila(Nodo *&pila, int n)
{
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato = n;
	nuevo_nodo->siguiente = pila;
	pila = nuevo_nodo;
	
	cout<<"\tElemento "<<n<<" agregado a PILA correctamente";
}

void sacarPila(Nodo *&pila, int &n)
{
	Nodo *aux = pila;
	n = aux->dato;
	pila = aux->siguiente;
	delete aux;
}