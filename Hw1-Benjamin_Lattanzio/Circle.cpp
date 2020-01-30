#include "Circle.h"
#include "Point2D.h"
#include<cmath>
#include <iostream>

using namespace std;

Circle::Circle(int inX, int inY, double inRadius):Point2D(inX,inY) { radius = inRadius; }; //constructor initializer

double Circle::getRadius()const {
	return radius;
}

void Circle::setRadius(double inRadius) {
	radius = inRadius;
}

double Circle::area() {//finding area of circle
	double area = 0;
	double pi = 3.14;
	return area = pi * (radius*radius);
	
}
bool Circle::equal(Circle inCircle) {//checking if the radius of two circles are equal
	bool check = false;
	if (radius == inCircle.getRadius())
		check = true;

	return check;
}

double Circle::distance() {//finding distance from origin to circle
	double distance = 0;
	distance = sqrt((getPointX()*getPointX()) + (getPointY()*getPointY()));
	return distance;
}

double Circle::distance(Circle inCircle) {//finding distance between two circles
	double distance = 0;
	distance = sqrt(((inCircle.getPointX() - getPointX())*(inCircle.getPointX() - getPointX())) + ((inCircle.getPointY()-getPointY())*(inCircle.getPointY() - getPointY())));
	return distance;
}

void Circle::print() {//printing out radius and area
	cout << "The radius of the circle is: " << radius << endl;
	cout << "The area of the circle is: " << area() << endl;
}