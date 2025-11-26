#pragma once
#include "figure.hpp"

class Square : public Figure {
public:
    Square();
    Square(const Point& p1, const Point& p2, const Point& p3, const Point& p4);
    Square(const Square& other);
    Square(Square&& other) noexcept;
    
    Square& operator=(const Square& other);
    Square& operator=(Square&& other) noexcept;
    bool operator==(const Square& other) const;

    Point getCenter() const override;
    bool isCorrect() const override;
    operator double() const override;
    const char* getName() const override;

    friend std::ostream& operator<<(std::ostream& os, const Square& s);
    friend std::istream& operator>>(std::istream& is, Square& s);
};