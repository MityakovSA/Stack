#include <cstddef>
#include <stdexcept>
#include <algorithm>


template <typename T>
class stack
{
public:
    stack() : array_(new T [init_size_]), array_size_(init_size_), count_(0) {}
    auto size() const noexcept -> size_t;
    auto count() const noexcept -> size_t;
    auto empty() const noexcept -> bool;
    auto push(const T&) /* strong */ -> void;
    auto pop() noexcept -> void;
    auto top() const noexcept -> const T*;
    ~stack() { delete[] array_; }
private:
    static const size_t init_size_ = 5;
    T* array_;
    size_t array_size_;
    size_t count_;
};


template <typename T>
auto stack<T>::size() const noexcept -> size_t
{
    return array_size_;
}


template <typename T>
auto stack<T>::count() const noexcept -> size_t
{
    return count_;
}


template <typename T>
auto stack<T>::empty() const noexcept -> bool
{
    return (count_ ? false : true);
}


template <typename T>
auto stack<T>::push(const T& value) /* strong */ -> void
{
    T* backup;

    try
    {
        backup = new T[array_size_];
        std::copy(array_, array_+count_, backup);
    }
    catch(...)
    {
        delete[] backup;
        throw;
    }

    if (count_ == array_size_)
    {
        array_size_ *= 2;
        T* new_array;

        try
        {
            new_array = new T[array_size_];
            std::copy(array_, array_+count_, new_array);
            delete[] array_;
            array_ = new_array;
        }
        catch (...)
        {
            delete[] new_array;
            delete[] backup;
            array_size_ /= 2;
            throw;
        }

    }

    try
    {
        array_[count_] = value;
        ++count_;
    }
    catch (...)
    {
        delete[] array_;
        array_ = backup;
        array_size_ /= 2;
        throw;
    }

    delete[] backup;
    return;
}


template <typename T>
auto stack<T>::pop() noexcept -> void
{
    if (count_)
        --count_;
    return;
}


template <typename T>
auto stack<T>::top() const noexcept -> const T*
{
    if (count_)
    {
        const T* value = nullptr;

        try
        {
            value = &array_[count_ - 1];
        }
        catch (...) {}

        return value;
    }
    return nullptr;
}