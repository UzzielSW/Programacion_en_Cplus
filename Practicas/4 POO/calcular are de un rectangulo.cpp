#include <iostream>
using namespace std;

class Rectangle
{
	private:
		double length;
		double width;
	public:
		Rectangle()
		{
			length = 0;
			width = 0;
		}
		void setLength(double);
		void setWidth(double);
		double getLength();
		double getWidth();
		double getArea();
};


 void Rectangle::setLength(double len)
 {
 	length = (len >= 0) ? len : 1.0;
 }
 
 void Rectangle::setWidth(double w)
 {
 	width = (w >= 0) ? w : 1.0;
 }
 
 double Rectangle::getLength(){return length;}
 double Rectangle::getWidth(){return width;}
 double Rectangle::getArea(){return length * width;}
 
 int main(){
 	
 	Rectangle box; 
 	double alto, ancho;
 	
 	cout << " el programa calcula el area de un ractangulo.\n";
 	cout << " largo? ";
 	cin  >> alto;
 	cout << " ancho? ";
 	cin  >> ancho;
 	
 	box.setLength(alto);
 	box.setWidth(ancho);
 	
 	cout << "\nInformacion del rectangulo:\n";
 	cout << "Length: " << box.getLength() << endl;
 	cout << "Width : " << box.getWidth()  << endl;
 	cout << "Area  : " << box.getArea()   << endl;
 	
 	return 0;
}