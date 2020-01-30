#include <iostream>
#include "Circle.h"
#include"Point2D.h"
#include"Cylinder.h"
using namespace std;

double distance(Circle inCircle);//prototypes for functions
double distance(Circle inOne, Circle inTwo);



int main() {
	double distanceOne = 0;
	double distanceTwo = 0;
	Point2D* pointOne = new Point2D(3,3);//3 dynamic objects
	Circle* circleOne = new Circle(4,2,7);
	Cylinder* cylinderOne = new Cylinder(2,3,4,6);

	Point2D pointTwo(5, 2);//point and all methods
	Point2D pointThree(7, 3);
	pointTwo.setPointX(3);
	pointTwo.setPointY(5);
	pointTwo.equal(pointThree);
	pointTwo.print();

	Circle circleTwo(1,2,2.5);//circle and all methods
	Circle circleThree(5, 3, 7);
	circleTwo.setRadius(8);
	circleTwo.equal(circleThree);
	circleTwo.area();
	circleTwo.distance();
	circleTwo.distance(circleThree);
	distanceOne = distance(circleTwo);
	distanceTwo = distance(circleTwo, circleThree);
	circleTwo.print();
	

	Cylinder cylinderTwo(4,3,2,15);//cylinder and all methods
	Cylinder cylinderThree(4,3,2,3);
	cylinderTwo.setHeight(10);
	cylinderTwo.equal(cylinderThree);
	cylinderTwo.area();
	cylinderTwo.volume();
	cylinderTwo.print();


	Circle * pointerCircleArray[10];//three arrays of object pointers
	Point2D * pointerPoint[10];
	Cylinder * pointerCylinder[10];

	pointerCircleArray[0] = &circleTwo;// referencing objects
	pointerPoint[0] = &pointTwo;
	pointerCylinder[0] = &cylinderTwo;

	Circle circleArray[10];//three arrays of objects
	Point2D pointArray[10];
	Cylinder cylinderArray[10];

	system("pause");

	return 0;

}

double distance(Circle inCircle) {//non memeber-finding distance from origin to circle
	double distance = 0;
	distance = sqrt((inCircle.getPointX()*inCircle.getPointX()) + (inCircle.getPointY()*inCircle.getPointY()));
	return distance;
}

double distance(Circle inOne, Circle inTwo) {//non member-finding distance between two circles
	double distance = 0;
	distance = sqrt(((inTwo.getPointX() - inOne.getPointX())*(inTwo.getPointX() - inOne.getPointX())) + ((inTwo.getPointY() - inOne.getPointY())*(inTwo.getPointY() - inOne.getPointY())));
	return distance;

}