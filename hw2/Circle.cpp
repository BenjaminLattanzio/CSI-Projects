#include "Circle.h"
#include <iostream>
using namespace std;


// Circle.cpp // Contains the definitions of the methods of the Circle class.

Circle::Circle(double posX,double posY, double inRadius ):Shape(posX,posY) {        
	// Use the "this->" notation   
	this->radius = inRadius;
}


double Circle::area() {
	const double PI = 3.1415927;  return PI * radius * radius; }


double Circle::getRadius() {
	return radius;
}


void Circle::resize(double inRadius) { 
	this->radius = inRadius;
	this->area();
	}


void Circle::print() {
	cout << "X:" << getPositionX() << endl;
	cout << "Y:" << getPositionY() << endl;
	cout << "Radius:" << radius << endl;
	
};