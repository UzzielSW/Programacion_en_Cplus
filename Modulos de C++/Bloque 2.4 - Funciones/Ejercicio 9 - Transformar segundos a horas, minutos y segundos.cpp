/*Ejercicio 9: Escriba una funcion nombrada tiempo() que tenga un parametro en numero 
entero llamado totalSeg y tres parametros de referencia enteros nombrados horas, min
y seg. La funcion es convertir el numero de segundos transmitido en un numero 
equivalente de horas, minutos y segundos.*/
#include<iostream>
using namespace std;

void tiempo(int, int&, int&, int&);

int main()
{
	int totalSeg, horas, min, seg;
	
	cout<<"Digita la cantidad de segundos: ";
	cin>>totalSeg;
		
	tiempo(totalSeg, horas, min, seg);
	
	cout<<"\nHoras: "<<horas
		<<"Minutos: "<<min
		<<"Segundos: "<<seg<<endl;
	
	return 0;
}

void tiempo(int totalSeg, int& horas, int& min, int& seg)
{	
	horas = totalSeg / 3600;
	totalSeg %= 3600;

	min = totalSeg / 60;
	seg = totalSeg % 60; 
}