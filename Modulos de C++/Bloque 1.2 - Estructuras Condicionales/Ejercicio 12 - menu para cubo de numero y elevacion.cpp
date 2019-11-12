/*12. Hacer un men� que considere las siguientes opciones:
	Caso 1: Cubo de un numero
	Caso 2: Numero par o impar
	Case 3: salir.
*/
#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	int opc, numero, cubo;
	
	cout<<"\tMENU"
		<<"\n1. Cubo de un numero"
		<<"\n2. Numero par o impar"
		<<"\n3. Salir"
		<<"\nOpcion: "; 
	cin>>opc;
	
	switch(opc)
	{
		case 1: 
			cout<<"\nDigite un numero: "; cin>>numero;
			cout<<"El cubo del numero es: "<< pow(numero, 3); //elevamos el numero al cubo
		break;
		
		case 2: 
			cout<<"\nDigite un numero: "; cin>>numero;
			
			if((numero % 2) == 0)
				cout<<"El numero es par";
			else
				cout<<"El numero es impar";
		break;

		case 3: break;
	}
	
	return 0;
}