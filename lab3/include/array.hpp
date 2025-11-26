#pragma once
#include "figure.hpp"
#include <iostream>

class Array
{
private:
    Figure** arr;
    size_t size;
    size_t capacity;
    void resize(size_t newCapacity); 

public:
    Array();
    ~Array();

    Array(const Array&) = delete;
    Array& operator=(const Array&) = delete;

    void push_back(Figure* f);
    bool empty() const;
    void remove(size_t idx);
    Figure* operator[](size_t idx) const;
    size_t getSize() const;

    double totalArea() const;
    void printAll() const;
    void clear();
    
};