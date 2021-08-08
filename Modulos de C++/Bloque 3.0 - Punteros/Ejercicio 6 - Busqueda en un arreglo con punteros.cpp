/*Ejercicio 6: Hacer una funcion para almacenar N numeros en un arreglo dinamico,  
posteriormente en otra funcion buscar un numero en particular. 
NOTA: Puedes utilizar cualquier metodo de busqueda(Secuencial o Binaria)*/ 
#include<iostream>
using namespace std;

void pedirDatos();
void busqueda(int *, int);
int nElementos,  *elemento;

int main()
{
	pedirDatos();
	busqueda(elemento, nElementos);
	
	delete[] elemento; //Liberar memoria utilizada en el arreglo
	
	return 0;
}

void pedirDatos()
{
	cout<<"Digite el numero de elementos del arreglo: ";
	cin>>nElementos;
	if(nElementos <= 0){
		cout<<"\n No es posible realizar el proceso con valor introducido";
		return;
	}
	
	elemento = new int[nElementos]; //Crear el arreglo
	
	for(int i=0; i < nElementos; i++)//Pedir datos al usuario para el arreglo
	{
		cout<<"Digite un numero["<<i<<"]: ";
		cin>>*(elemento+i);
	}
}


void busqueda(int *elemento, int nElementos)
{
	if(nElementos <= 0) return;

	int dato, i;
	bool band = false;
	
	cout<<"\nDigite el numero que quiere buscar: ";
	cin>>dato;
	
	//Busqueda Secuencial
	i = 0;
	while((band == false) && (i < nElementos))
	{
		if(*(elemento+i) == dato) //Verificar si existe el numero en el arreglo
			band = true; //Si lo encuentra bandera cambia a Verdadero
		i++;
	}
	
	if(band == false)
		cout<<"El numero "<<dato<<" NO ha sido encontrado"<<endl;
	else
		cout<<"El numero "<<dato<<" ha sido encontrado en la posicion "<<(i-1)<<endl;
}
