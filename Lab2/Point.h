#pragma once
class Point {
private:
	int x;
	int y;
public:
	Point() :x(0), y(0) {};//default constructor
	Point(int, int);
	 int getPointX()const;
	 int getPointY()const;
	 bool equal(Point);
	 void setPointX(int);
	 void setPointY(int);
	 void print();
};