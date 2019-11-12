/*11. Hacer un programa que simule un cajero autom�tico con un saldo inicial 
de 1000 D�lares.*/
#include<iostream>
using namespace std;

int main()
{
	int saldo_inicial = 1000, opc;
	float extra, saldo = 0, retiro; 
	
	cout<<"\tBienvenido a su cajero automatico"
		<<"\n1.Ingresar dinero en cuenta"
		<<"\n2.Retirar dinero de la cuenta"
		<<"\n3.Salir"
		<<"\nOpcion: "; 
	cin>>opc;
	
	switch(opc)
	{
		case 1: 
			cout<<"\nCuanto dinero desea ingresar en cuenta: "; 
			cin>>extra;
				
			cout<<"\nDinero en cuenta: "<< (saldo_inicial + extra);
		break;

		case 2: 
			cout<<"\nCuanto dinero desea retirar: "; 
			cin>>retiro;
				
			if(retiro > saldo_inicial)
				cout<<"No cuenta con esa cantidad";
			else
			{
				cout<<"\nDinero en cuenta: "<< (saldo_inicial - retiro); 
			}
		break;

		case 3: break;
		default: cout<<"Se equivoco de opcion de menu";break;
	}
	
	return 0;
}