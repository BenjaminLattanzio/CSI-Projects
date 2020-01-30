#include "Point2D.h"
#include <iostream>

using namespace std;

Point2D::Point2D(int inX, int inY) { x = inX; y = inY; }//constructor initializer

int Point2D::getPointX()const {
	return x;
}

int Point2D::getPointY() const {
	return y;
}

void Point2D::setPointX(int inX) {
	x = inX;
}

void Point2D::setPointY(int inY) {
	y = inY;
}

bool Point2D::equal(Point2D inPoint) {//checking if the two points are equal to another
	bool check = false;

	if (x == inPoint.getPointX() && y == inPoint.getPointY())
		check = true;

	return check;
		

	
}

void Point2D::print() {//printing out the point
	cout << "The point is : (" << x << ',' << y << ')' << endl;

}