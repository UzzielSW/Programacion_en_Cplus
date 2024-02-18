// Programa de prueba del adaptador queue de la Biblioteca estandar.
#include <iostream>
#include <queue> // definicion del adaptador queue
using namespace std;

int main()
{
	queue<double> valores; // cola con valores double

	cout << " metiendo datos de valores: ";
	// mete los elementos en la cola valores
	for (int i = 0; i <= 5; i++)
	{
		valores.push(i);
		cout << valores.back() << ' ';
	}

	cout << "\n Sacando datos de valores: ";
	// saca los elementos de la cola
	while (!valores.empty())
	{
		cout << valores.front() << ' '; // ve el elemento que esta al frente
		valores.pop();					// elimina el elemento
	}

	cout << endl;
	return 0;
}
