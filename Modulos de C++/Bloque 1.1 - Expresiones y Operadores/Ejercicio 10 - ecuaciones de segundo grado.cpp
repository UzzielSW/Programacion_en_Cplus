/*10. Escriba un programa que calcule las soluciones de una ecuacion de 
segundo grado de la forma ax^2 + bx + c = 0, teniendo en cuenta que: 
	x1 = (-b+sqrt(pow(b,2)-4*a*c))/(2*a) 
	x2 = (-b-sqrt(pow(b,2)-4*a*c))/(2*a)
*/
#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	float a,b,c, ver, resultado1, resultado2;
	
	cout<<"Digite el valor de a: "; cin>>a;
	cout<<"Digite el valor de b: "; cin>>b;
	cout<<"Digite el valor de c: "; cin>>c;
	
	ver = pow(b, 2) - (4 * a *c); //verificar la excepcion de tener una raiz con numero negativo
	if(ver < 0) {
		cout<<"\n Solucion con numeros imaginarios";
		return 1;
	}else if(a == 0){
		cout<<"\n No division entre cero";
		return 1;
	}

	resultado1 = (-b + sqrt(ver))/(2 * a);
	resultado2 = (-b - sqrt(ver))/(2 * a);
	
	cout<<"\nEl resultado 1 es: "<<resultado1
		<<"\nEl resultado 2 es: "<<resultado2;

	return 0;
}