#include<stdlib.h>

#ifndef FUNCIONES_H
#define FUNCIONES_H 

FILE *archivo;

//Arreglo de los paises
char Paises[32][30]=
{
      {"Equipos\\Alemania.txt"},
      {"Equipos\\ArabiaSaudita.txt"},
      {"Equipos\\Argentina.txt"},
      {"Equipos\\Australia.txt"},
      {"Equipos\\Belgica.txt"},
      {"Equipos\\Brasil.txt"},
      {"Equipos\\Colombia.txt"},
      {"Equipos\\CostaRica.txt"},
      {"Equipos\\Croasia.txt"},
      {"Equipos\\Dinamarca.txt"},
      {"Equipos\\Egipto.txt"},
      {"Equipos\\España.txt"},
      {"Equipos\\Francia.txt"},
      {"Equipos\\Inglaterra.txt"},
      {"Equipos\\Iran.txt"},
      {"Equipos\\Islandia.txt"},
      {"Equipos\\Japon.txt"},
      {"Equipos\\Marruecos.txt"},
      {"Equipos\\Mexico.txt"},
      {"Equipos\\Nigeria.txt"},
      {"Equipos\\Panama.txt"},
      {"Equipos\\Peru.txt"},
      {"Equipos\\Polonia.txt"},
      {"Equipos\\Portugal.txt"},
      {"Equipos\\RepublicaDeCorea.txt"},
      {"Equipos\\Rusia.txt"},
      {"Equipos\\Senegal.txt"},
      {"Equipos\\Serbia.txt"},
      {"Equipos\\Suecia.txt"},
      {"Equipos\\Suiza.txt"},
      {"Equipos\\Tunez.txt"},
      {"Equipos\\Uruguay.txt"},
};


void LeerArchivo(Equipo equipos[32])
{
    for (int i = 0; i < 32; ++i)
      {
            archivo = fopen(Paises[i],"r+");

            if (archivo == NULL)
            {
                  printf("\n No se leyo el archivo [%s]",Paises[1]);
            }else{
                  while(feof(archivo) == 0)
                  {     
                        fscanf(archivo,"%s",&equipos[i].nombreEquipo);
                        fscanf(archivo,"%s",&equipos[i].grupo);
                        fscanf(archivo," %[^\n]",&equipos[i].nombreTecnico);
                        for (int k = 0; k < MAXJGD; ++k)
                        {
                              fscanf(archivo,"%s",&equipos[i].jugadores[k].nombre);
                              fscanf(archivo,"%i",&equipos[i].jugadores[k].camiseta);
                        }   
                  }
            }

            fclose(archivo);
            archivo = NULL;
      }  
}


#endif
