/*
	escribir un programa que haga uso de dos funciones: 

-1.carga (declarada y llamada dentro de main):
	solicitar al usuario el nombre y la edad(deve ser retornados al main). 

-2.convertir a binario (declarada y llamada dentro de main):
	tomara la edad y la convertira e imprimira en binario.
*/

#include "all.h"

string nombre;
int main(){
	int edad;
int carga(void);	
void convertir(int);

	edad=carga();
	system("cls");
		cout<<"\n joven "<<nombre<<" su edad en decimal es: "<<edad;	
	convertir(edad);

return 0;
}

int carga(void){
	
	int edad;
	cout<<"\n ingrese el nombre: ";cin>>nombre;
	cout<<" ingrese su edad: ";cin>>edad;
	
return edad;	
}

void convertir(int edad){
	int binario[100],cant=0;
	int divisor=2,cociente,res;
	
		cout<<"\n";
	do{
			res=edad%divisor;
			binario[cant]=res;
			cociente=edad/divisor;	
	if(cociente>1){
			edad=cociente;
	}else{
		
			cant++;
			binario[cant]=cociente;
	
	}
	cant++;
	}while(cociente>1);
		cout<<" joven "<<nombre<<" su edad en binario es: ";
	for(int i=0;i<cant;i++){
		cout<<binario[i];
	}
		cout<<"\n orden correcto: ";
	for(int i=cant-1;i>=0;i--){
		cout<<binario[i];
	}
}
