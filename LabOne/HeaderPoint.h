#include "StandHeader.h"
//#include
#pragma once
using namespace std;

class Point
{
private:
	double x, y;
public:

	Point();
	Point(double newX, double newY);

	/* Функции сравнения */
	bool operator==(Point& pointCoordinate);
	bool operator!=(Point& pointCoordinate);

	/* Не стандартные функции */
	bool PointOnStraightLine(double onePoint, double twoPoint);
	bool PointAboveStraightLine(double onePoint, double twoPoint);
	bool PointUnderStraightLine(double onePoint, double twoPoints);
	int CoordinateQuarter();

	/* Функции ввода и вывода */
	friend ostream& operator<<(ostream& stringOut, const Point& CoordinatePoints);
	friend istream& operator>>(istream& stringIn, Point& cPoints);
};

Point::Point() {
	x = y = 0;
}
Point::Point(double newX, double newY) {
	x = newX;
	y = newY;
}

/* Функции сравнения */
bool Point::operator==(Point& pointCoordinate) {

	if (x == pointCoordinate.x 
		and y == pointCoordinate.y) {
		return true;
	}
	return false;
}

bool Point::operator!=(Point& pointCoordinate) {

	if (x != pointCoordinate.x
		and y != pointCoordinate.y) {
		return true;
	}
	return false;
}

/* Не стандартные функции */
bool Point::PointOnStraightLine(double onePoint, double twoPoint) {

	if ((onePoint * x + twoPoint) == y) {
		return true;
	}

	return false;

}
bool Point::PointAboveStraightLine(double onePoint, double twoPoint) {
	
	if ((onePoint * x + twoPoint) < y) {
		return true;
	}

	return false;

}
bool Point::PointUnderStraightLine(double onePoint, double twoPoint) {

	if ((onePoint * x + twoPoint) > y) {
		return true;
	}

	return false;

}
int Point::CoordinateQuarter() {

	int quarter = 0;
	if (x > 0 && y > 0)	{
		quarter = 1;
	}
	else if (x < 0 && y > 0) {
		quarter = 2;
	}
	else if (x < 0 && y < 0) {
		quarter = 3;
	}
	else if (x > 0 && y > 0) {
		quarter = 4;
	}
	return quarter;

}

/* Служебные функции */
ostream& operator<<(ostream& stringOut, const Point& cPoints) {

	stringOut << "Coordinate Points: X - " << cPoints.x << " Y - " << endl;
	return stringOut;
}
istream& operator>>(istream& stringIn, Point& cPoints) {

	stringIn >> cPoints.x >> cPoints.y;
	return stringIn;
}