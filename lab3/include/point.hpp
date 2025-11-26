#pragma once
#include <iostream>

class Point
{
protected:
    double x, y;

public:
    Point();
    Point(double x, double y);
    Point(const Point& other);
    Point(Point&& other) noexcept;
    ~Point() noexcept;
    
    // Геттеры и сеттеры координат
    double get_x() const;
    double get_y() const;
    void set_x(double x);
    void set_y(double y);

    Point operator+(const Point& right) const;
    Point operator-(const Point& right) const;

    Point operator+=(const Point& right);
    Point operator-=(const Point& right);
    Point& operator=(const Point&) = default;
    Point& operator=(Point&&) noexcept = default;

    // Потоковые операторы
    friend std::ostream& operator<<(std::ostream& os, const Point& p);
    friend std::istream& operator>>(std::istream& is, Point& p);
};