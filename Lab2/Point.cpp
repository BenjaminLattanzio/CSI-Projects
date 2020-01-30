#include "Point.h"
#include <iostream>

using namespace std;

Point::Point(int inX, int inY) { x = inX; y = inY; }//constructor initializer

int Point::getPointX()const {
	return x;
}

int Point::getPointY() const {
	return y;
}

void Point::setPointX(int inX) {
	x = inX;
}

void Point::setPointY(int inY) {
	y = inY;
}

bool Point::equal(Point inPoint) {//checking if the two points are equal to another
	bool check = false;

	if (x == inPoint.getPointX() && y == inPoint.getPointY())
		check = true;

	return check;
		

	
}

void Point::print() {//printing out the point
	cout << "The point is : (" << x << ',' << y << ')' << endl;

}