/*
  -Tienes N zapatos, para cada una de ellas se conoce su tama�o y si se trata de una izquierda o una zapato derecho.
  -Cualquier zapato izquierdo se puede combinar con cualquier zapato derecho del mismo tama�o.
  - tienes que buscar �Cual es el numero maximo de pares se puede hacer?

La entrada estandar
 -La primera linea contiene un solo numero entero N .
 -Cada una de la siguiente N lineas describe un zapato.
 -La linea contiene un numero entero, que representa el tama�o de la zapatilla, seguido por un caracter: (L) en caso de un zapato izquierdo,
  o (R) en el caso de un zapato derecho.

la salida estandar:
 -Imprimir un solo numero entero que representa el numero maximo de pares de zapatos.

Limitaciones y notas:
	1 <= N <= 20

Las tallas de zapatos son numeros enteros entre 1 y 14.


Entrada	 Salida	  explicacion
5          2      Podemos hacer un par de tama�o (1 | 1) y uno de tama�o (3 | 3)
1 L
1 L
3 R
3 L
1 R
________ ________ __________________________________________________________________

4           0      No podemos hacer un par utilizando dos zapatos izquierdos.
2 L
2 L
2 L
3 R

________ ________ __________________________________________________________________

6           2
1 L
2 R
2 L
2 L
1 L
1 R

*/

#include "iostream"
using namespace std;

int main()
{

	int n, out, lef, rig, num, max, men;
	n = out = num = lef = rig = out = max = men = 0;
	char letter;
	int letraR[20], letraL[20];

	cin >> n;
	if ((n >= 1) && (n <= 20))
	{

		for (int i = 0; i < n; ++i)
		{
			std::cin >> num >> letter;
			std::cin.ignore(0, ' ');

			switch (letter)
			{
			case 'R':
				if (num >= 1 && num <= 14)
				{
					letraR[rig] = num;
					rig++;
				}
				break;
			case 'L':
				if (num >= 1 && num <= 14)
				{
					letraL[lef] = num;
					lef++;
				}
				break;
			default:
				break;
			}
		}

		if (rig > lef)
		{
			for (int i = 0; i < rig; ++i)
			{
				num = letraR[i];
				for (int k = 0; k < lef; ++k)
				{
					if (num == letraL[k])
					{
						letraL[k] = 0;
						out++;
						break;
					}
				}
			}
		}
		else
		{
			for (int i = 0; i < lef; ++i)
			{
				num = letraL[i];
				for (int k = 0; k < rig; ++k)
				{
					if (num == letraR[k])
					{
						letraR[k] = 0;
						out++;
						break;
					}
				}
			}
		}
		system("cls");
		cout << out;
	}

	return 0;
}
