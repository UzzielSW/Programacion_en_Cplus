#include <iostream>
#include <regex>
using namespace std;

int main()
{
	regex patron("\\s+");// para buscar coincidencia de espacios en blanco
	string replace = "/",
			texto = "esto es un texto con demasiados espacios en blanco";

	//reemplaza expresiones regulares enparejados
	cout<<regex_replace(texto, patron, replace);

	return 0;
}