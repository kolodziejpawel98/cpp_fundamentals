#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <optional>

#pragma once

class Buffer
{
public:
    Buffer()
    {
        arraySize_ = 0;
        array_ = nullptr;
    };

    Buffer(int size, int value)
    {
        if (size != 0)
        {
            array_ = new int[size];
            arraySize_ = size;
            for (int i = 0; i < size; i++)
                array_[i] = value;
        }
        else
        {
            arraySize_ = 0;
            array_ = nullptr;
        }
    }

    Buffer(const Buffer &obj)
    {
        this->arraySize_ = obj.arraySize_;
        if (this->arraySize_ == 0)
            array_ = nullptr;
        int *tmpArray = new int[this->arraySize_];
        for (int i = 0; i < this->arraySize_; i++)
            tmpArray = obj.array_;
        array_ = tmpArray;
    }

    ~Buffer()
    {
        delete[] array_;
    }

private:
    int *array_;
    int arraySize_;
};