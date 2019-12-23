/*
	CAIDA LIBRE:
	Cuando un objeto esta cayendo debido a la gravedad, la siguiente formula puede ser utilizada para determinar la distancia que el 
	objeto cae en un periodo de tiempo especifico: 
	D = 1/2 g(t^2)
	las variables en la formula es como sigue: D es la distancia en metros, g es de 9,8, y t es la cantidad de tiempo en segundo,
	que el objeto ha estado cayendo. escribir una funcion llamada caida_libre que acepte tiempo de caida de un objeto como argumento.
	la funcion debe devolver la distancia, en metros, que el objeto ha caido durante ese intervalo de tiempo. escribir un programa 
	que demuestre la funcion llamandolo en un ciclo para valores de 1 al 10 y los imprima.
	
*/
#include <iostream>
#include <math.h>
using namespace std;

class Distancia
{
	private:
		int time;
	public:

		Distancia(int t) { setTime(t); }
		Distancia(){ time = 0; }

		void setTime(int t)
		{ 
			if(t >= 0)
				time = t; 
			else
			{
				do{
					cout<<"\n Tiempo incorrecto!\n";
					cout<<"\n Ingrese el tiempo nuevamente: ";
					cin>>t;
				}while(t < 0);

				time = t;
			}
		}

		float getdistancia(){ return 0.5 * 9.8 * pow(time, 2); }
};


int main()
{
	Distancia ball;

	cout<<"Distancias en el tiempo: D(t): "<<endl;
	for (int i = 1; i < 11; i++)
	{
		 ball.setTime(i);
		 cout<<"D("<<i<<"): "<< ball.getdistancia() <<" m"<< endl;
	}

	getchar();
	return 0;
}