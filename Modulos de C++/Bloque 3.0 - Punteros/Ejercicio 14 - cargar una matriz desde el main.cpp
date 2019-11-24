#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;

int main()
{
    int nf = 0, nc = 0; 
    int matriz[4][4];
    void carga(int [][4],int *,int *);
    void imprime(int [][4], int, int);

    carga(matriz, &nf, &nc);
    system("cls");
    imprime(matriz, nf, nc);
    getchar();

    return 0;
}

void carga(int matriz[4][4], int *nf, int *nc)
{
    cout<<"\n ingrese el numero de filas: ";cin>>*nf;
    cout<<" ingrese el numero de columnas: ";cin>>*nc;
    cout<<endl;
    for (int i = 0; i < *nf; ++i)
        for (int j = 0; j < *nc; ++j)
            cin>>matriz[i][j];
}

void imprime(int matriz[4][4], int nf, int nc)
{
    cout<<"\n matriz: \n\n";
    for (int i = 0; i < nf; ++i)
    {
        for (int j = 0; j < nc; ++j)
            cout<<" "<<matriz[i][j];

        cout<<endl;
    }
}