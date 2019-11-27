#include<iostream>
using namespace std;

int main()
{
	int	matrices[2][3][2];
	
	matrices[0][0][0] = 2;
	matrices[0][0][1] = 3;
	matrices[0][1][0] = 4;
	matrices[0][1][1] = 5;
	matrices[0][2][0] = 6;
	matrices[0][2][1] = 7;
	matrices[1][0][0] = 8;
	matrices[1][0][1] = 9;
	matrices[1][1][0] = 10;
	matrices[1][1][1] = 11;
	matrices[1][2][0] = 12;
	matrices[1][2][1] = 13;
	    
	//mostrando matriz 3D
 	for(int i=0; i < 2; i++)
	 for(int j=0; j < 3; j++)
	  for(int k=0; k < 2; k++)
		cout<<"\tmatrices["<<i<<"]["<<j<<"]["<<k<<"]= "<<matrices[i][j][k]<<endl;
		
	return(0);
}