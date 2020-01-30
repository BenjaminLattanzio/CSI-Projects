#pragma once
#include "Point2D.h"
class Circle : public Point2D{
private:
	double radius;
public:
	Circle() :radius(0) {};//default constructor
	Circle(int,int,double) ;
	double getRadius()const;
	void setRadius(double);
	double area();
	bool equal(Circle);
	void print();
	double distance();
	double distance(Circle);
};