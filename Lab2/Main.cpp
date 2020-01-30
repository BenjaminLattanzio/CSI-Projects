#include <iostream>
#include "Circle.h"
#include"Point.h"
#include"RTriangle.h"
using namespace std;

double distance(Circle inCircle);//prototypes for functions
double distance(Circle inOne, Circle inTwo);



int main() {
	Point myPoint;//point objects
	Point myPoint2;
	RTriangle myTriangle;//triangle object

	myPoint.setPointX(2);//setting points
	myPoint.setPointY(4);
	myPoint2.setPointX(5);
	myPoint2.setPointY(9);
	myPoint.print();

	Circle myCircle(myPoint, 9.3);//cirle objects
	Circle myCircle2(myPoint2, 3.2);
	
	myCircle2.setRadius(7);//setting radius of circle and finding area
	myCircle.calculate_area();
	myCircle.print();

	myTriangle.setSide1(2);//setting sides of triangle and finding hypotenuse and area.
	myTriangle.setSide2(5);
	myTriangle.hyp();
	myTriangle.calculate_area();
	myTriangle.print();

	cout << "The distance from the origin to the circle is: " << distance(myCircle) << endl;
	cout << "The distance from the two circles is :" << distance(myCircle, myCircle2) << endl;




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