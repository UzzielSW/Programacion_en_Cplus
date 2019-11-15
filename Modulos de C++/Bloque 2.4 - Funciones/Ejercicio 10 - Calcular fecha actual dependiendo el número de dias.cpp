/*Ejercicio 10: Escriba una funci�n nombrada calc_a�os() que tenga un par�metro entero 
que represente el n�mero total de d�as desde la fecha 1/1/2000 y par�metros de referencia
nombrados a�o, mes y d�a. La funci�n es calcular el a�o, mes y d�a actual para el
n�mero dado de d�as que se le transmitan. Usando las referencias, la funci�n deber�
alterar en forma directa los argumentos respectivos en la funci�n que llama. Para este
problema suponga que cada a�o tiene 365 d�as y cada mes tiene 30 d�as.*/
#include<iostream>
using namespace std;

void calc_anios(int, int&, int&, int&);

int main()
{
	int totalDias, anio, mes, dia;
	
	cout<<"Digite el numero total de dias transcurridos: ";
	cin>>totalDias;
	
	calc_anios(totalDias, anio, mes, dia);
	 
	cout<<"Fecha Actual: "<<(dia + 1)<<"/"<<(mes + 1)<<"/"<<(anio + 2000)<<endl;
		
	getchar();
	return 0;
}

void calc_anios(int totalDias, int& anio, int& mes, int& dia)
{
	anio = totalDias / 365;
	totalDias %= 365;
	mes = totalDias / 30;
	dia = totalDias % 30;
}