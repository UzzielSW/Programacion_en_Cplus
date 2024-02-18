/* 
	escribir un programa para simular el comportaminento de area de un banco
	en los cual los datos se almacenaran y manejaran bajo el concepto de listas lineales  
	mediante un menu cuyas opciones son: 

	1-crear una cuenta

    	desde esta opcion se llamara a la operacion crea final de lista si no existe 
    	ninguna cuenta o inserta  final si ya existe una cuenta la ista ya esta creada.

	2-depositar a una cuenta existente

    	desde esta opcion  se ingresara el numero de la cuenta y se debe realizar la operacion de lista adecuada para verificar si existe (operacion busca desordena) si la cuenta es encontrada , se solicitara el saldo y se altualizara el Nodo con el deposito.

	3-retirar de una cuenta 

    	se debe realizar una realacion similar a la de deposito. 

	4-consultar 

  		es parecida a la primera , consultando el saldo.

	5-imprimir un reporte de todas las cuenta 

    	imprime dede llamar a recorre y imprimira todas las cuentas.

	6-eliminar una cuenta

  	 	debe llamar a la funcion elimina y luego se mete en una pila o una cola dinamica.

	7-salir 

	(al salir, las cuentas activas y eliminadas deben ser almacenadas en archivos)


	los datos que almacena la cuenta son:
		- Nombre de cuenta
		- tipo de la cuenta
		- el numero de cuenta de 6 digitos que no se repite. 
		(generado aleatoriamente , se usa busca para ver si el numero generado ya existe) 
		- el saldo de de la cuenta 
*/

#include "Helpers.h"
#include <conio.h>

int main()
{	//variables
	int opc;
	Nodo *p = NULL;
	Nodo *c = NULL;
	//Funciones
	Nodo *Crea_Final();
	Nodo *Inserta_Final(Nodo *p);
	void Depositar_Cuenta(Nodo *p);
	void Retirar_Cuenta(Nodo *p);
	void Consultar_Cuenta(Nodo *p);
	void Imprime_Cuentas(Nodo *p, char opc);
	Nodo *Eliminar_Cuenta(Nodo *p, Nodo **c);
	void Guardar_Cuentas(Nodo *p, Nodo *c);
	void Recargar_Cuentas(Nodo **p, Nodo **c);
	//RECUPERANDO LAS CUENTAS DE LOS ARCHIVOS
	Recargar_Cuentas(&p, &c);
	Sleep(3000);
	// MENU
	do
	{
		system("cls");
		SetConsoleTextAttribute (screen, 128);
		cout<<"\n\t:..:Banco Ghenos:..:\t\t\t"<<char(174)<<"Junior"<<char(175);
		SetConsoleTextAttribute (screen, 137);
		cout<<"\n\n 1.Crear Cuenta";
		cout<<"\n 2.Depositar a una cuenta existente";
		cout<<"\n 3.Retirar de una cuenta existente";
		cout<<"\n 4.Consultar saldo";
		cout<<"\n 5.Reporte de cuenta activas";
		cout<<"\n 6.Reporte de cuenta eliminadas";
		cout<<"\n 7.Eliminar una cuenta";
		SetConsoleTextAttribute (screen, 140);
		cout<<"\n 8.Exit";
		SetConsoleTextAttribute (screen, 139);
		cout<<"\n\n >> ";
		fflush(stdin);
		cin>>opc;
		
		SetConsoleTextAttribute (screen, 143);
		switch(opc){
			case 1:
				p = (p == NULL)? Crea_Final() : Inserta_Final(p);
			break;

			case 2:
				if (p != NULL)
					Depositar_Cuenta(p);
				else
					Imprime_Cuentas(p, 'l');
			break;

			case 3:
				if (p != NULL)
					Retirar_Cuenta(p);
				else
					Imprime_Cuentas(p, 'l');
			break;
			
			case 4:
				if(p != NULL)	
					Consultar_Cuenta(p);
				else			
					Imprime_Cuentas(p, 'l');
			break;

			case 5:		Imprime_Cuentas(p, 'l');		break;

			case 6:		Imprime_Cuentas(c, 'c');		break;

			case 7:
				if(p != NULL)
					p = Eliminar_Cuenta(p, &c);
				else			
					Imprime_Cuentas(p, 'l');
			break;
			
			default: Guardar_Cuentas(p, c);
		}getch();
	} while (opc != 8);
return 0;
}
