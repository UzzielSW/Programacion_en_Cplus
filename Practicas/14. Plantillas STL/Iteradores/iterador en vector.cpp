#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void imprime(int &x)
{
	cout << x << " -> ";
}

int main()
{
	vector<int> vect;

	for (int i = 0; i < 10; ++i)
	{
		vect.push_back(i * i);
	}

	vector<int>::iterator iter = vect.begin();

	// while(iter != vect.end())
	// {
	// 	cout<< *iter <<" ";
	// 	iter++;
	// }

	for_each(vect.begin(), vect.end(), imprime);

	getchar();
	return 0;
}