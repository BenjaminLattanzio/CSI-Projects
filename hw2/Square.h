#pragma once
#include "Shape.h"

class Square : public Shape {
public:
	Square(double inX, double inY, double side);
	virtual void resize(double inSide);
	virtual double area();
	virtual void print();
	virtual double getWidth();


private:
	double side;
};