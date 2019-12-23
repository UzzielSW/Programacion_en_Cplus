/*
	escribir un programa que haga uso de dos funciones: 

	-1.carga (declarada y llamada dentro de main):
	solicitar al usuario el nombre y la edad(deve ser retornados al main). 

	-2.convertir a binario (declarada y llamada dentro de main):
	tomara la edad y la convertira e imprimira en binario.
*/
#include <iostream>
using namespace std;

struct Person
{
	string nombre;
	int edad;
};

Person carga();
void convertir(Person);

int main()
{
	Person p1 = carga();

	cout<<"\n joven "<<p1.nombre<<" su edad en decimal es: "<<p1.edad;	
	convertir(p1);

	return 0;
}

Person carga()
{
	Person us;

	cout<<"\n ingrese el nombre: ";
	cin>>us.nombre;

	cout<<" ingrese su edad: ";
	cin>>us.edad;
	
	return us;	
}

void convertir(Person us)
{
	int binario[100], cant=0;
	int divisor = 2, cociente, res;
	int edad = us.edad;

	do{
		res = edad % divisor;
		binario[cant] = res;
		cociente = edad/divisor;	

		if(cociente > 1)
			edad = cociente;
		else
			binario[++cant] = cociente;

		cant++;
	}while(cociente > 1);
		
	//==============================================
	cout<<"\n joven "<<us.nombre<<" su edad en binario es: ";
	for(int i=0; i < cant; i++)
		cout<<binario[i];
		
	cout<<"\n orden correcto: ";
	for(int i = cant-1; i >= 0; i--)
		cout<<binario[i];
}