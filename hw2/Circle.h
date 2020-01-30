#pragma once
#include "Shape.h"


// Circle.h // Contains the declaration (but not the definition!) of the Circle class. 

 #include "Shape.h" 

class Circle : public Shape {
public:    Circle(double positionX,double positionY, double radius );

		   virtual double area();
		   virtual double getRadius();  
		   virtual void resize(double radIN);

		   // override all virtual functions from Shape class 
		 
		   virtual void print();

private: 
	double radius;
};
