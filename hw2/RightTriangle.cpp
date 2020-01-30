// RightTriangle.cpp // Contains the definition of the methods in RightTriangle. 
#pragma once
#include <cmath> 
#include "RightTriangle.h" 
#include <iostream>
using namespace std;

RightTriangle::RightTriangle(double positionX, double positionY, double inWidth, double inHeight):Shape(positionX,positionY) { 
	this->height = height;
	this->width = width;

}


double RightTriangle::area() {
	return width * height / 2;
}


double RightTriangle::getWidth() {
	return width; 
}


double RightTriangle::getHeight() { //add your code  
	return height;
}


double RightTriangle::getHypotenuseLength() {  
	return sqrt((height*height) + (width*width));
} 
	
void RightTriangle::resize(double inWidth,double inHeight) { 
	this->width = inWidth;
	this->height = inHeight;

	}

void RightTriangle::print() {
	cout << "X:" << getPositionX() << endl;
	cout << "Y:" << getPositionY() << endl;
	cout << "Width:" << width << endl;
	cout << "Height:" << height << endl;
	
}