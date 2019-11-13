/*5. Hacer 2 estructuras una llamada promedio que tendr� los siguientes campos:
nota1, nota2, nota3; y otro llamada alumno que tendr� los siguientes miembros:
nombre, sexo, edad; hacer que la estructura promedio este anidada en la
estructura alumno, luego pedir todos los datos para un alumno, luego calcular su
promedio, y por ultimo imprimir todos sus datos incluidos el promedio.*/
#include<iostream>
using namespace std;

struct Promedio
{
	float nota1;
	float nota2;
	float nota3;
};

struct Alumno
{
	char nombre[20];
	char sexo[10];
	int edad;
	struct Promedio prom;
};

int main()
{
	float promedio_alumno;
	Alumno alumno1;

	cout<<"Nombre: "; cin.getline(alumno1.nombre, 20, '\n');
	cout<<"Sexo: "; cin.getline(alumno1.sexo, 10, '\n');
	cout<<"Edad: "; cin>>alumno1.edad;
	
	cout<<".:Notas del Examen:."<<endl;
	cout<<"Nota1: "; cin>>alumno1.prom.nota1;
	cout<<"Nota2: "; cin>>alumno1.prom.nota2;
	cout<<"Nota3: "; cin>>alumno1.prom.nota3;
	
	//Sacando el promedio del alumno
	promedio_alumno = (alumno1.prom.nota1 + alumno1.prom.nota2 + alumno1.prom.nota3)/3;
	
	
	cout<<"\n\nMostrando Datos"
		<<"\nNombre: "<<alumno1.nombre
		<<"\nSexo: "<<alumno1.sexo
		<<"\nEdad: "<<alumno1.edad
		<<"\nPromedio: "<<promedio_alumno<<endl;
	
	getchar();
	return 0;
}