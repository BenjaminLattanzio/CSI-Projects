#include "RTriangle.h"
#include"Point.h"
#include "Circle.h"
#include"Shape.h"
#include <iostream>
#include <cmath>

using namespace std;

RTriangle::RTriangle(double area, double inSide1, double inSide2) :Shape(area) { side1 = inSide1; side2=inSide2; };//constructor initializer

double RTriangle::getSide1()const {
	return side1;
}

double RTriangle::getSide2()const {
	return side2;
}

void RTriangle::setSide1(double inSide1) {
	side1 = inSide1;
}
void RTriangle::setSide2(double inSide2) {
	side2 = inSide2;
}

double RTriangle::hyp() {//finding the hypotenuse
	double hypo = 0;
	return hypo = sqrt((getSide1()*getSide1()) + (getSide2()*getSide2()));
}

 void RTriangle::calculate_area() {//finding area of RTriangle

	double area = 0;
	setArea( ((getSide1()*getSide2())/2));
	
	
}


bool RTriangle::equal(RTriangle inRTriangle) {// checking if the sides are equal between two RTriangles
	bool check = false;
	if (side1 == inRTriangle.getSide1() && getSide2() == inRTriangle.getSide2())
		check = true;
	
	return check;
}

void RTriangle::print() {//printing out the hypotenuse
	cout << "The hypotenuse of the RTriangle is: " << hyp() << endl;
	Shape::print();
	
}

