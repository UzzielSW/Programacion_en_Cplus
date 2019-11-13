/*2. Hacer una estructura llamada alumno, en la cual se tendr�n los siguientes
Campos: Nombre, edad, promedio, pedir datos al usuario para 3 alumnos, comprobar cu�l 
de los 3 tiene el mejor promedio y posteriormente imprimir los datos del alumno.*/
#include<iostream>
using namespace std;

struct Alumno
{
	char nombre[20];
	int edad;
	float promedio;
};

int main()
{
	int mayor = 0, pos=0;
	Alumno alumnos[3];

	//Pedir los datos para 3 alumnos
	for(int i=0; i < 3; i++)
	{
		fflush(stdin);
		cout<<"Nombre: "; cin.getline(alumnos[i].nombre, 20, '\n');
		cout<<"Edad: "; cin>>alumnos[i].edad;
		cout<<"Promedio: "; cin>>alumnos[i].promedio;
		
		if(alumnos[i].promedio > mayor){
			mayor = alumnos[i].promedio; //sacamos el mayor promedio
			pos = i; // guardamos la posicion del mayor promedio
		}
		cout<<"\n";
	}
	
	//Imprimimos los datos del alumno con el mejor promedio
	cout<<"\nAlumnos con el mejor Promedio: \n"
		<<"\nNombre: "<<alumnos[pos].nombre
		<<"\nEdad: "<<alumnos[pos].edad
		<<"\nPromedio: "<<alumnos[pos].promedio<<endl;
	
	getchar();
	return 0;
}