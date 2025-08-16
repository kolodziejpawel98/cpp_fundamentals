#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <optional>

#pragma once

class Buffer
{
public:
    Buffer() : arraySize_(0), array_(nullptr) {}

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

    Buffer(const Buffer &obj) : arraySize_(obj.arraySize_), array_(nullptr)
    {
        if (arraySize_ == 0)
        {
            return;
        }
        else
        {
            int *tmpArray = new int[arraySize_];
            for (int i = 0; i < arraySize_; i++)
                tmpArray[i] = obj.array_[i];
            array_ = tmpArray;
        }
    }

    Buffer &operator=(const Buffer &obj)
    {
        if (this == &obj)
            return *this;
        if (obj.arraySize_ == 0)
        {
            delete[] array_;
            array_ = nullptr;
            arraySize_ = 0;
            return *this;
        }
        int tmpSize = obj.arraySize_;
        int *tmpArray = new int[tmpSize];
        for (int i = 0; i < tmpSize; i++)
        {
            tmpArray[i] = obj.array_[i];
        }

        delete[] array_;
        array_ = tmpArray;
        arraySize_ = tmpSize;

        return *this;
    }

    //  String5(String5&& other) noexcept
    //   String5& operator=(String5&& other) noexcept

    ~Buffer()
    {
        delete[] array_;
    }

private:
    int arraySize_;
    int *array_;
};