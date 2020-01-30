#pragma once
#include "Circle.h"
#include "Shape.h"
#include "RTriangle.h"
class RTriangle: public Shape{
private:
	double side1;
	double side2;
public:
	RTriangle() :side1(0),side2(0) {};//default constructor
	RTriangle(double, double,double);
	void calculate_area();
	double getSide1()const;
	double getSide2()const;
	double hyp();
	void setSide1(double);
	void setSide2(double);
	bool equal(RTriangle);
	void print();
};