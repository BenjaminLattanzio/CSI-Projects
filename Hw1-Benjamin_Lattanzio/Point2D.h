#pragma once
class Point2D {
private:
	int x;
	int y;
public:
	Point2D() :x(0), y(0) {};//default constructor
	Point2D(int, int);
	 int getPointX()const;
	 int getPointY()const;
	 bool equal(Point2D);
	 void setPointX(int);
	 void setPointY(int);
	 void print();
};