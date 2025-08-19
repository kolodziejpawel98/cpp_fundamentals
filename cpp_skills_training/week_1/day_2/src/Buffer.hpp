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
            for (size_t i = 0; i < arraySize_; i++)
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

    Buffer(Buffer &&obj) noexcept : arraySize_(obj.arraySize_)
    {
        array_ = obj.array_;
        obj.array_ = nullptr;
        obj.arraySize_ = 0;
    }

    Buffer &operator=(Buffer &&obj) noexcept
    {
        if (this == &obj)
            return *this;
        delete[] array_;
        array_ = obj.array_;
        arraySize_ = obj.arraySize_;
        obj.array_ = nullptr;
        obj.arraySize_ = 0;
        return *this;
    }

    int getArraySize()
    {
        return arraySize_;
    }

    const int *getData() const
    {
        return array_;
    }

    int operator[](size_t indexOfElement)
    {
        return array_[indexOfElement];
    }

    int at(size_t indexOfElement)
    {
        if (indexOfElement >= arraySize_)
        {
            throw std::out_of_range("Buffer::at – index out of range");
        }
        return array_[indexOfElement];
    }

    void push_back(int element)
    {
        int *newArray = new int[arraySize_ + 1];

        for (size_t i = 0; i < arraySize_; i++)
            newArray[i] = array_[i];
        newArray[arraySize_] = element;

        delete[] array_;
        array_ = newArray;
        arraySize_++;
    }

    ~Buffer()
    {
        delete[] array_;
    }

private:
    size_t arraySize_;
    int *array_;
};