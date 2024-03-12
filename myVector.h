#pragma once

#include <iostream>
#include <initializer_list>
#include <algorithm>

template <typename T>
class myVector {
public:
    myVector(size_t s);
    myVector(std::initializer_list<T>);
    myVector(const myVector&);
    myVector();
    ~myVector();

    myVector& operator=(const myVector&);

    T* begin();
    T* end();

    size_t size() const;
    size_t max_size() const;
    void resize(const size_t, const T&);
    bool empty() const;
    void reserve(size_t);
    void shrink_to_fit();

    const T& operator[](size_t) const;
    T& operator[](size_t);
    T& at(const size_t&);
    T& front();
    T& back();
    T* dat();

    void push_back(const T&);
    void pop_back();
    void insert(const size_t, const T&);
    void erase(const size_t);
    void erase(const size_t, const size_t);
    void swap(myVector&);
    void clear();
    void emplace_back(const T&);

private:
    size_t capacity;
    size_t sz;
    T* data;

    void copy(const myVector&);
};

template<typename T>
myVector<T>::myVector(size_t s)
    : capacity(s)
    , sz(s)
    , data(new T[sz])
{
    if (data == nullptr)
        throw std::bad_alloc();
}

template<typename T>
myVector<T>::myVector(std::initializer_list<T> data_l)
    : capacity(data_l.size())
    , sz(data_l.size())
    , data(new T[sz])
{
    std::copy(data_l.begin(), data_l.end(), data);
}

template<typename T>
myVector<T>::myVector(const myVector<T>& other) {
    if (this != &other) {
        copy(other);
    }
}

template<typename T>
myVector<T>::myVector()
    : capacity(10)
    , sz(0)
    , data(new T[capacity])
{
    if (data == nullptr)
        throw std::bad_alloc();
}

template<typename T>
myVector<T>::~myVector() {
    delete[] data;
}

template<typename T>
myVector<T>& myVector<T>::operator=(const myVector<T>& other) {
    if (this != &other) {
        delete[] data;
        copy(other);
    }
    return *this;
}

template<typename T>
T* myVector<T>::begin() {
    return data;
}

template<typename T>
T* myVector<T>::end() {
    return data + sz;
}

template <typename T>
size_t myVector<T>::size() const {
    return sz;
}

template <typename T>
size_t myVector<T>::max_size() const {
    return capacity;
}

template <typename T>
void myVector<T>::resize(const size_t newSize, const T& value) {
    if (newSize < sz) {
        sz = newSize;
    }
    else if (newSize > sz) {
        reserve(newSize);
        std::fill(data + sz, data + newSize, value);
        sz = newSize;
    }
}

template <typename T>
bool myVector<T>::empty() const {
    return sz == 0;
}

template <typename T>
void myVector<T>::reserve(size_t newCap) {
    if (newCap > capacity) {
        T* newData = new T[newCap];
        std::copy(data, data + sz, newData);
        delete[] data;
        data = newData;
        capacity = newCap;
    }
}

template <typename T>
void myVector<T>::shrink_to_fit() {
    if (sz < capacity) {
        T* newData = new T[sz];
        std::copy(data, data + sz, newData);
        delete[] data;
        data = newData;
        capacity = sz;
    }
}

template<typename T>
const T& myVector<T>::operator[](size_t index) const {
    if (index >= sz) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

template<typename T>
T& myVector<T>::operator[](size_t index) {
    return data[index];
}

template<typename T>
T& myVector<T>::at(const size_t& index) {
    if (index >= sz)
        throw std::out_of_range("Index out of range");
    return data[index];
}

template<typename T>
T& myVector<T>::front() {
    return data[0];
}

template<typename T>
T& myVector<T>::back() {
    return data[sz - 1];
}

template<typename T>
T* myVector<T>::dat() {
    return data;
}

template<typename T>
void myVector<T>::push_back(const T& other) {
    if (sz >= capacity) {
        reserve(capacity * 2);
    }
    data[sz] = other;
    ++sz;
}

template<typename T>
void myVector<T>::pop_back() {
    if (sz > 0)
        --sz;
    else
        std::cerr << "Vector is empty\n";
}

template<typename T>
void myVector<T>::insert(const size_t index, const T& value) {
    if (index > sz)
        throw std::out_of_range("Index out of range");

    if (sz >= capacity) {
        reserve(capacity * 2);
    }

    for (size_t i = sz; i > index; --i) {
        data[i] = data[i - 1];
    }
    data[index] = value;
    ++sz;
}

template<typename T>
void myVector<T>::erase(const size_t index) {
    if (index >= sz)
        throw std::out_of_range("Index out of range");

    for (size_t i = index; i < sz - 1; ++i) {
        data[i] = data[i + 1];
    }
    --sz;
}

template<typename T>
void myVector<T>::erase(const size_t start, const size_t end) {
    if (start >= sz || end >= sz || start > end) {
        throw std::out_of_range("Index out of range");
        return;
    }

    size_t elements_to_move = sz - end - 1;
    for (size_t i = start; i <= end && (i + elements_to_move) < capacity; ++i) {
        data[i] = data[i + elements_to_move];
    }

    sz -= (end - start + 1);
}

template<typename T>
void myVector<T>::swap(myVector<T>& other) {
    std::swap(data, other.data);
    std::swap(sz, other.sz);
    std::swap(capacity, other.capacity);
}

template<typename T>
void myVector<T>::clear() {
    sz = 0;
}

template<typename T>
void myVector<T>::emplace_back(const T&) {
    // Not implemented
}

template<typename T>
void myVector<T>::copy(const myVector<T>& other) {
    capacity = other.capacity;
    sz = other.sz;
    data = new T[capacity];
    std::copy(other.data, other.data + sz, data);
}
