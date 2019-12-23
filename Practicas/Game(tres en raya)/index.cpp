/*
	// Reto: Juego de tres en raya
	// Autor: Brayan Puyol 
	// Date: 2017
*/
#include <iostream>
#include <stdlib.h>	
#include <conio.h>
#include <vector>
#include <iomanip>
#include <algorithm>
	#define TAMANIO 9
using namespace std;

void Play();

int arreglo[ TAMANIO ] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
vector< int > tres(arreglo, arreglo + TAMANIO);

int main()
{
	int opc;
	do{
		system("cls");
		cout<<"\t Juego tres en raya"
			<<"\n 1.Play"
			<<"\n 2.Salir"
			<<"\n\n >> ";
		cin>>opc;

		switch(opc){
			case 1:
				Play();
			break;

			case 2: break;
		}getch();
	}while(opc != 2);
return 0;
}

void Play()
{
	int turnos=1;
	int pos;
	int cont=0;
	int ref;
	bool ganas(int);

	do
	{	system("cls");
		cout<<"\n Turno Jugador " << ((turnos%2 != 0)? "1" : "2")<<endl<<endl;

		for (vector<int>::iterator i = tres.begin(); i != tres.end(); ++i)
		{
			cont++;
//			cout<<" "<<*i;
			if(*i == 1) cout<<" [X]";
			else if (*i == 2) cout<<" [O]";
			else cout<< " [ ]";
			
			if(cont%3==0) cout<<"\n";
		}

		cout<<"\n posicion: ";
		cin>>pos;
		
		if(turnos%2 == 0)
			tres.at(pos) = 2;
		else 
			tres.at(pos) = 1;

		ref = (turnos%2 != 0)? 1 : 2;

		if(ganas(ref)){
			system("cls");
			cout<<"\n Turno Jugador " << ((turnos%2 != 0)? "1" : "2")<<endl<<endl;
	
			for (vector<int>::iterator i = tres.begin(); i != tres.end(); ++i)
			{
				cont++;
				if(*i == 1) cout<<" [X]";
				else if (*i == 2) cout<<" [O]";
				else cout<< " [ ]";
			
				if(cont%3==0) cout<<"\n";
			}
			
			cout<<"\n Jugador "<< ((turnos%2 != 0)? "1" : "2") << " Winners";
			break;
		}
		
		turnos++;
		
		if(turnos == 10){
			system("cls");
			for (vector<int>::iterator i = tres.begin(); i != tres.end(); ++i)
			{
				cont++;
				if(*i == 1) cout<<" [X]";
				else if (*i == 2) cout<<" [O]";
				else cout<< " [ ]";
			
				if(cont%3==0) cout<<"\n";
			}
			
			cout<<"\n anyone's won";
		}
	} while (turnos!=10);
	getch();
	for(int i=0; i<9; i++) tres[i] = 0;
}


bool ganas(int ref)
{
	int veri=0;
	
	// diagonal principal
	for(int i=0; i<=8; i+=4)
	{
		if(tres[i] == ref)
			veri++;
	}

	if(veri == 3)
		return true;
	else
		veri = 0;
	
	// diagonal secundaria
	for(int i=2; i<=6; i+=2)
	{
		if(tres[i] == ref)
			veri++;
	}

	if(veri == 3)
		return true;
	else
		veri = 0;
	
	// vertical 1
	for(int i=0; i<=6; i+=3)
	{
		if(tres[i] == ref)
			veri++;
	}

	if(veri == 3)
		return true;
	else
		veri = 0;

	// vertical 2
	for(int i=1; i<=7; i+=3)
	{
		if(tres[i] == ref)
			veri++;
	}

	if(veri == 3)
		return true;
	else
		veri = 0;
	
	// vertical 3
	for(int i=2; i<=8; i+=3)
	{
		if(tres[i] == ref)
			veri++;
	}

	if(veri == 3)
		return true;
	else
		veri = 0;
	
	// horizontal 1,2,3
	for(int i=0; i<=8; i++)
	{
		if(i%3==0)
			veri = 0;

		if(tres[i] == ref)
			veri++;
		
		if(veri == 3)
			return true;
	}
		
return false;
}
