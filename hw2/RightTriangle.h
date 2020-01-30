#pragma once

// RightTriangle.h // Contains the declaration (but not the definition!) of the RightTriangle // class, which inherits from Shape. 

#ifndef RIGHTTRIANGLE_H #define RIGHTTRIANGLE_H 

#include "Shape.h" 

class RightTriangle : public Shape {
public:  RightTriangle(double positionX, double positionY, double inWidth, double inHeight); 
		 virtual double area();
		 virtual double getWidth(); 
		 virtual double getHeight(); 
		 double getHypotenuseLength(); 
		 virtual void resize(double width, double height);
		 virtual void print();

private:
	
		double width;  
		double height;
};

#endif // RIGHTTRIANGLE_H 