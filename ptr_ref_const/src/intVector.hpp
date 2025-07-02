#include <iostream>
#include <stdexcept>
#pragma once

class IntVector
{
public:
    IntVector();
    // IntVector(const IntVector& other);
    // IntVector& operator=(const IntVector& other);
    ~IntVector();
    void push_back(int);
    int get(int) const;
    int size() const;

private:
    int *data_;
    int size_;
    // size_t capacity_;

    // void resize();
};
