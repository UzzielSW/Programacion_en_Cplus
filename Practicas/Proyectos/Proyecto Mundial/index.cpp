#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include "equipo.h"

int main()
{
	for(int iter = 0; iter < MAXEQ; iter++)
	{
		printf("\n----------------------------------------------------------------------\n");
		printf("\n equipo: %s",equipos[iter].nombreEquipo);
		printf("\t grupo: %c",equipos[iter].grupo);
		printf("\t tecnico: %s",equipos[iter].nombreTecnico);
		printf("\n Jugadores:");
		for(int i=0; i<23; i++)
		{
			printf("\n Jugador: %s", equipos[iter].jugadores[i].nombre);
			
			if (strlen(equipos[iter].jugadores[i].nombre)<14)
				printf("\t");
			
			printf("\tcamiseta: N[%d]",equipos[iter].jugadores[i].camiseta);
		}
		printf("\n");
	}	
	
	getchar();
	return 0;
}