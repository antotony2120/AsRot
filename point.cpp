#include "point.h"

Point::Point()
{
    this->_x = 0;
    this->_y = 0;
    this->_z = 0;
}

Point::Point(const double _x, const double _y, const double _z){
    this->_x = _x;
    this->_y = _y;
    this->_z = _z;
}

Point::Point(const Point& copypoint){
    this->_x = copypoint.x();
    this->_y = copypoint.y();
    this->_z = copypoint.z();
}

Point::~Point(){
    this->_x = 0;
    this->_y = 0;
    this->_z = 0;
}

double Point::x() const{
    return this->_x;
}

double Point::y() const{
    return this->_y;
}

double Point::z() const{
    return this->_z;
}

Point& Point::operator + (const Point &move){
    this->_x += move.x();
    this->_y += move.y();
    this->_z += move.z();
    return *this;
}

Point& Point::operator - (const Point& move){
    this->_x -= move.x();
    this->_y -= move.y();
    this->_z -= move.z();
    return *this;
}

Point& Point::operator = (const Point& copypoint){
    this->_x = copypoint.x();
    this->_y = copypoint.y();
    this->_z = copypoint.z();
    return *this;
}


int Point::rotate(const Point& r, const double w) // r - axis, w - angle
{
    double new_x = (pow(r.x(), 2.0) * (1 - cos(w)) + cos(w)) * this->_x + (r.x() * r.y() * (1 - cos(w)) - r.z() * sin(w)) * this->_y + (r.x() * r.z() * (1 - cos(w)) + r.y() * sin(w)) * this->_z;
    double new_y = (r.x() * r.y() * (1 - cos(w)) + r.z() * sin(w)) * this->_x + (pow(r.y(), 2.0) * (1 - cos(w)) + cos(w)) * this->_y + (r.y() * r.z() * (1 - cos(w)) - r.x() * sin(w)) * this->_z;
    double new_z = (r.x() * r.z() * (1 - cos(w)) - r.y() * sin(w)) * this->_x + (r.y() * r.z() * (1 - cos(w)) + r.x() * sin(w)) * this->_y + (pow(r.z(), 2.0) * (1 - cos(w)) + cos(w)) * this->_z;
    this->_x = new_x;
    this->_y = new_y;
    this->_z = new_z;
    return 0;
}

int Point::rotate(const Vector3d& vecr, const double w) // vecr - axis, w - angle
{
    Point r = vecr.direction();
    double new_x = (pow(r.x(), 2.0) * (1 - cos(w)) + cos(w)) * this->_x + (r.x() * r.y() * (1 - cos(w)) - r.z() * sin(w)) * this->_y + (r.x() * r.z() * (1 - cos(w)) + r.y() * sin(w)) * this->_z;
    double new_y = (r.x() * r.y() * (1 - cos(w)) + r.z() * sin(w)) * this->_x + (pow(r.y(), 2.0) * (1 - cos(w)) + cos(w)) * this->_y + (r.y() * r.z() * (1 - cos(w)) - r.x() * sin(w)) * this->_z;
    double new_z = (r.x() * r.z() * (1 - cos(w)) - r.y() * sin(w)) * this->_x + (r.y() * r.z() * (1 - cos(w)) + r.x() * sin(w)) * this->_y + (pow(r.z(), 2.0) * (1 - cos(w)) + cos(w)) * this->_z;
    this->_x = new_x;
    this->_y = new_y;
    this->_z = new_z;
    return 0;
}
