#include "../include/point.hpp"
#include <istream>
#include <ostream>

Point::Point() : x(0.0), y(0.0){}

Point::Point(double x, double y) : x(x), y(y) {}

Point::Point(const Point& other) : x(other.x), y(other.y) {}

Point::Point(Point&& other) noexcept : x(other.x), y(other.y) {
    other.x = 0.0;
    other.y = 0.0;
}

Point::~Point() noexcept = default;

double Point::get_x() const{
    return this->x;
}

double Point::get_y() const{
    return this->y;
}

void Point::set_x(double x) {
    this->x = x;
}

void Point::set_y(double y){
    this->y = y;
}

Point Point::operator+(const Point& right) const{
    return Point(this->x + right.x, this->y + right.y);
}

Point Point::operator-(const Point& right) const{
    return Point(this->x - right.x, this->y - right.y);
}

Point Point::operator+=(const Point& right){
    this->x += right.x;
    this->y += right.y;
    return *this;
}

Point Point::operator-=(const Point& right){
    this->x -= right.x;
    this->y -= right.y;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Point& p){
    os << "(" << p.get_x() << ", " << p.get_y() << ")" << " ";
    return os;
}



std::istream& operator>>(std::istream& is, Point&p){
    double x, y;
    is >> x >> y;
    p.set_x(x);
    p.set_y(y);
    return is;
}