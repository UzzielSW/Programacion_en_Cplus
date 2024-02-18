// Programa de prueba del adaptador priority_queue de la Biblioteca estándar.
#include <iostream>
#include <queue> // definición del adaptador priority_queue
using namespace std;
int main()
{
	priority_queue<double> prioridades; // crea un priority_queue

	cout << " insertando datos: ";
	// mete elementos en prioridades
	prioridades.push(3.2);
	cout << prioridades.top() << ' ';
	prioridades.push(9.8);
	cout << prioridades.top() << ' ';
	prioridades.push(5.4);
	cout << "5.4" << ' ';

	cout << "\n Sacando datos de prioridades: ";

	// saca elemento de priority_queue
	while (!prioridades.empty())
	{
		cout << prioridades.top() << ' '; // ve el elemento superior
		prioridades.pop();				  // elimina el elemento superior
	}

	cout << endl;
	return 0;
}
