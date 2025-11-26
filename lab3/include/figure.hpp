#pragma once

#include <iostream>
#include <vector>
#include "point.hpp"

class Figure{
protected:
    Point* points; // массив точек, задающих вершины фигуры
    size_t size; 

public:
    Figure();
    Figure(size_t n);
    virtual ~Figure();

    Figure(const Figure& other);
    Figure(Figure&& other) noexcept;

    Figure& operator=(const Figure& other);
    Figure& operator=(Figure&& other) noexcept;

    bool operator==(const Figure& other) const;

    virtual Point getCenter() const = 0;
    virtual bool isCorrect() const = 0;
    virtual operator double() const = 0;
    size_t getPointCount() const noexcept;
    const Point& getPoint(size_t idx) const;
    virtual const char* getName() const = 0;

    friend std::ostream& operator<<(std::ostream& os, const Figure& f);
    friend std::istream& operator>>(std::istream& is, Figure& f);

};