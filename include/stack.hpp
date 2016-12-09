#include <cstddef>
#include <iostream>
#include <exception>
#include <stdexcept>


template <typename T>
class stack
{
public:
    stack() : array_(new T [init_size_]), array_size_(init_size_), count_(0) {}
    auto size() const -> size_t;
    auto count() const -> size_t;
    auto push(const T&) -> void;
    auto pop() -> T;
    ~stack() { delete[] array_; }
private:
    static const size_t init_size_ = 5;
    T* array_;
    size_t array_size_;
    size_t count_;
};


template <typename T>
auto stack<T>::size() const -> size_t
{
    return array_size_;
}


template <typename T>
auto stack<T>::count() const -> size_t
{
    return count_;
}


template <typename T>
auto stack<T>::push(const T& value) -> void
{
    if (count_ == array_size_)
    {
        T* new_array = new T [array_size_*=2];
        for (int i = 0; i < count_; ++i)
            new_array[i] = array_[i];
        delete[] array_;
        array_ = new_array;
    }
    array_[count_++] = value;
    return;
}


template <typename T>
auto stack<T>::pop() -> T
{
    if (count_)
        return array_[--count_];
    else
        throw std::underflow_error("Stack is empty!");
}
