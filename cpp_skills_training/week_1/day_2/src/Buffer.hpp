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

    // int main() {
    //     String a{"Hello"};      // konstruktor
    //     String b = a;           // konstruktor kopiujący
    //     String c = String{"Hi"}; // konstruktor przenoszący

    //     b = a;                  // przypisanie kopiujące
    //     b = String{"World"};    // przypisanie przenoszące

    //     String d{"Tmp"};
    //     d = std::move(c);       // wymuszone przeniesienie
    // }

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

    ~Buffer()
    {
        delete[] array_;
    }

private:
    int arraySize_;
    int *array_;
};