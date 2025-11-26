#include "../include/triangle.hpp"
#include <cmath>

static double cross(const Point& a, const Point& b) {
    return a.get_x()*b.get_y() - a.get_y()*b.get_x();
}

static double dot(const Point& a, const Point& b) {
    return a.get_x()*b.get_x() + a.get_y()*b.get_y();
}

Triangle::Triangle() : Figure(3) {}

Point Triangle::getCenter() const {
    Point sum(0,0);
    for (size_t i = 0; i < size; ++i) sum += points[i];
    return Point(sum.get_x() / size, sum.get_y() / size);
}

bool Triangle::isCorrect() const {
    double area = static_cast<double>(*this);
    return std::fabs(area) > 1e-9;
}

Triangle::operator double() const {
    double s = 0.0;
    for (size_t i = 0; i < size; ++i) {
        const Point& p1 = points[i];
        const Point& p2 = points[(i+1)%size];
        s += p1.get_x()*p2.get_y() - p1.get_y()*p2.get_x();
    }
    return std::fabs(s) * 0.5;
}
