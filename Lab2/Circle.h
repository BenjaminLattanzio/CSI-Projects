#pragma once
#include "Point.h"
#include "Shape.h"
class Circle : public Shape {
private:
	double radius;
	Point center;
public:
	Circle() :radius(0) {};//default constructor
	Circle(Point&, double);
	void calculate_area();
	double getRadius()const;
	void setRadius(double);
	bool equal(Circle);
	void print();

	int getPointX();
	int getPointY();

};