#include "intVector.hpp"

IntVector::IntVector()
    : data_(nullptr), size_(0) {}

IntVector &IntVector::operator=(const IntVector &other)
{
    if (this != &other)
    {
        size_ = other.size_;
        delete[] data_;
        data_ = new int[size_];
        for (int i = 0; i < size_; i++)
        {
            data_[i] = other.data_[i];
        }
    }
    return *this;
}

IntVector::IntVector(const IntVector &other)
{
    size_ = other.size_;
    data_ = new int[size_];
    for (int i = 0; i < size_; i++)
    {
        data_[i] = other.data_[i];
    }
}

void IntVector::push_back(int value)
{
    int *new_data = new int[size_ + 1];

    for (size_t i = 0; i < size_; ++i)
    {
        new_data[i] = data_[i];
    }

    delete[] data_;
    data_ = new_data;

    data_[size_] = value;
    size_++;
}

int IntVector::size() const
{
    return size_;
}

int IntVector::get(int index) const
{
    if (index < 0 || index >= size_)
    {
        throw std::out_of_range("Index out of range");
    }
    return data_[index];
}

IntVector::~IntVector()
{
    delete[] data_;
}
