/*4. Hacer un arreglo de estructura llamada atleta para N atletas que contenga los
siguientes campos: nombre, pa�s, numero_medallas. y devuelva los datos
(Nombre, pa�s) del atleta que ha ganado el mayor n�mero de medallas.*/
#include<iostream>
using namespace std;

struct Atleta
{
	char nombre[20];
	char pais[20];
	int n_medallas;
};

int main()
{
	int n_atletas, mayor = 0, posM = 0;
	Atleta atletas[100];

	cout<<"Digite el numero de atletas: ";
	cin>>n_atletas;
	
	//Pedimos los datos para N atletas
	for(int i=0; i < n_atletas; i++)
	{
		fflush(stdin);
		cout<<"Nombre: "; cin.getline(atletas[i].nombre, 20, '\n');
		cout<<"Pais: "; cin.getline(atletas[i].pais, 20, '\n');
		cout<<"Numero de Medallas: "; cin>>atletas[i].n_medallas;

		//Sacando el atleta con mayor numero de medallas
		if(atletas[i].n_medallas > mayor)
		{
			mayor = atletas[i].n_medallas;
			posM = i;
		}
		cout<<"\n";
	}
	
	cout<<"\nAtleta con mas medallas ganadas: \n"
		<<"\nNombre: "<<atletas[posM].nombre
		<<"\nPais: "<<atletas[posM].pais<<endl;
	
	getchar();
	return 0;
}