/*Ejercicio 22: Escriba una funci�n escribeNumeros(int ini, int fin) que devuelva 
en la salida est�ndar los n�meros del ini al fin. Escriba una versi�n que escriba los 
n�meros en orden ascendente.

		escribeNumeros(ini,fin) = ini                             , si ini=fin
								  escribeNumeros(ini,fin-1)       , si fin>ini
*/
#include<iostream>
using namespace std;

//Prototipo de Funcion
int escribeNumeros(int, int);

int main()
{
	int ini, fin;
	
	//Pedimos los datos al usuario
	cout<<"Escriba el inicio: ";
	cin>>ini; 

	cout<<"Escriba el fin: "; 
	cin>>fin;
	
	//Llamamos a la funcion de forma iterativa para mostrar todos los elementos
	for(int i = ini; i <= fin; i++)
		cout<<escribeNumeros(i, fin)<<" ";
	
	getchar();
	return 0;
} 

int escribeNumeros(int ini, int fin)
 {
	if(ini == fin)//Caso base
		return ini;
	else//Caso general
		return escribeNumeros(ini, fin - 1);
}