#include <iostream>
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "RightTriangle.h"
#include "Square.h"
using namespace std;

void main() {

	Shape * sPointer[4];
	sPointer[0] = new Circle(5, 2, 7);
	sPointer[1] = new Rectangle(3, 9, 3, 15);
	sPointer[2] = new RightTriangle(22, 2,  9, 3);
	sPointer[3] = new Square(5, 3, 8);


	for (int i = 0; i < 4; i++) {
		sPointer[i]->print();
		cout << endl;
	}


	for (int i = 0; i < 4; i++) {
		cout <<"Area: " <<sPointer[i]->area();
		cout << endl;
	}

	//resize shape objects with values (2,3)
	//only works on Rtriangle and Rectangle
	for (int i = 0; i < 4; i++) {
		sPointer[i]->resize(3,2);
		cout << endl;
	}


	for (int i = 0; i < 4; i++) {
		sPointer[i]->print();
		cout << endl;
	}


	for (int i = 0; i < 4; i++) {
		cout << "Area: " << sPointer[i]->area();
		cout << endl;
	}


	for (int i = 0; i < 4; i++) {
		delete sPointer[i];
	}
	
	

	system("pause");
}