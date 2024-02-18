#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <list> // definicion de la plantilla de clase list
#include <algorithm>
#include <iterator> // iteradores
using namespace std;

template <typename T>
void imprimirLista(const list<T> &Lista);

int main()
{
	list<int> LISTA; // crea una lista de tipo int
	int opc, dato;
	int v;
	// char res;

	do
	{
		system("cls");
		printf("\n\t\t.: LISTAS de Plantillas STL :.");
		printf("\n\n\t1. Insertar al inicio\t\t\t[0]{Vaciar lista}");
		printf("\n\t2. Insertar al final");
		printf("\n\t3. Recorrer lista");
		printf("\n\t4. Eliminar al inicio");
		printf("\n\t5. Eliminar el ultimo");
		printf("\n\t6. Elimina X");
		printf("\n\t7. Invertir lista");
		printf("\n\t8. Ordenar lista ascendente");
		printf("\n\t9. Ordenar lista descendente");

		printf("\n\nopc? ");

		fflush(stdin);
		v = scanf("%d", &opc);
		fflush(stdin);
		if (!v)
			break;

		printf("\n");
		cout << "Actual: ";
		imprimirLista(LISTA);

		switch (opc)
		{
		case 0:
			LISTA.clear();
			break;
		case 1:
			cout << "\n Ingresar numero entero: ";
			if (cin >> dato)
				LISTA.push_front(dato);
			else
			{
				cin.clear();
				cout << "\n data error[!]";
			}
			break;

		case 2:
			cout << "\n Ingresar numero entero: ";
			if (cin >> dato)
				LISTA.push_back(dato);
			else
			{
				cin.clear();
				cout << "\n data error[!]";
			}
			break;

		case 3:
			imprimirLista(LISTA);
			break;

		case 4:
			if (LISTA.empty())
				cout << "\n operation pop_front error[!] | list:[]";
			else
				LISTA.pop_front();
			break;

		case 5:
			if (LISTA.empty())
				cout << "\n operation pop_back error[!] | list:[]";
			else
				LISTA.pop_back();
			break;

		case 6:
			if (LISTA.empty())
				cout << "\n operation remove X error[!] | list:[]";
			else
			{
				cout << "\n Ingresar numero entero que desea eliminar: ";
				if (cin >> dato)
					LISTA.remove(dato);
				else
				{
					cin.clear();
					cout << "\n data error[!]";
				}
			}
			break;

		case 7:
			LISTA.reverse();
			break;
		case 8:
			LISTA.sort();
			break;
		case 9:
			LISTA.sort();
			LISTA.reverse();
			break;

		default:
			break;
		}
		cout << "\nNueva: ";
		imprimirLista(LISTA);
		fflush(stdin);
		getchar();
	} while (true);
	return 0;
}

template <typename T>
void imprimirLista(const list<T> &Lista)
{
	if (Lista.empty()) // lista esta vacia
		cout << " Lista esta vacia! | list:[]";
	else
	{
		ostream_iterator<T> output(cout, ", ");
		cout << " [ ";
		copy(Lista.begin(), Lista.end(), output);
		cout << "]";
	}
}
