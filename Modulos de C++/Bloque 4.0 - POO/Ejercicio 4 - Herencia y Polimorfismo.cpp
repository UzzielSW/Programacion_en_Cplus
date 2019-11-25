/*Ejercicio 4: Crear un programa en C++ que tenga la siguiente jerarqu�a de
clases: Animal(Clase Padre) -> Humano(Clase Hija) -> Perro(Clase Hija),  
y hacer polimorfismo con el metodo Comer(). */
#include<iostream>
#include<stdlib.h>
using namespace std;

class Animal
{
	private: 
		int edad;
	public:
		Animal(int);
		virtual void Comer();
};

class Humano : public Animal
{
	private: 
		string nombre;
	public:
		Humano(int, string);
		void Comer();
};

class Perro : public Animal
{
	private: 
		string nombre, raza;
	public: 
		Perro(int, string, string);
		void Comer();
};

//Constructor de la clase Animal
Animal::Animal(int _edad)
{
	edad = _edad;
}

void Animal::Comer()
{
	cout<<"Yo como ";
}

//COnstructor de la clase Humano
Humano::Humano(int _edad, string _nombre) : Animal(_edad)
{
	nombre = _nombre;
}

void Humano::Comer()
{
	Animal::Comer();
	cout<<"en la mesa,  sentado en una silla"<<endl;
}

//Constructor de la clase Perro
Perro::Perro(int _edad, string _nombre, string _raza) : Animal(_edad)
{
	nombre = _nombre;
	raza = _raza;
}

void Perro::Comer()
{
	Animal::Comer();
	cout<<"en un plato,  en el suelo"<<endl;
}

int main()
{
	Animal *animales[2];
	
	animales[0] = new Humano(21, "Luis");
	animales[1] = new Perro(4, "Boby", "Pastor Aleman");
	
	animales[0]->Comer();
	animales[1]->Comer();	
	
	system("pause");
	return 0;
}