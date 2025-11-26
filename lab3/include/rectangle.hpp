#pragma once
#include "figure.hpp"

class Rectangle : public Figure {
public:
    Rectangle();
    virtual ~Rectangle() = default;
    virtual Point getCenter() const override;
    virtual bool isCorrect() const override;
    virtual operator double() const override;
    virtual const char* getName() const override { return "Rectangle"; }
};
