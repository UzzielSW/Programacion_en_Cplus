#ifndef EQUIPO_h
#define EQUIPO_H 
#define MAXEQ 3 //CANTIDAD DE EQUIPOS

struct Registro
{
	int ganados;
	int perdidos;
	int empatados;
	int goles_favor;
	int goles_contra;
	int puntos;
	int posicion_grupo;
};


struct Jugadores
{
	char nombre[30];
	int camiseta;
};


struct Equipo
{
	char grupo;
	char nombreEquipo[30];
	char nombreTecnico[30];
	Jugadores jugadores[23];
	Registro record;
};

Equipo equipos[MAXEQ] = 
{
	{//[0]
		'A', "Alemania", "Low Joachim",
		{
			{ "Manuel Neuer", 1},
			{ "Kevin Trapp", 12 },
			{ "Marc-Andre Ter Stegen", 22 },
			{ "Marvin Plattenhardt", 2 },
			{ "Jonas Hector", 3 },
			{ "Matthias Ginter", 4 },
			{ "Mats Hummels", 5 },
			{ "Niklas Suele", 15 },
			{ "Antonio Ruediger", 16 },
			{ "Jerome Boateng", 17 },
			{ "Joshua Kimmich", 18 },
			{ "Sami Khedira", 6 },
			{ "Julian Draxler", 7 },
			{ "Toni Kroos", 8 },
			{ "Mesut Oezil", 10 },
			{ "Thomas Mueler", 13 },
			{ "Leon Goretzka", 14 },
			{ "Sebastian Rudy", 19 },
			{ "Julian Brandt", 20 },
			{ "Ilkay Guendogan", 21 },
			{ "Timo Werner ", 9 },
			{ "Marco Reus", 11 },
			{ "Mario Gomez", 2}
		},
	},//[0]
	{ //[1]
		'A', "Arabia Saudita", "PIZZI Juan Antonio",
		{
			{ "ABDULLAH ALMUAIOUF", 1 },
			{ "YASSER ALMOSAILEM", 21 },
			{ "MOHAMMED ALOWAIS", 22 },
			{ "MANSOUR ALHARBI", 2 },
			{ "OSAMA HAWSAWI", 3 },
			{ "ALI ALBULAYHI", 4 },
			{ "OMAR HAWSAWI", 5 },
			{ "MOHAMMED ALBURAYK", 6 },
			{ "YASSER ALSHAHRANI", 13 },
			{ "MOTAZ HAWSAWI", 23 },
			{ "SALMAN ALFARAJ", 7 },
			{ "YAHIA ALSHEHRI", 8 },
			{ "HATAN BAHBRI", 9 },
			{ "ABDULMALEK ALKHAIBRI", 11 },
			{ "MOHAMED KANNO", 12 },
			{ "ABDULLAH OTAYF", 14 },
			{ "ABDULLAH ALKHAIBARI", 15 },
			{ "HUSSAIN ALMOQAHWI", 16 },
			{ "TAISEER ALJASSAM", 17 },
			{ "SALEM ALDAWSARI", 18 },
			{ "MOHAMMED ALSAHLAWI", 10 },
			{ "FAHAD ALMUWALLAD", 19 },
			{ "MUHANNAD ASIRI", 20 }
		},
	},//[1]
	{
	 	'D', "Argentina", "Sampaili_Jorge",
		{ "Nahuel_Guzman", 1 },
		{ "Franco_Armani", 12 },
		{ "Wilfredo_Caballero", 23 },
		{ "Gabriel_Mercado", 2 },
		{ "Nicolas_Tagliafico", 3 },
		{ "Cristian_Ansaldi", 4 },
		{ "Federico_Fazio", 6 },
		{ "Marcos_Acuna", 8 },
		{ "Javier_Macherano", 14 },
		{ "Marcos_Rojo", 16 },
		{ "Nicolas_Otamendi", 17 },
		{ "Eduardo_Salvio", 18 },
		{ "Lucas_Biglia", 5 },
		{ "Ever_Banega", 7 },
		{ "Angel_Di_Maria", 8 },
		{ "Maximiliano_Meza", 13 },
		{ "Enzo_Perez", 15 },
		{ "Giovani_Lo_Celso", 20 },
		{ "Cristian_Pavon", 22 },
		{ "Gonzalo_Higuain", 9 },
		{ "Lionel_Messi", 10 },
		{ "Sergio_Aguero", 19 },
		{ "Paulo_Dybala", 21 },
	},
	{
		'C', "Australia ", "VAN MARWIJK BERT",
		{ "Mathew_Ryan", 1 },
		{ "Brad_Jones", 12 },
		{ "Danny_Vukovic", 18 },
		{ "Milos_Degenek", 2 },
		{ "James_Meredith", 3 },
		{ "Mark_Milligan", 5 },
		{ "Matthew_Jurman", 6 },
		{ "Aziz_Behich", 1 },
		{ "Joshua_Risdon", 19 },
		{ "Trent_Sainsbury", 20 },
		{ "Massimo_Luongo", 8 },
		{ "Aaron_Mooy", 13 },
		{ "Mile_Jedinak", 15 },
		{ "Jackson_Irvine", 22 },
		{ "Tom_Rogic", 23 },
		{ "Tim_Cahill", 4 },
		{ "Mathew_Leckie", 7 },
		{ "Tomi_Juric", 9 },
		{ "Robbie_Kruse", 10 },
		{ "Andrew_NabbouTt", 11 },
		{ "Jamie_Maclaren", 14 },
		{ "Daniel_Arzani", 17 },
		{ "Dimitrios_Petratos", 21},
	}
};

#endif