//solo funciona en windows
#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;

int main()
{
	void espacio(int n);
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE); 
	int color = 10;

	for(char letra = 'A'; letra <= 'Z'; letra += 2)
	{
		SetConsoleTextAttribute (screen, color); 
		espacio(letra - 'A');
		cout << letra << static_cast<char> (letra + 1) <<endl;
		color += 2; 
		if (color > 14) 
			color = 10;

		Sleep(280);
	}

	SetConsoleTextAttribute(screen, 7);

	return 0;
}

void espacio(int n)
{
	for (int espace = 1; espace <= n; espace++)
	cout <<" "; 
}