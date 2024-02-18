#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

#define cal(a, b, c) (b-a)/c
#define fun1(x, y) x-y
#define fun2(x, y) ((x==y)? 1: 0)
#define fun3(x, y) x+y
#define fun4(x, y) ((x<=y)? y: x)
#define fun5(x, y) x*y
#define fun6(x, y) abs(x-y)

#define EL printf("\n")
#define pb push_back
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FORD(i,r,l) for (int i=r;i>=l;i--)

int main()
{
    // MACROS PREDEFINIDAS
	cout<<" ubicacion del archivo: "<<__FILE__<<endl
		<<" numero de linea: "<<__LINE__<<endl
		<<" fecha: "<<__DATE__<<endl
		<<" hora: "<<__TIME__<<endl;

    // putchar('\n');
    // for (int i=1; i <= 6; i++) {
    //     for (int k=1; k <= 6; k++){
    //         printf("%4d ", fun6(i, k));
    //     }
    //     printf("\n");
    // }

    // lo mismo que lo de arriba pero usando macros
    EL;
    FOR(i, 1, 6)
    {
        FOR(j, 1, 6)
        {
            printf("%4d ", fun6(i, j));
        }
        EL;
    }

	// float va, vb, vc;
	// while(scanf("%f %f %f",&va, &vb, &vc))
	// {
	// 	printf("(%.1f-%.1f)/%.1f =  %.1f\n", vb, va, vc, cal(va, vb, vc));
	// }
	return 0;
}