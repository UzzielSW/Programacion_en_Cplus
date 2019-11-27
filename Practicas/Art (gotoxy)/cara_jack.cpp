#include <iostream>
#include <time.h>
#include <windows.h>

void menu();
int eleccion_color();
void cara_jack();

int main()
{
 	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE); 
	const int salir = 6;
	int color;

 	do{  
 		SetConsoleTextAttribute(screen, 7); 

		menu();

		color = eleccion_color();

		if (color != salir)
		{  
			SetConsoleTextAttribute (screen, color + 9);
			cara_jack();
		}	

 	}while(color != salir);

	return 0;
}

void menu()
{  
	system("cls");  
	cout<< "I will draw a Jack-o-lantern. What color should it be?\n\n"
		<< "Enter 1 for Green     2 for Blue     3 for Red \n"
		<< "      4 for Purple    5 for Yellow   6 to salir: ";
}


int eleccion_color()
{
	int eleccion;
	cin >> eleccion;
	while (eleccion < 1 || eleccion > 6)
	{
		cout << "The only valid eleccions are 1-6.  Please re-enter. ";
		cin  >> eleccion;
	}

	return eleccion;
}

void cara_jack()
{
	cout << "\n\n";
	cout << "                            ^   ^  \n";
	cout << "                              *    \n";
	cout << "                            \\___/   " << endl;
	cout << "\n\n             Press ENTER to return to the menu." ;
	cin.get();     // Clear the previous \n out of the input buffer
 	cin.get();     // Wait for the user to press ENTER
}