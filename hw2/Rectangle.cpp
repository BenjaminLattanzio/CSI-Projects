#pragma once
#include <iostream>
using namespace std;
// Rectangle.cpp // Contains definitions of Rectangle's methods. 

#include "Rectangle.h" 

Rectangle::Rectangle(double inX, double inY, double inWidth,double inHeight):Shape(inX,inY)
{  // Use the "this->" notation 
		this->width = inWidth;
		this->height = inHeight;

	}

double Rectangle::area(){
	return width * height; 
}


double Rectangle::getWidth() const{  
	return this->width;
}


double Rectangle::getHeight() const {

	return this->height; 
}


void Rectangle::resize(double inWidth, double inHeight){ 
	this->width = inWidth;
	this->height = inHeight;
}

void Rectangle::print() {
	cout << "X:" << getPositionX() << endl;
	cout << "Y:" << getPositionY() << endl;
	cout << "Width:" << width << endl;
	cout << "Height:" << height << endl;
	
}