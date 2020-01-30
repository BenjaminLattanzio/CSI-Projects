#include "Circle.h"
#include "Point.h"
#include"Shape.h"
#include<cmath>
#include <iostream>

using namespace std;

Circle::Circle(Point& point, double inRadius) 
{
	radius = inRadius;
	center = point;
}; //constructor initializer
int Circle::getPointX() {
	return center.getPointX();
}
int Circle::getPointY() {
	return center.getPointY();
}


double Circle::getRadius()const {
	return radius;
}

void Circle::setRadius(double inRadius) {
	radius = inRadius;
}

void Circle::calculate_area() {//finding area of circle
	
	double pi = 3.14;
	setArea(pi * (radius*radius));
	
}
bool Circle::equal(Circle inCircle) {//checking if the radius of two circles are equal
	bool check = false;
	if (radius == inCircle.getRadius())
		check = true;

	return check;
}




void Circle::print() {//printing out radius and calling other prints.
	cout << "The radius of the circle is: " << radius << endl;
	Shape::print();
	center.print();
}