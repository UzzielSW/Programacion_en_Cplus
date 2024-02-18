// Los algoritmos fill, fill_n, generate y generate_n de la Biblioteca estandar.
#include <iostream>
#include <algorithm> // definiciones de los algoritmos
#include <vector>	 // definicion de la plantilla de clase vector
#include <iterator>	 // ostream_iterator
using namespace std;
char siguienteLetra(); // prototipo de la funcion generadora

int main()
{
	vector<char> chars(10);
	ostream_iterator<char> salida(cout, " ");
	fill(chars.begin(), chars.end(), '5'); // llena chars con 5s

	cout << " Vector chars despues de llenarlo con 5s:\n";
	copy(chars.begin(), chars.end(), salida);

	// llena los primeros cinco elementos de chars con As
	fill_n(chars.begin(), 5, 'A');

	cout << "\n\n Vector chars despues de llenar cinco elementos con As:\n";
	copy(chars.begin(), chars.end(), salida);

	// genera los valores para todos los elementos de chars con siguienteLetra
	generate(chars.begin(), chars.end(), siguienteLetra);

	cout << "\n\n Vector chars despues de generar las letras A-J:\n";
	copy(chars.begin(), chars.end(), salida);

	// genera valores para los primeros cinco elementos de chars con siguienteLetra
	generate_n(chars.begin(), 5, siguienteLetra);
	cout << "\n\n Vector chars despues de generar K-O para los primeros cinco elementos:\n";
	copy(chars.begin(), chars.end(), salida);
	cout << endl;
	return 0;
}

// funcion generadora que devuelve la siguiente letra (empieza con A)
char siguienteLetra()
{
	static char letra = 'A';
	return letra++;
}