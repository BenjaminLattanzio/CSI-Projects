#include<iostream>
#include"Shape.h"
using namespace std;


Shape::Shape(double inArea) {
	area = inArea;
}
double Shape::getArea()const {
	return area;
}


void Shape::setArea(double inArea) {
	area = inArea;
 }
void Shape::print() {
	cout << "The area is :" << area << endl;
}