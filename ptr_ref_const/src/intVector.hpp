#include <iostream>
#pragma once

class IntVector {
public:
    IntVector();
    // IntVector(const IntVector& other);
    // IntVector& operator=(const IntVector& other);
    // ~IntVector();
    int getOne() { return 1;}
    // void push_back(int value);
    // int get(size_t index) const;
    // size_t size() const;

private:
    int* data_;
    size_t size_;
    size_t capacity_;

    // void resize();
};
