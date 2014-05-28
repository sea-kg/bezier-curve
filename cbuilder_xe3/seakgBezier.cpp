// ---------------------------------------------------------------------------

#pragma hdrstop

#include "seakgBezier.h"

// ---------------------------------------------------------------------------
#pragma package(smart_init)

// helper class
coordPoint::coordPoint() : x(0), y(0) {
};

// --------------------------------------------------------------------

coordPoint::coordPoint(double X, double Y) : x(X), y(Y) {
};

void coordPoint::setXY(double X, double Y) {
	x = X;
	y = Y;
};

// --------------------------------------------------------------------

void coordPoint::setX(double X) {
	x = X;
};

// --------------------------------------------------------------------

void coordPoint::setY(double Y) {
	y = Y;
};

// --------------------------------------------------------------------

double coordPoint::getX() {
	return x;
};

// --------------------------------------------------------------------

double coordPoint::getY() {
	return y;
};

// --------------------------------------------------------------------

double coordPoint::lengthTo(double X, double Y) {
	double dX = X - x, dY = Y - y;
	if ((dX == 0) && (dY == 0))
		return 0;
	return sqrt(dX*dX + dY*dY);
};

// --------------------------------------------------------------------

double coordPoint::lengthTo(coordPoint p) {
	return lengthTo(p.getX(), p.getY());
};

// --------------------------------------------------------------------

coordPoint coordPoint::midpointLine(coordPoint toPoint) {
	coordPoint point;
	point.setX((toPoint.getX() - x) / 2.0 + x);
	point.setY((toPoint.getY() - y) / 2.0 + y);
	return point;
};

// --------------------------------------------------------------------

// impl class
std::vector<coordPoint>seakgBezier::getVectorBezier() {
	return dest;
};

// --------------------------------------------------------------------

bool seakgBezier::calculate(std::vector<coordPoint> &points, int max) {
	if (points.size() < 2)
		return false;
	dest.clear();
	recurs(points, 0, max);
	return true;
};

// --------------------------------------------------------------------

void seakgBezier::recurs(std::vector<coordPoint>points, int sch, int max) {
	if (sch <= max) {
		std::vector<coordPoint>left, right, buf1, buf2;
		// remember points from source vector
		left.push_back(points[0]);
		right.push_back(points[points.size() - 1]);
		// calculate middle points
		unsigned int pointsSize = points.size();
		for (unsigned int i = 1; i < pointsSize; i++) {
			buf2.clear();
			for (unsigned int b1 = 0; b1 < points.size() - 1; b1++)
				buf2.push_back(points[b1].midpointLine(points[b1 + 1]));
			// remember side points
			left.push_back(buf2[0]);
			right.push_back(buf2[buf2.size() - 1]);
			// copy from buf2 to points
			points.clear();
			for (unsigned int i = 0; i < buf2.size(); i++)
				points.push_back(buf2[i]);
		};
		// inverting vector
		buf2.clear();
		for (unsigned int i = 0; i < right.size(); i++)
			buf2.push_back(right[right.size() - i - 1]);
		// call recursion
		sch++;
		recurs(left, sch, max);
		recurs(buf2, sch, max);
	}
	else {
		// записываем результат
		for (unsigned int i = 0; i < points.size(); i++)
			dest.push_back(points[i]);
	};
};
