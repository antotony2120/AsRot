#ifndef VECTOR3D_H
#define VECTOR3D_H

#include<utility>

#include"point.h"

class Point;

typedef std::pair<Point*, Point*> VECT;

class Vector3d
{
private:
   VECT vec;
public:
    Vector3d();
    Vector3d(const Point& point1, const Point& point2);
    Vector3d(const Vector3d& vector);
    ~Vector3d();

    Point& direction() const;
    Vector3d& rotation(const Point& r, const double w);
    Vector3d& rotation(const Vector3d& vecr, const double w);
};

#endif // VECTOR3D_H
