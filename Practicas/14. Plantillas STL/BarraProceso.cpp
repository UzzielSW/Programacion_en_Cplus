#include <iostream>
#include <stdio.h>
#include <vector>
#include <iterator>
using namespace std;

int main()
{

    vector<int> arr;
    vector<int>::iterator iter;

    printf("\nFase 1:"); // agregar valores a la lista
    for (int i = 0; i < 10; i++)
    {
        arr.push_back(i * i);
    }

    // imprimir vector
    for (iter = arr.begin(); iter != arr.end(); ++iter)
    {
        printf("\nn: %d", *iter);
    }

    printf("\n\nFase 2:"); // generar piramide
    for (int i = 0, j = 9; i < 10; i++, j--)
    {
        arr[i] = i * j;
    }

    // imprimir nuevo vector
    for (iter = arr.begin(); iter != arr.end(); ++iter)
    {
        printf("\nn: %d", *iter);
    }

    printf("\n\nFase 3:"); // imprimir barra
    for (iter = arr.begin(); iter != arr.end(); ++iter)
    {
        printf("\nbar: [");
        for (int k = 0; k < *iter; k++)
        {
            printf("#");
        }
        printf("]");
    }

    return 0;
}
