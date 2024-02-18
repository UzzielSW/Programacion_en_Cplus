/*Ejercicio 15: Hacer una estructura llamada alumno,  en la cual se tendran los siguientes
Campos: Nombre,  edad,  promedio,  pedir datos al usuario para 3 alumnos, comprobar cual 
de los 3 tiene el mejor promedio y posteriormente imprimir los datos del alumno.
NOTA: Usar punteros a estructura*/
#include<iostream>
using namespace std;

struct Alumno
{
	char nombre[30];
	int edad;
	float promedio;
};

int main()
{
//	declaracion de variables y funciones
	Alumno *puntero_alumno;
	int tam = 0;
	void pedirDatos(Alumno *, int);
	void comprobarMejorPromedio(Alumno *, int);

//	generando arreglo de estructura dinamica
	cout<<"\n ingrese la cantidad: ";cin>>tam;
	puntero_alumno = new Alumno[tam];

//	llamado de funciones
	cout<<endl;
	pedirDatos(puntero_alumno, tam);	
	comprobarMejorPromedio(puntero_alumno, tam);
	
	return 0;
}

void pedirDatos(Alumno *puntero_alumno, int tam)
{
	for(int i=0; i < tam; i++)
	{
		fflush(stdin); //Limpiar buffer para poder seguir digitando datos
		cout<<"\n Digite su nombre: ";
		cin.getline((puntero_alumno + i)->nombre, 30, '\n');

		cout<<" Digite su edad: ";
		cin>>(puntero_alumno + i)->edad;

		cout<<" Digite su promedio: ";
		cin>>(puntero_alumno + i)->promedio;
	}
}

void comprobarMejorPromedio(Alumno *puntero_alumno, int tam)
{
	float mayor = 0;
	int pos = 0;
	
	for(int i=0; i < tam; i++)
	{
		if((puntero_alumno + i)->promedio > mayor)
		{
			mayor = (puntero_alumno + i)->promedio;//sacamos el mayor promedio
			pos = i;// guardamos la posicion del mayor promedio
		}
	}
	
	//Imprimimos los datos del alumno con el mejor promedio	
	cout<<"\nAlumno con el mejor promedio: "<<endl;
	cout<<"Nombre: "<<(puntero_alumno + pos)->nombre<<endl;
	cout<<"Edad: "<<(puntero_alumno + pos)->edad<<endl;
}