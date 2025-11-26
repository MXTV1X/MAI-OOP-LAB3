#include "../include/figure.hpp"
#include <cmath>
#include <stdexcept>

Figure::Figure() : points(nullptr), size(0) {}

Figure::Figure(size_t n) : size(n), points(nullptr) {
    if (n > 0){
        points = new Point[n];
    }
}

Figure::~Figure() {
    delete[] points;
}

Figure::Figure(const Figure& other) : size(other.size) {
    points = new Point[size];
    for (size_t i = 0; i < size; ++i)
        points[i] = other.points[i];
}

Figure::Figure(Figure&& other) noexcept : points(other.points), size(other.size) {
    other.points = nullptr;
    other.size = 0;
}

Figure& Figure::operator=(const Figure& other) {
    if (this != &other) {
        delete[] points;
        size = other.size;
        points = new Point[size];
        for (size_t i = 0; i < size; ++i)
            points[i] = other.points[i];
    }
    return *this;
}

Figure& Figure::operator=(Figure&& other) noexcept {
    if (this != &other) {
        delete[] points;
        points = other.points;
        size = other.size;
        other.points = nullptr;
        other.size = 0;
    }
    return *this;
}

bool Figure::operator==(const Figure& other) const {
    const double EPS = 1e-6;
    if (size != other.size)
        return false;

    for (size_t i = 0; i < size; ++i) {
        if (std::fabs(points[i].get_x() - other.points[i].get_x()) > EPS ||
            std::fabs(points[i].get_y() - other.points[i].get_y()) > EPS)
            return false;
    }
    return true;
}

size_t Figure::getPointCount() const noexcept {
    return size;
}

const Point& Figure::getPoint(size_t idx) const {
    if (idx >= size) throw std::out_of_range("Point index out of range");
    return points[idx];
}

std::ostream& operator<<(std::ostream& os, const Figure& f) {
    os << f.getName() << "\n";

    for (size_t i = 0; i < f.getPointCount(); ++i) {
        const Point& p = f.getPoint(i);
        os << "(" << p.get_x() << ", " << p.get_y() << ")\n";
    }

    return os;
}


std::istream& operator>>(std::istream& is, Figure& f) {
    for (size_t i = 0; i < f.size; ++i)
        is >> f.points[i];
    return is;
}