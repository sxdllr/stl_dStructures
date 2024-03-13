#pragma once
#include "doubleList.h"

template <typename T>
class myStack {
public:
	myStack() : top_ind(-1) {}

	bool empty() const;
	size_t size();
	T top();
	void push(const T&);
	void pop();

private:
	doubleList<T> data;
	int top_ind;
};

template <typename T>
bool myStack<T>::empty() const {
	return top_ind == -1;
}

template <typename T>
size_t myStack<T>::size() {
	return data.size();
}

template <typename T>
T myStack<T>::top() {
	if (empty()) {
		throw std::out_of_range("Stack is empty");
	}
	return data.back();
}

template <typename T>
void myStack<T>::push(const T& val) {
	data.push_back(val);
	++top_ind;
}

template <typename T>
void myStack<T>::pop() {
	if (top_ind >= 0) {
		data.pop_back();
		--top_ind;
	}
}