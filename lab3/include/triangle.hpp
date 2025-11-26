#pragma once
#include "figure.hpp"

class Triangle : public Figure {
public:
    Triangle();
    virtual ~Triangle() = default;
    virtual Point getCenter() const override;
    virtual bool isCorrect() const override;
    virtual operator double() const override;
    virtual const char* getName() const override { return "Triangle"; }
};
