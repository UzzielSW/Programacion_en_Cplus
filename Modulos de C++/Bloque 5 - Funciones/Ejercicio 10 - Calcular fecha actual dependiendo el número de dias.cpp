/*Ejercicio 10: Escriba una funcion nombrada calc_years() que tenga un parametro entero 
que represente el numero total de dias desde la fecha 1/1/2000 y parametros de referencia
nombrados year, mes y dia. La funcion es calcular el year, mes y dia actual para el
numero dado de dias que se le transmitan. Usando las referencias, la funcion debera
alterar en forma directa los argumentos respectivos en la funcion que llama. Para este
problema suponga que cada year tiene 365 dias y cada mes tiene 30 dias.*/
#include<iostream>
using namespace std;

void calc_years(int, int&, int&, int&);

int main()
{
	int totalDias, anio, mes, dia;
	
	cout<<"Digite el numero total de dias transcurridos: ";
	cin>>totalDias;
	
	calc_years(totalDias, anio, mes, dia);
	 
	cout<<"Fecha Actual: "<<(dia + 1)<<"/"<<(mes + 1)<<"/"<<(anio + 2000)<<endl;
		
	return 0;
}

void calc_years(int totalDias, int& anio, int& mes, int& dia)
{
	anio = totalDias / 365;
	totalDias %= 365;
	mes = totalDias / 30;
	dia = totalDias % 30;
}