/*4. Escriba un programa que tome cada 4 horas la temperatura exterior, 
ley�ndola durante un per�odo de 24 horas. Es decir, debe leer 6 temperaturas. 
Calcule la temperatura media del d�a, la temperatura m�s alta y la m�s baja.*/
#include<iostream>
using namespace std;

int main()
{
	float temperatura, suma_temperatura=0, temperatura_media;
	float temperatura_alta=0, temperatura_baja=999;
	
	for(int i=0; i < 24; i += 4) //vamos aumentando de 4 en 4 horas
	{ 
		cout<<"Digite la temperatura a las "<<i<<": ";
		cin>>temperatura;
		
		suma_temperatura += temperatura;
		
		if(temperatura > temperatura_alta)
			temperatura_alta = temperatura;
		else if(temperatura < temperatura_baja)
			temperatura_baja = temperatura;
	}
	
	temperatura_media = suma_temperatura / 6; //entre 6 porque son 6 temperaturas al dia
	
	cout<<"\nLa temperatura media del dia es: "<< temperatura_media
		<<"\nLa temperatura mas alta es: "<< temperatura_alta
		<<"\nLa temperatura mas baja es: "<< temperatura_baja;
	
	getchar();
	return 0;
}