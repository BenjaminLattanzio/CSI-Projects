#pragma once
#include "Circle.h"
#include "Cylinder.h"
class Cylinder: public Circle{
private:
	double height;
public:
	Cylinder() :height(0) {};//default constructor
	Cylinder(int,int,double, double);
	double area();
	double getHeight()const;
	double volume();
	void setHeight(double);
	bool equal(Cylinder);
	void print();
};