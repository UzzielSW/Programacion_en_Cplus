#include <iostream>
#include <stdlib.h>

int main()
{
	int opc, num, n;
	int binario[100], cant = 0, decimal = 0;
	int divisor = 2, cociente, res;
	int arreglo[n];

	do{
		system("cls");
		cout<<"\n 1. Decimal a binario"
			<<"\n 2. Binario a decimal"
			<<"\n 3. salir"
			<<"\n\n  ingrese una opcion: ";
		cin>>opc;
			
		switch(opc)
		{
			case 1:
				cout<<"\n ingrese un numero: ";
				cin>>num;

				do{
					res = num % divisor;
					binario[cant] = res;
					cociente = num/divisor;	
					if(cociente > 1)
						num = cociente;
					else
						binario[++cant] = cociente;

					cant++;
				}while(cociente > 1); //fin de convertir a binario
					
				cout<<"\n el numero en binario es: ";
				for(int i = 0; i < cant; i++)
					cout<<binario[i];
				
				cout<<"\n orden correcto: ";
				for(int i = cant-1; i >= 0; i--)
					cout<<binario[i];

				//	limpieza de variables
				arreglo[n] = 0;		
				cant = 0;
				decimal = 0;

			break;
		
			case 2:
				cout<<"\n ingrese la longitud del numero: ";
				cin>>n;
				
				cout<<"\ningrese un numero binario: ";
				for(int i = n-1; i >= 0; i--)
					cin>>arreglo[i];

				for(int i = 0; i < n; i++)
					arreglo[i] = arreglo[i] * (pow(divisor, i));
				
				for(int i = 0; i < n; i++)
					decimal += arreglo[i];
				
				cout<<"\n decimal: "<<decimal;
					
				//limpiesa de variables
				arreglo[n] = 0;		
				cant = 0;
				decimal = 0;

			break;	
		
			case 3:	cout<<"\n gracias por usar el programa";break;	

			default: cout<<"\n ingrese otra opcion";
		}
		fflush(stdin);
		getchar();	
	}while(opc != 3);

	return 0;
}//fin main


void binario2(int binario[100], int cant)
{
	int decimal = 0;
	int productos[cant+1];

	for(int i = 0; i < cant; i++)
		productos[i] = binario[i] * (pow(2, i));
	
	for(int i = 0; i < cant; i++)
		decimal += productos[i];
	
	cout<<"\n decimal: "<<decimal;
}