#include "Buffer.hpp"

Buffer::Buffer() : size_(0), array_(nullptr) {}

Buffer::Buffer(size_t size, int value)
{
    if (size != 0)
    {
        array_ = new int[size];
        size_ = size;
        for (size_t i = 0; i < size; i++)
            array_[i] = value;
    }
    else
    {
        size_ = 0;
        array_ = nullptr;
    }
}

Buffer::Buffer(const Buffer &obj) : size_(obj.size_), array_(nullptr)
{
    if (size_ == 0)
    {
        return;
    }
    else
    {
        int *tmpArray = new int[size_];
        for (size_t i = 0; i < size_; i++)
            tmpArray[i] = obj.array_[i];
        array_ = tmpArray;
    }
}

Buffer &Buffer::operator=(const Buffer &obj)
{
    if (this == &obj)
        return *this;
    if (obj.size_ == 0)
    {
        delete[] array_;
        array_ = nullptr;
        size_ = 0;
        return *this;
    }
    size_t tmpSize = obj.size_;
    int *tmpArray = new int[tmpSize];
    for (size_t i = 0; i < tmpSize; i++)
        tmpArray[i] = obj.array_[i];

    delete[] array_;
    array_ = tmpArray;
    size_ = tmpSize;

    return *this;
}

Buffer::Buffer(Buffer &&obj) noexcept : size_(obj.size_)
{
    array_ = obj.array_;
    obj.array_ = nullptr;
    obj.size_ = 0;
}

Buffer &Buffer::operator=(Buffer &&obj) noexcept
{
    if (this == &obj)
        return *this;
    delete[] array_;
    array_ = obj.array_;
    size_ = obj.size_;
    obj.array_ = nullptr;
    obj.size_ = 0;
    return *this;
}

int Buffer::getSize() const
{
    return size_;
}

const int *Buffer::getData() const
{
    return array_;
}

int Buffer::operator[](size_t indexOfElement)
{
    return array_[indexOfElement];
}

int Buffer::at(size_t indexOfElement)
{
    if (indexOfElement >= size_)
    {
        throw std::out_of_range("Buffer::at – index out of range");
    }
    return array_[indexOfElement];
}

void Buffer::push_back(int element)
{
    int *newArray = new int[size_ + 1];

    for (size_t i = 0; i < size_; i++)
        newArray[i] = array_[i];
    newArray[size_] = element;

    delete[] array_;
    array_ = newArray;
    size_++;
}

void Buffer::resize(size_t size)
{
    if (size > size_)
    {
        int *resizedArray = new int[size];
        for (size_t i = 0; i < size; i++)
        {
            if (i < size_)
            {
                resizedArray[i] = array_[i];
            }
            else
            {
                resizedArray[i] = 0;
            }
        }
        delete[] array_;
        array_ = resizedArray;
        size_ = size;
    }
    else if (size < size_)
    {
        if (size == 0)
        {
            delete[] array_;
            array_ = nullptr;
            size_ = 0;
            return;
        }

        int *resizedArray = new int[size];
        for (size_t i = 0; i < size; i++)
            resizedArray[i] = array_[i];

        delete[] array_;
        array_ = resizedArray;
        size_ = size;
    }
    else
    {
        return;
    }
}

Buffer::~Buffer()
{
    delete[] array_;
}
