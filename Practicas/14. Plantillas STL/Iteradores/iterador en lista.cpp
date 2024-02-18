#include <iostream>
#include <list> 
#include <algorithm>
using namespace std;

void imprime(int &x)
{
	cout<< x << " ";
}

int main()
{
	list <int> mylist;
	list <int> ::iterator iter;

	for(int i = 0; i < 10; i++)
		mylist.push_back(i);

	for_each(mylist.begin(), mylist.end(), imprime);
	cout<<"\n";

	mylist.reverse();
	for_each(mylist.begin(), mylist.end(), imprime);

	getchar();
	return 0;
}