#pragma once
#include "Shape.h" 


class Rectangle : public Shape { 
public:
	Rectangle(double inX,double inY,double inWidth,double inHeight);

	// I've overridden the area() method here, just like I did in Circle.  
	virtual double area();
	virtual double getWidth() const;
	virtual double getHeight() const;
	
	virtual void resize(double inWidth, double inHeight);
	virtual void print();


private:  // ...and two new data members  
	double width;  
	double height; 
};