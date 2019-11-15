/*Ejercicio 5: Escriba una plantilla de funci�n llamada despliegue() que despliegue el valor
del argumento �nico que se le transmite cuando es invocada la funci�n.*/
//pantillas de funcion son para realizar una misma accion con diferentes tipos de variables
#include<iostream>
using namespace std;

template <class TIPOD>
void despliegue(TIPOD dato);

int main()
{
	int dato1 = 4;
	float dato2 = 5.678;
	double dato3 = 15.6789;
	char dato4 = 'a';
	
	despliegue(dato1);
	despliegue(dato2);
	despliegue(dato3);
	despliegue(dato4);
	
	getchar();
	return 0;
}

template <class TIPOD>
void despliegue(TIPOD dato)
{
	cout<<"El dato es: "<<dato<<endl;
}