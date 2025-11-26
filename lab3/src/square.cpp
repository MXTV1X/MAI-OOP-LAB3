#include "../include/square.hpp"
#include <cmath>
#include <stdexcept>

Square::Square() : Figure(4) {}

Square::Square(const Point& p1, const Point& p2, const Point& p3, const Point& p4) : Figure(4) {
    points[0] = p1;
    points[1] = p2;
    points[2] = p3;
    points[3] = p4;
    if (!isCorrect()) {
        throw std::invalid_argument("Invalid square points");
    }
}

Square::Square(const Square& other) : Figure(4) {
    for (size_t i = 0; i < 4; ++i) {
        points[i] = other.points[i];
    }
}

Square::Square(Square&& other) noexcept : Figure(std::move(other)) {}

Square& Square::operator=(const Square& other) {
    if (this != &other) {
        for (size_t i = 0; i < 4; ++i) {
            points[i] = other.points[i];
        }
    }
    return *this;
}

Square& Square::operator=(Square&& other) noexcept {
    Figure::operator=(std::move(other));
    return *this;
}

bool Square::operator==(const Square& other) const {
    return Figure::operator==(other);
}

Point Square::getCenter() const {
    double center_x = (points[0].get_x() + points[1].get_x() + points[2].get_x() + points[3].get_x()) / 4.0;
    double center_y = (points[0].get_y() + points[1].get_y() + points[2].get_y() + points[3].get_y()) / 4.0;
    return Point(center_x, center_y);
}

bool Square::isCorrect() const {
    // Проверяем, что все стороны равны и углы 90 градусов
    double d2 = std::pow(points[1].get_x() - points[0].get_x(), 2) + std::pow(points[1].get_y() - points[0].get_y(), 2);
    double d3 = std::pow(points[2].get_x() - points[1].get_x(), 2) + std::pow(points[2].get_y() - points[1].get_y(), 2);
    double d4 = std::pow(points[3].get_x() - points[2].get_x(), 2) + std::pow(points[3].get_y() - points[2].get_y(), 2);
    double d1 = std::pow(points[0].get_x() - points[3].get_x(), 2) + std::pow(points[0].get_y() - points[3].get_y(), 2);

    // Проверяем равенство сторон
    if (std::abs(d1 - d2) > 1e-9 || std::abs(d2 - d3) > 1e-9 || std::abs(d3 - d4) > 1e-9) {
        return false;
    }

    // Проверяем перпендикулярность смежных сторон
    double dot_product = (points[1].get_x() - points[0].get_x()) * (points[2].get_x() - points[1].get_x()) +
                        (points[1].get_y() - points[0].get_y()) * (points[2].get_y() - points[1].get_y());
    
    return std::abs(dot_product) < 1e-9;
}

Square::operator double() const {
    double side = std::sqrt(std::pow(points[1].get_x() - points[0].get_x(), 2) + 
                           std::pow(points[1].get_y() - points[0].get_y(), 2));
    return side * side;
}

const char* Square::getName() const {
    return "Square";
}

std::ostream& operator<<(std::ostream& os, const Square& s) {
    os << s.points[0] << " " << s.points[1] << " " << s.points[2] << " " << s.points[3];
    return os;
}

std::istream& operator>>(std::istream& is, Square& s) {
    is >> s.points[0] >> s.points[1] >> s.points[2] >> s.points[3];
    if (!s.isCorrect()) {
        throw std::invalid_argument("Invalid square points");
    }
    return is;
}