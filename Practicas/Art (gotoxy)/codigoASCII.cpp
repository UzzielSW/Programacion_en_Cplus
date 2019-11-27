#include <iostream>
#include <stdlib.h>
#include <conio.h>
using namespace std;

int main()
{
	for(int i=33; i <= 253; i++)
	{
		cout<<char(i)<<" ["<<i<<"]\t\t";
		if(i % 5 == 0) cout<<endl;
	}

	getch();
	return 0;
}