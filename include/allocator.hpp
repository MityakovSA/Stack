#include <memory>
#include <cstddef>
#include <algorithm>


template <typename T>
class allocator
{
protected:
    allocator(size_t size = 0) : size_(size), count_(0), ptr_( static_cast<T*>(::operator new(size * sizeof(T))) ) {}
    allocator(allocator const&) = delete;
    ~allocator();

    auto operator =(allocator const&) -> allocator& = delete;

    auto swap(allocator& other) -> void;
    auto allocate() -> void;
    auto reallocate() -> void;

    size_t size_;
    size_t count_;
    T* ptr_;
};


template <typename T>
allocator<T>::~allocator()
{
    for (size_t i = 0; i < count_; ++i)
        ptr_[i].~T();
    ::operator delete[](ptr_);
}


template <typename T>
auto allocator<T>::swap(allocator &other) -> void
{
    std::swap(size_, other.size_);
    std::swap(count_, other.count_);
    std::swap(ptr_, other.ptr_);
}


template <typename T>
auto allocator<T>::allocate() -> void
{
    size_ *= 2;

    try
    {
        reallocate();
    }
    catch (...)
    {
        size_ /= 2;
        throw;
    }

    return;
}


template <typename T>
auto allocator<T>::reallocate() -> void
{
    allocator<T> alloc(size_);
    std::copy(ptr_, ptr_ + count_, alloc.ptr_);
    alloc.count_ = count_;
    swap(alloc);
}