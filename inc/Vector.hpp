#include <cstddef>
#include <iostream>
#include <concepts>

template <typename T>
class Vector
{
public:
    Vector():data_(nullptr), size_(0), capacity_(0)
    {}

    Vector(const Vector& obj):
        size_(obj.size_), capacity_(obj.capacity_)
    {
        data_ = new T[capacity_];
        for (int i = 0; i < size_; i++)
        {
            data_[i] = obj.data_[i];
        }
        
    }
    
    Vector(Vector&& obj):
        size_(obj.size_), capacity_(obj.capacity_)
    {
        data_ = new T[capacity_];
        for (size_t i = 0; i < obj.size_; i++)
        {
            data_[i] = obj.data_[i];
        }

        delete [] obj.data_;
        obj.size_ = 0;
        obj.capacity_ = 0;
    }
    
    bool operator==(const Vector& obj) const
    {
        static_assert(std::equality_comparable<T>,
                    "ERROR: Types must be comparable!!!!");

        if(size_ != obj.size_)
        {
            return false;
        }
        for (size_t i = 0; i < size_; i++)
        {
            if(obj.data_[i] != data_[i])
            {
                return false;
            }
        }
        return true;
    }

    size_t size()
    {
        return size_;
    }
    size_t capacity()
    {
        return capacity_;
    }

    void push_back(T elem)
    {
        //std::cout << "PUSH BACK" << std::endl;
        if(size_ == capacity_)
        {
            _grow();
        }
        data_[size_++] = elem;
    }

    T& operator[](int index)
    {
        return data_[index];
    }
    const T& operator[](int index) const
    {
        return data_[index];
    }
private:

    void _grow()
    {
        size_t new_capacity = (capacity_ == 0 ) ? 1 : capacity_ * 2;

        T* new_data = new T[new_capacity];
        for (size_t i = 0; i < size_; i++)
        {
            new_data[i] = data_[i];
        }
        delete [] data_;
    
        data_ = new_data;
        capacity_ = new_capacity;
    }

    T* data_;
    size_t size_;
    size_t capacity_;
};
