// ---------------------------------------------------------------------------

#ifndef seakgBezierH
#define seakgBezierH
// ---------------------------------------------------------------------------
#include <math.h>
#include <vector>

// helper class
class coordPoint {
public:
	coordPoint();
	coordPoint(double X, double Y);
	void setXY(double X, double Y);
	void setX(double X);
	void setY(double Y);
	double getX();
	double getY();
	double lengthTo(double X, double Y);
	double lengthTo(coordPoint p);
	coordPoint midpointLine(coordPoint toPoint);

private:
	double x, y;
};

// impl class:
class seakgBezier {
public:
	std::vector<coordPoint>getVectorBezier();
	bool calculate(std::vector<coordPoint> &points, int max);

private:
	std::vector<coordPoint>dest;
	void recurs(std::vector<coordPoint>points, int sch, int max);
};

#endif
