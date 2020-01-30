#pragma once
#include <iostream>
using namespace std;

class Shape {
private:
	double area;
public:
	Shape() :area(0) {};
	Shape(double);
	double getArea()const;
	void setArea(double);
	void print();

};