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
