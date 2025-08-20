#include <iostream>
#include <fstream>
#include <string>
#include <memory>

#pragma once

class Buffer
{
public:
    Buffer();
    Buffer(size_t, int);
    Buffer(const Buffer &);
    Buffer &operator=(const Buffer &);
    Buffer(Buffer &&) noexcept;
    Buffer &operator=(Buffer &&obj) noexcept;
    int getSize() const;
    const int *getData() const;
    int operator[](size_t);
    int at(size_t);
    void push_back(int);
    void resize(size_t);
    ~Buffer();

private:
    size_t size_;
    int *array_;
};