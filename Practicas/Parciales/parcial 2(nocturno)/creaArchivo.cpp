/*
	programa para generar archivo con la cantidad N de numeros en forma desordenada.
 */
#include <iostream>
#include <algorithm> // definiciones de algoritmos 
#include <numeric> // aqui se define accumulate
#include <vector>
#include <iterator>
#include <fstream>
using namespace std;

void escribir(string name, vector< int > arreglo, int cantidad)
{
	ofstream archivo;

	archivo.open(name.c_str(),ios::out); //Creamos el archivo
	
	if(archivo.fail()){ //Si a ocurrido algun error
		cout<<"No se pudo abrir el archivo";
		exit(1);
	}
	else
	{
		for (int i = 0; i < cantidad; ++i)
		{
			archivo << arreglo[i];
			if (i != cantidad-1)
				archivo<<" ";
		}		
		archivo.close();
	}
}

int main()
{
	int cant;
	string name;

	cout<<"\n Gernerador de archivos con numeros desordenados\n";
	cout<<"\n cantidad de numeros: ";
	cin>>cant;
	cout<<"\n nombre del archivo: ";
	getline(cin, name);

// -------------------------------------------------------------

	 int a1[ cant ];
	 ostream_iterator< int > salida( cout, " " );

	 for(int i = 0,aux = 1; i < cant; i++, aux++) a1[i] = aux;

	 vector< int > v( a1, a1 + cant ); // copia de a1

	 cout << " Vector v: ";
	 copy( v.begin(), v.end(), salida );

	 random_shuffle( v.begin(), v.end() ); // revuelve los elementos de v
	 cout << "\n Vector v despues de random_shuffle: ";
	 copy( v.begin(), v.end(), salida );

	 escribir(name, v, v.size());

	 fflush(stdin);
	 getchar();
return 0;
}

