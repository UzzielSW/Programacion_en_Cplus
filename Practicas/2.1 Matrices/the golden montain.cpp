#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int main()
{
	int size = 5;                                           
	//buscar la ruta en la cual la suma de la mayor cantidad moviendose solo en / o \ 
	// en este ejemplo es: 7 + 8 + 7 + 4 + 6 = 32
	int array[5][5] = {{7},
					  {3,8},
					 {8,1,7},
					{2,7,4,4},
				   {4,5,2,6,5}};
	
	for(int i = size - 2; i >= 0 ; i--)
		for(int k = 0; k <= i; k++)
			array[i][k] += max(array[i+1][k], array[i+1][k+1]); //funcion max(ini, fin) calcula el mayor en un arreglo

	cout<<" ruta maxima: "<<array[0][0];
	return 0;
}