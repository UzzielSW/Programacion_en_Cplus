// Solo funciona en windows
#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

struct userInfo
{
	string name;
	int age;
	char gender;
};

void placeCursor(HANDLE, int, int);
void displayPrompts(HANDLE);
void getUserInput(HANDLE, userInfo &);
void displayData(HANDLE, userInfo);

int main()
{
	system("cls");
	userInfo input;
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);

	displayPrompts(screen);
	getUserInput(screen, input);
	displayData(screen, input);

	return 0;
}

void placeCursor(HANDLE screen, int row, int col)
{
	COORD position;
	position.Y = row;
	position.X = col;
	SetConsoleCursorPosition(screen, position);
}

void displayPrompts(HANDLE screen)
{
	placeCursor(screen, 3, 25);
	cout << "******* Ingrese sus datos *******" << endl;

	placeCursor(screen, 5, 25);
	cout << "Nombre: " << endl;

	placeCursor(screen, 7, 25);
	cout << "Edad: 		 Genero(M/F): " << endl;
}

void getUserInput(HANDLE screen, userInfo &input)
{
	placeCursor(screen, 5, 33);
	getline(cin, input.name);

	placeCursor(screen, 7, 31);
	cin >> input.age;

	placeCursor(screen, 7, 54);
	cin >> input.gender;
}

void displayData(HANDLE screen, userInfo input)
{
	placeCursor(screen, 10, 2);
	cout << "Sus datos son: \n";
	cout << "Nombre : " << input.name << endl;
	cout << "Edad : " << input.age << endl;
	cout << "Genero: " << input.gender << endl;
}