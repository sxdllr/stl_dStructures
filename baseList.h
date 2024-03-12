#pragma once

template<typename T>
class baseList {
public:
	struct Node {
		T value;
		Node* next;
		Node* prev;

		Node()
			: value(T{})
			, next(nullptr)
			, prev(nullptr)
		{}

		Node(const T& val)
			: value(val)
			, next(nullptr)
			, prev(nullptr)
		{}
	};

	baseList()
		: head(nullptr)
		, tail(nullptr)
	{}

	virtual ~baseList() {}

	virtual void push_back(const T&) = 0;
	virtual void push_front(const T&) = 0;
	virtual void print_list() = 0;
	virtual void pop_back() = 0;
	virtual void pop_front() = 0;
	virtual void erase(T) = 0;
	virtual void clear() = 0;
	virtual size_t size() = 0;
	virtual Node* begin() = 0;
	virtual Node* end() = 0;
	virtual bool empty() = 0;

protected:
	Node* head;
	Node* tail;
};