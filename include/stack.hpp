#include <allocator.hpp>


template <typename T>
class stack : public allocator<T>
{
public:
    stack() : allocator<T>(init_size_) {}

    auto size() const noexcept -> size_t;
    auto count() const noexcept -> size_t;
    auto empty() const noexcept -> bool;
    auto push(const T&) /* strong */ -> void;
    auto pop() noexcept -> void;
    auto top() const /* strong */ -> T;

private:
    static const size_t init_size_ = 5;
};


template <typename T>
auto stack<T>::size() const noexcept -> size_t
{
    return allocator<T>::size_;
}


template <typename T>
auto stack<T>::count() const noexcept -> size_t
{
    return allocator<T>::count_;
}


template <typename T>
auto stack<T>::empty() const noexcept -> bool
{
    return (allocator<T>::count_ ? false : true);
}


template <typename T>
auto stack<T>::push(const T& value) /* strong */ -> void
{
    bool realloc = false;

    try
    {
        allocator<T>::allocate();
        realloc = true;
    }
    catch (...)
    {
        throw;
    }

    try
    {
        allocator<T>::ptr_[allocator<T>::count_] = value;
    }
    catch (...)
    {
        if (realloc)
        {
            allocator<T>::size_ /= 2;
            allocator<T>::reallocate();
        }
        throw;
    }

    ++allocator<T>::count_;
    return;
}


template <typename T>
auto stack<T>::pop() noexcept -> void
{
    if (allocator<T>::count_)
        --allocator<T>::count_;
    return;
}


template <typename T>
auto stack<T>::top() const /* strong */ -> T
{
    if (allocator<T>::count_)
    {
        T value = allocator<T>::ptr_[allocator<T>::count_ - 1];
        return value;
    }
    throw std::underflow_error("Stack is empty!");
}