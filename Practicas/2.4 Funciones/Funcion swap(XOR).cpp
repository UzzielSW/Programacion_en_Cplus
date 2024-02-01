#include <iostream>
using namespace std;

int main()
{
	int num1 = 1;
	int num2 = 2;

	void swap_temp(int&, int&);
	void swap_xor(int&, int&);

	swap_temp(num1, num2);
	
	cout<<"\n swap temp ";
	cout<<"\n num1: "<<num1;
	cout<<"\n num2: "<<num2;

	swap_xor(num1, num2);

	cout<<"\n swap xor ";
	cout<<"\n num1: "<<num1;
	cout<<"\n num2: "<<num2;

	return 0;
}

void swap_temp(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void swap_xor(int &a, int &b)
{
	a ^= b;
	b ^= a;
	a ^= b;
}