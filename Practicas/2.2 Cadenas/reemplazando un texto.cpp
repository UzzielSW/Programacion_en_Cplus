#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	string cadena;
	string cadena2;
	string remplazar;
	int lond=0,pos=0;

	cout<<"\n ingresar un texto: "; 
	getline(cin, cadena);

	cout<<"\n cadena: "<<cadena<<endl;
	fflush(stdin);

	cout<<"\n ingrese el texto que desea reemplazar: "; 
	getline(cin, cadena2);
	fflush(stdin);

	lond = cadena2.length();
	pos = cadena.find(cadena2);

	cout<<"\n ingrese el texto por el que desea reemplazar: "; 
	getline(cin, reemplazar);

	//replazame la cadena en la posicion(pos), con longitud(lond), por el texto de la variable(remplazar)
	cadena.replace(pos, lond, remplazar);

	cout<<"\n cadena luego de ser modificada: "<<cadena<<endl;
	return 0;
}