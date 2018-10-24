#include "vector3d.h"

Vector3d::Vector3d()
{
    this->vec = VECT(new Point(), new Point());
}

Vector3d::Vector3d(const Point& point1, const Point& point2){
    this->vec = VECT(new Point(point1), new Point(point2));
}

Vector3d::Vector3d(const Vector3d& vector){
    this->vec = VECT(new Point(*vector.vec.first), new Point(*vector.vec.second));
}

Vector3d::~Vector3d(){
    *(this->vec.first) = Point();
    *(this->vec.second) = Point();
    delete this->vec.first;
    delete this->vec.second;
    this->vec.first = nullptr;
    this->vec.second = nullptr;
}

Point& Vector3d::direction() const{
    Point* retp = new Point(*(this->vec.second) - *(this->vec.first));
    return *retp;
}

Vector3d& Vector3d::rotation(const Point &r, const double w){
    this->vec.first->rotate(r, w);
    this->vec.second->rotate(r, w);
    return *this;
}

Vector3d& Vector3d::rotation(const Vector3d& vecr, const double w){
    Point r = vecr.direction();
    this->vec.first->rotate(r, w);
    this->vec.second->rotate(r, w);
    return *this;
}
