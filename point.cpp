#include "point.h"

Point::Point()
{
    this->_x = 0;
    this->_y = 0;
    this->_z = 0;
}

Point::Point(double _x, double _y, double _z){
    this->_x = _x;
    this->_y = _y;
    this->_z = _z;
}

Point::Point(Point& copypoint){
    this->_x = copypoint.x();
    this->_y = copypoint.y();
    this->_z = copypoint.z();
}

Point::~Point(){
    this->_x = 0;
    this->_y = 0;
    this->_z = 0;
}

double Point::x(){
    return this->_x;
}

double Point::y(){
    return this->_y;
}

double Point::z(){
    return this->_z;
}

Point& Point::operator + (Point& move){
    this->_x += move.x();
    this->_y += move.y();
    this->_z += move.z();
    return *this;
}

Point& Point::operator - (Point& move){
    this->_x -= move.x();
    this->_y -= move.y();
    this->_z -= move.z();
    return *this;
}

Point& Point::operator = (Point& copypoint){
    this->_x = copypoint.x();
    this->_y = copypoint.y();
    this->_z = copypoint.z();
    return *this;
}


int Point::rotate(Point& r, double w) // r - axis, w - angle
{
    double new_x = (pow(r.x(), 2.0) * (1 - cos(w)) + cos(w)) * this->_x + (r.x() * r.y() * (1 - cos(w)) - r.z() * sin(w)) * this->_y + (r.x() * r.z() * (1 - cos(w)) + r.y() * sin(w)) * this->_z;
    double new_y = (r.x() * r.y() * (1 - cos(w)) + r.z() * sin(w)) * this->_x + (pow(r.y(), 2.0) * (1 - cos(w)) + cos(w)) * this->_y + (r.y() * r.z() * (1 - cos(w)) - r.x() * sin(w)) * this->_z;
    double new_z = (r.x() * r.z() * (1 - cos(w)) - r.y() * sin(w)) * this->_x + (r.y() * r.z() * (1 - cos(w)) + r.x() * sin(w)) * this->_y + (pow(r.z(), 2.0) * (1 - cos(w)) + cos(w)) * this->_z;
    this->_x = new_x;
    this->_y = new_y;
    this->_z = new_z;
    return 1;
}
