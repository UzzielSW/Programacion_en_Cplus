#include <iostream>
#include <conio.h>
using namespace std;

struct Datos_arbol_genealogico {
	string nombre;
	int fecha_nacimiento;
	struct Datos_arbol_genealogico *li;
	struct Datos_arbol_genealogico *ld;
};

typedef struct Datos_arbol_genealogico NodoArbol;

int main ()
{
	NodoArbol *Raiz;
	Raiz= new NodoArbol();

	//Funciones
	void crea_arbol(NodoArbol *);
	void impre_pre(NodoArbol *);
	void impre_ino(NodoArbol *);
	void impre_pos(NodoArbol *);

	//LLamados
	crea_arbol (Raiz);
	
	cout<<"\n imprecion en preorden";
	impre_pre(Raiz);
	
	cout<<"\n imprecion en inorden ";
	impre_ino(Raiz);
	
	cout<<"\n imprecion en posorden ";
	impre_pos (Raiz);
	
	getch();
return 0;
}

void crea_arbol(NodoArbol *Raiz)
{
	int opc;
	
	cout<<"\n ingrese el nombre y la fecha de naciomiento: "<<endl;
	cin >> Raiz->nombre >> Raiz->fecha_nacimiento;
	
	cout <<"\n desea un nodo por la izquierda   1=si  0=no "<< Raiz->nombre <<endl;
	cin>>opc;
	
	if (opc == 1)
	{
		NodoArbol *otro = new NodoArbol();
		Raiz->li = otro;
		crea_arbol(Raiz->li);
	
	}else	Raiz->li = NULL;
	
	
	cout <<"\n desea un nodo por la derecha  1=si  0=no "<< Raiz->nombre <<endl;  
	cin>>opc;

	if (opc == 1)
	{
		NodoArbol *otro = new NodoArbol();
		Raiz->ld = otro;
		crea_arbol(Raiz->ld);
	
	}else	Raiz->ld = NULL;   
}


void impre_pre(NodoArbol *Raiz)
{
	if (Raiz != NULL)
	{ 
		cout<< Raiz ->nombre << " " << Raiz->fecha_nacimiento<<endl;
		impre_pre(Raiz->li);
		impre_pre(Raiz->ld);
	} 	
}


void impre_ino(NodoArbol *Raiz)
{
	if (Raiz != NULL)
	{ 
		impre_ino(Raiz-> li);
		cout<< Raiz->nombre << " " << Raiz->fecha_nacimiento <<endl;
		impre_ino(Raiz-> ld);
	} 
} 


void impre_pos(NodoArbol *Raiz)
{
	if (Raiz != NULL)
	{ 
		impre_pos(Raiz-> li);
		impre_pos(Raiz-> ld);
		cout<< Raiz->nombre << " " << Raiz->fecha_nacimiento <<endl;
	} 
}