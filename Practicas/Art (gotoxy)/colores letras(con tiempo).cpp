#include <iostream>
#include <time.h>
#include <windows.h">
using namespace std;

int main()
{ 
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE); 
		 
	// escribe 16 lines con colores diferentes. 
    for (int color = 7; color < 16; color++)  
	{
	    SetConsoleTextAttribute (screen, color); 
    	cout << " Hello World!" << endl; 
		Sleep(400); //pausa
 	} 
	  
	// restaura al color original
	SetConsoleTextAttribute(screen,7); 
 
	return 0; 
}