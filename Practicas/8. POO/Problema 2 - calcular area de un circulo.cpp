#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
using namespace std;

class Circle
{
	private:
		double radius;
	public:
		void setRadius(double);
		double getArea();
}circle1, circle2;

void Circle::setRadius(double r) { radius = r; }
double Circle::getArea() { return 3.14 * pow(radius, 2); }

int main()
{
	double rad1, rad2;
	
	cout<<"\n radio 1: ";cin>>rad1;
	cout<<" radio 2: ";cin>>rad2;

	circle1.setRadius(rad1);
	circle2.setRadius(rad2);

 	cout<<"\n El area del circulo 1 es " << circle1.getArea() <<"\n"
 		<<" El area del circulo 2 es " << circle2.getArea() <<"\n"; 
	
	return 0;
}