//problemas para la solucion de problemas de matematica discreta
#include<iostream>
#include<stdlib.h>
using namespace std;

void permutaciones();
void combinaciones();

int main()
{
	int n=0, r, opc, na=0;
	int p=0, c=0;

	do{
		cout<<"\n\t1.permutaciones"
			<<"\n\t2.combinaciones"
			<<"\n\t3.salir"
			<<"\n\n\topcion: ";
		cin>>opc;

		switch(opc)
		{
			case 1: permutaciones(); break;
			case 2: combinaciones(); break;
		    case 3: cout<<"\nSaliendo"; break;
		}

		fflush(stdin);
		getchar();
		system("cls");
	}while(opc != 3);
	return 0;
}



void permutaciones()
{
	cout<<"\n ingrese los valores de la permutacion P(n,r): "<<endl;
	cout<<" n: "; cin>>n;
	cout<<" r: "; cin>>r;
	
	na = (n - r);
	
	if(n >= r)
	{
		switch(n)
		{
			case 12: n *= 11;
			case 11: n *= 10;
			case 10: n *= 9;
			case 9:  n *= 8;
			case 8:  n *= 7;
			case 7:  n *= 6;
			case 6:  n *= 5;
			case 5:  n *= 4;
			case 4:  n *= 3;
			case 3:  n *= 2;
			case 2:  n *= 1;
			case 1:  n *= 1; 	break;
			case 0:  n = 1; 	break;
		}
		
		
		switch(na)
		{
			case 10: na *= 9;
			case 9:  na *= 8;
			case 8:  na *= 7;
			case 7:  na *= 6;
			case 6:  na *= 5;
			case 5:  na *= 4;
			case 4:  na *= 3;
			case 3:  na *= 2;
			case 2:  na *= 1;
			case 1:  na *= 1; 	break;
			case 0:  na = 1; 	break;		
		}
		
		cout<<"el valor de na: "<<na<<endl;
		cout<<"el valor de n: "<<n<<endl;
		
		p = (n / na);
		
		cout<<"permutacion: "<<p<<endl;
	}
	else
		cout<<"\n no se puede realizar esta operacion";
}


void combinaciones()
{
	cout<<"\n ingrese los valores de la combinacion C(n,r): "<<endl;
	cout<<" n: ";	cin>>n;
	cout<<" r: ";	cin>>r;
		
	na = (n - r);
		
	if(n >= r >= 0)
	{
		switch(n)
		{
			case 12: n *= 11;
			case 11: n *= 10;
			case 10: n *= 9;
			case 9:  n *= 8;
			case 8:  n *= 7;
			case 7:  n *= 6;
			case 6:  n *= 5;
			case 5:  n *= 4;
			case 4:  n *= 3;
			case 3:  n *= 2;
			case 2:  n *= 1;
			case 1:  n *= 1; 	break;
			case 0:  n = 1; 	break;
		}
		
		
		switch(na)
		{
			case 10: na *= 9;
			case 9:  na *= 8;
			case 8:  na *= 7;
			case 7:  na *= 6;
			case 6:  na *= 5;
			case 5:  na *= 4;
			case 4:  na *= 3;
			case 3:  na *= 2;
			case 2:  na *= 1;
			case 1:  na *= 1; 	break;
			case 0:  na = 1; 	break;		
		}
		
		
		switch(r)
		{
			case 10: r *= 9;
			case 9:  r *= 8;
			case 8:  r *= 7;
			case 7:  r *= 6;
			case 6:  r *= 5;
			case 5:  r *= 4;
			case 4:  r *= 3;
			case 3:  r *= 2;
			case 2:  r *= 1;
			case 1:  r *= 1; break;
			case 0:  r = 1;  break;
		}

		c = (n / (na * r));
		
		cout<<"\n combinacion: "<<c<<endl;
	}
	else
		cout<<"\n no se puede realizar esta operacion";
}