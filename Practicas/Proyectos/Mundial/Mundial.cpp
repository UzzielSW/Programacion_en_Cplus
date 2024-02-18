/*
SEMESTRAL MUNDIAL
                   
Alexis Cunningham 8-940-1634
Jose Rodriguez  8-926-725

*/

#include "EstructuraMundial.h"
#include "Funciones.h"

int main()
{
	Equipo equipos[32]; //arreglo de los equipos
	
	LeerArchivo(equipos); //cargar los datos de los equipos
	
	//imprimir tods los equipos
	for (int i = 0; i < 32; ++i)
	{
		printf("\n--------------------------------------------------------------------\n");
		printf("\nEquipo: %s \t\tGrupo: %s", equipos[i].nombreEquipo, equipos[i].grupo);
		printf("\nTecnico: %s", equipos[i].nombreTecnico);
		for (int i = 0; i < MAXJGD; ++i)
		{
			printf("\nJugador: %s \t\t Camiseta: %i",equipos[i].jugadores[i].nombre, equipos[i].jugadores[i].camiseta);
		}   
	}
	


	return 0;
}
