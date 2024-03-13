#pragma once
#include <iostream>
#include <initializer_list>
#include <algorithm>

template<typename T, size_t N>
class myArray {
public:
	myArray() : cap(10) {}
	myArray(std::initializer_list<T>);

	myArray& operator =(const myArray&);

	const T* begin() const;
	const T* end() const;

	size_t size() const;
	size_t max_size() const;
	bool empty() const;

	T& operator [](size_t);
	const T& at(const size_t&) const;
	T& front() const;
	T& back() const;
	T* dat() const;
	void fill(const int&);
	void swap(myArray&);

private:
	T data[N];
	size_t cap;
};

template<typename T, size_t N>
myArray<T, N>::myArray(std::initializer_list<T> data_l) {
	if (data_l.size() != N)
		throw std::invalid_argument("Initializer list size does not match array size");
	if (data_l.size() >= cap)
		cap *= 2;
	std::copy(data_l.begin(), data_l.end(), data);
}

template<typename T, size_t N>
myArray<T, N>& myArray<T, N>::operator =(const myArray<T, N>& other) {
	if (this != &other) { 
		std::copy(other.data, other.data + N, data);
	}
	return *this;
}

template<typename T, size_t N>
const T* myArray<T, N>::begin() const {
	return data;
}

template<typename T, size_t N>
const T* myArray<T, N>::end() const {
	return data + N;
}

template<typename T, size_t N>
size_t myArray<T, N>::size() const {
	return N;
}

template<typename T, size_t N>
size_t myArray<T, N>::max_size() const {
	return cap;
}

template<typename T, size_t N>
bool myArray<T, N>::empty() const {
	return N == 0;
}

template<typename T, size_t N>
T& myArray<T, N>::operator[](size_t index) {
	return data[index];
}

template<typename T, size_t N>
const T& myArray<T, N>::at(const size_t& index) const {
	if (index >= N)
		throw std::out_of_range("Index out of range");
	return data[index];
}

template<typename T, size_t N>
T& myArray<T, N>::front() const {
	return data[0];
}

template<typename T, size_t N>
T& myArray<T, N>::back() const {
	return data[N - 1];
}

template<typename T, size_t N>
T* myArray<T, N>::dat() const {
	return data;
}

template<typename T, size_t N>
void myArray<T, N>::fill(const int& add_data) {
	for (int i = 0; i < N; ++i)
		data[i] = add_data;
}

template<typename T, size_t N>
void myArray<T, N>::swap(myArray<T, N>& other) {
	std::swap_ranges(data, data + N, other.data);
}