//solo funciona en windows
#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;

void gotoxy(int x1, int y1)
{
	HANDLE hson = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	
	dwPos.X = x1;
	dwPos.Y = y1;

	SetConsoleCursorPosition(hson,dwPos);		
}

char opc;
int x = 10, y = 10;

int main()
{
	while(opc != 'z')
	{
		system("cls");
		gotoxy(x, y);
		cout<<"-|0--0|-";

		opc = getch();
		switch(opc)
		{
			case 'w': y--;break; //moverse arriba
			case 's': y++;break; //moverse abajo 
			case 'a': x--;break; //moverse izquierda
			case 'd': x++;break; //moverse derecha
		}
	}

	return(0);
}