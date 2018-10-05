#ifndef POINT_H
#define POINT_H


class Point
{
private:
    double _x, _y, _z;
public:
    Point();
    Point(double _x, double _y, double _z);
    Point(Point& copypoint);
    ~Point();
    double x();
    double y();
    double z();
    Point& operator + (Point& move);
    Point& operator - (Point& move);
    Point& operator = (Point& copypoint);
};

#endif // POINT_H
