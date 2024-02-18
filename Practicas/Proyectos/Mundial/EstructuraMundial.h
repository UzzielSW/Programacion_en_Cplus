#ifndef ESTRUCTURA_MUNDIAL_H
#define ESTRUCTURA_MUNDIAL_H 

// Librerias
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
//Constantes
#define MAXEQ 32 // numero maximo de equipos
#define MAXGRP 8 //numeor maximo de grupos
#define MAXEQPG 4 // maximo de equipos por grupo
#define MAXJUEGOS 64 //numero total de juegos del mundial
#define MAXJGD 23 //maximo de jugadores
//estructura contenedora de valores enteros


typedef struct 
{
	int npartido;
	char fecha[30];
	char hora[8];	
	char estadio[30];
	char paises[2][40];
}Partido;


typedef struct 
{
	char grupos[4];
	char equipos[4][40];
}Grupo;


Grupo COPMUN2018[8] =
{
  {
		{'A','A','A','A'},
		{"Uruguay","Rusia","ArabiaSaudita","Ejipto"}
  },

	{
		{'B','B','B','B'},
		{"España","Portugal","Iran","Marruecos"}
	},

	{
		{'C','C','C','C'},
		{"Fracia","Dinamarca","Peru","Australia"}
	},
	
  {
 		{'D','D','D','D'},
 		{"Croasia","Argentina","Nigeria","Islandia"}
  },

  {
 		{'E','E','E','E'},
 		{"Brasil","Suiza","Serbia","Costa Rica"}
  },

  {
 		{'F','F','F','F'},
 		{"Suecia","Mexico","RepublicaDeCorea","Alemania"}
  },
	
  {	
 		{'G','G','G','G'},
  		{"Belgica","Inglaterra","Tunez","Panama"}
  },

  {
 		{'H','H','H','H'},
     	{"Colombia","Japon","Senegal","Polonia"}
  },
	
}

Partido CAL2008 [MAXJUEGOS]={

  {
    1,
    "14 de junio 2018",
    "10hrs"
    "luzhniki",
    {"Rusia","ArabiaSaudita"}
  },

}
	
	
char grupovalido[MAXGRP]=
{
  'A','B','C','D','E','F','G','H'
}
	
	
#endif
