#include <iostream>
#include <regex>
using namespace std;

int main()
{
	regex patron("[0-9]+");
	string texto = {"uno1dos2tres3cuatro"};

	cout<<regex_replace(texto, patron, "\n");

	return 0;
}