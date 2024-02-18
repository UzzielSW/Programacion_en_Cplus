/*Ejercicio 1: Construya una clase llamada Rectangulo que tenga los siguientes
atributos: largo y ancho,  y los siguientes metodos: Perimetro() y Area()*/
#include<iostream>
using namespace std;

class Rectangulo
{
	private: //Atributos
		float largo, ancho;
	public: //Metodos
		Rectangulo(float, float); //Constructor
		void Perimetro();
		void Area();
};

Rectangulo::Rectangulo(float _largo, float _ancho)
{
	largo = _largo;
	ancho = _ancho;
}

void Rectangulo::Perimetro()
{
	float _Perimetro = (2 * largo) + (2 * ancho);
	cout<<"El Perimetro es: "<<_Perimetro<<endl;
}

void Rectangulo::Area()
{
	cout<<"El area es: "<<(largo * ancho)<<endl;	
}

int main()
{
	Rectangulo r1(11, 7);
	
	r1.Perimetro();
	r1.Area();
	
	return 0;
}