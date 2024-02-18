#include <windows.h>
#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);	

	for(int i=1; i <= 254; i++)
	{
		SetConsoleTextAttribute (screen, i);
		cout<<"\n \t   .:Kang:.    "<<i;		
	}

	getch();
	return 0;
}