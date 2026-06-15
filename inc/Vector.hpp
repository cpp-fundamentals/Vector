#include <cstddef>

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
        //TODO: capacity recheck;
        data_[size++] = elem;
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

    void capacity_recheck_()
    {
        ///TODO 
    }

    T* data_;
    size_t size_;
    size_t capacity_;
};
