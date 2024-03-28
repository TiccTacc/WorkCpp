#include "StandHeader.h"
#include "HeaderPoint.h"

int fPoints() {
	
	Point OnePoint, twoPoint;

	cout << "Enter the coordinates of the point (X Y). Example: 3 4 " << endl;
	cin >> OnePoint;
	cout << endl;

	cout << "Enter the coordinates of the second point (X Y). Example: 3 4 " << endl;
	cin >> twoPoint;
	cout << endl;

	int pointQuater = OnePoint.CoordinateQuarter();
	cout << "Quarter points: " << endl;
	if (pointQuater != 0) {
		cout << "The first point: " << pointQuater;
	}
	else {
		cout << "The first point lies on the axis. " << pointQuater;
	}

	pointQuater = twoPoint.CoordinateQuarter();
	if (pointQuater != 0) {
		cout << "The second point: " << pointQuater << endl;
	}
	else {
		cout << "The second point lies on the axis. " << pointQuater << endl;
	}

	if (OnePoint == twoPoint) {
		cout << "The points are equal." << endl;
	}
	else if (OnePoint != twoPoint) {
		cout << "The points are not equal" << endl;
	}

	double qOne, qTwo;

	cout << "Enter the coefficients for the equation of the straight line (y=kx+b) separated by a space." << endl;
	cin >> qOne >> qTwo;
	cout << endl;

	if (OnePoint.PointOnStraightLine(qOne, qTwo))
		cout << "The first point lies on a straight line" << endl;
	if (OnePoint.PointAboveStraightLine(qOne, qTwo))
		cout << "The first point lies above the straight line" << endl;
	if (OnePoint.PointUnderStraightLine(qOne, qTwo))
		cout << "The first point lies under a straight line" << endl;

	if (twoPoint.PointOnStraightLine(qOne, qTwo))
		cout << "The first point lies on a straight line" << endl;
	if (twoPoint.PointAboveStraightLine(qOne, qTwo))
		cout << "The first point lies above the straight line" << endl;
	if (twoPoint.PointUnderStraightLine(qOne, qTwo))
		cout << "The first point lies under a straight line" << endl;

	return 0;
}