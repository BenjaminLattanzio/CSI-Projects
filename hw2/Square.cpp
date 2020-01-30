#pragma once
#include <iostream>
#include "Square.h"
using namespace std;

Square::Square(double inX, double inY, double side) :Shape(inX, inY) {
	side = side;
}

void Square::resize(double inSide) {
	side = inSide;
}

double Square::area() {
	return (side*side);
}
double Square::getWidth() {
	return side;
}

void Square::print() {
	cout << "X:" << getPositionX() << endl;
	cout << "Y:" << getPositionY() << endl;
	cout << "Width:" << side<< endl;
	cout << "Height:" << side << endl;
	
}