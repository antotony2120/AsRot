#ifndef POINT_H
#define POINT_H

#include<cmath>

#include"vector3d.h"

class Vector3d;

class Point
{
private:
    double _x, _y, _z;
public:
    Point();
    Point(const double _x, const double _y, const double _z);
    Point(const Point& copypoint);
    ~Point();

    double x() const;
    double y() const;
    double z() const;
    Point& operator + (const Point& move);
    Point& operator - (const Point& move);
    Point& operator = (const Point& copypoint);
    int rotate(const Point& axis, const double angle);
    int rotate(const Vector3d &vecr, const double w);
};

#endif // POINT_H
