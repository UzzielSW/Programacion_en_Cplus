/*Ejercicio 9: Escriba una funci�n nombrada tiempo() que tenga un par�metro en n�mero 
entero llamado totalSeg y tres par�metros de referencia enteros nombrados horas, min
y seg. La funci�n es convertir el n�mero de segundos transmitido en un n�mero 
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
	
	getchar();
	return 0;
}

void tiempo(int totalSeg, int& horas, int& min, int& seg)
{	
	horas = totalSeg / 3600;
	totalSeg %= 3600;

	min = totalSeg / 60;
	seg = totalSeg % 60; 
}