#include "Cylinder.h"
#include"Point2D.h"
#include "Circle.h"
#include <iostream>

using namespace std;

Cylinder::Cylinder(int inX, int inY, double radius, double inHeight):Circle (inX,inY,radius) { height = inHeight; };//constructor initializer

double Cylinder::getHeight()const {
	return height;
}

void Cylinder::setHeight(double inHeight) {
	height = inHeight;
}
double Cylinder::area() {//finding area of cylinder
	double pi = 3.14;
	double area = 0;
	return area = (2 * pi*getRadius()*height) + (2 * pi*(getRadius()*getRadius()));
	
	
}
double Cylinder::volume() {//finding volume of cylinder
	double volume=0;
	double pi = 3.14;
	return volume = pi * (getRadius()*getRadius())*height;
}
bool Cylinder::equal(Cylinder inCylinder) {// checking if height and radius are equal between two cylinders
	bool check = false;
	if (height == inCylinder.getHeight() && getRadius() == inCylinder.getRadius())
		check = true;
	
	return check;
}

void Cylinder::print() {//printing out height area and volume
	cout << "The height of the cylinder is: " << height << endl;
	cout << "The area of the cylinder is: " << area() << endl;
	cout << "The volume of the cylinder is: " << volume() << endl;
}

