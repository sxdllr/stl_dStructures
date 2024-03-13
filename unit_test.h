#pragma once
#include "myVector.h"
#include "singleList.h"
#include "doubleList.h"
#include "myStack.h"

void printSeparator() {
	std::cout << "==================" << std::endl;
}
void test_singleList() {
	std::cout << "Single-linked list" << std::endl;
	std::cout << std::endl;

	singleList<int> sl1;
	std::cout << "List is empty?: "
		<< sl1.empty() << std::endl;
	std::cout << "List size: "
		<< sl1.size() << std::endl;

	std::cout << std::endl;

	sl1.push_back(10);
	sl1.push_back(20);
	sl1.push_back(30);
	sl1.push_front(0);

	std::cout << "list elements: ";
	sl1.print_list();

	std::cout << "List size: "
		<< sl1.size() << std::endl;

	std::cout << std::endl;

	singleList<int> sl2(sl1);
	std::cout << "Copy constructor: ";
	sl2.print_list();

	singleList<int> sl3 = sl1;
	std::cout << "Operator = ";
	sl3.print_list();

	std::cout << std::endl;

	sl3.pop_back();
	std::cout << "List afer pop_back(): ";
	sl3.print_list();

	sl3.pop_front();
	std::cout << "List afer pop_front(): ";
	sl3.print_list();

	std::cout << std::endl;

	//sl3.erase(2); // out_of_range
	sl3.erase(1);
	std::cout << "List afer erase(1): ";
	sl3.print_list();
}
void test_doubleList() {
	std::cout << "Double-linked list" << std::endl;
	std::cout << std::endl;

	doubleList<int> dl1;
	std::cout << "List is empty?: "
		<< dl1.empty() << std::endl;
	std::cout << "List size: "
		<< dl1.size() << std::endl;

	std::cout << std::endl;

	dl1.push_back(10);
	dl1.push_back(20);
	dl1.push_back(30);
	dl1.push_front(0);

	std::cout << "list elements: ";
	dl1.print_list();

	std::cout << "List size: "
		<< dl1.size() << std::endl;

	std::cout << std::endl;

	doubleList<int> dl2(dl1);
	std::cout << "Copy constructor: ";
	dl2.print_list();

	doubleList<int> dl3 = dl1;
	std::cout << "Operator = ";
	dl3.print_list();

	std::cout << std::endl;

	dl3.pop_back();
	std::cout << "List afer pop_back(): ";
	dl3.print_list();

	dl3.pop_front();
	std::cout << "List afer pop_front(): ";
	dl3.print_list();

	std::cout << std::endl;

	//dl3.erase(2); // out_of_range
	dl3.erase(1);
	std::cout << "List afer erase(1): ";
	dl3.print_list();
}
void test_vector() {
	std::cout << "Vector" << std::endl;
	std::cout << std::endl;

	myVector<int> vec_empty;
	std::cout << "Vector is empty?: " << vec_empty.empty() << std::endl;
	std::cout << "Size: " << vec_empty.size() << ", Capacity: " << vec_empty.max_size() << std::endl;
	std::cout << std::endl;

	vec_empty.push_back(1);
	vec_empty.push_back(2);
	vec_empty.push_back(3);
	vec_empty.push_back(4);
	std::cout << "Vector elements: ";
	for (size_t i = 0; i < vec_empty.size(); ++i) {
		std::cout << vec_empty[i] << " ";
	}
	std::cout << std::endl;

	vec_empty.pop_back();
	std::cout << "Vector after pop_back(): ";
	for (size_t i = 0; i < vec_empty.size(); ++i) {
		std::cout << vec_empty[i] << " ";
	}
	std::cout << std::endl;

	vec_empty.erase(1);
	std::cout << "Vector after erase(1): ";
	for (size_t i = 0; i < vec_empty.size(); ++i) {
		std::cout << vec_empty[i] << " ";
	}
	std::cout << std::endl;

	vec_empty.clear();
	std::cout << "Vector after clear(): ";
	std::cout << "Size: " << vec_empty.size() << ", Capacity: " << vec_empty.max_size() << std::endl;
	std::cout << std::endl;

	myVector<int> vec_init_list = { 10, 20, 30 };
	std::cout << "Vector with aggregate initialization: ";
	for (size_t i = 0; i < vec_init_list.size(); ++i) {
		std::cout << vec_init_list[i] << " ";
	}
	std::cout << std::endl;
}
void test_stack() {
	std::cout << "Stack" << std::endl;
	std::cout << std::endl;

	myStack<int> stack_empty;
	std::cout << "Stack is empty?: " << stack_empty.empty() << std::endl;
	std::cout << "Size: " << stack_empty.size() << std::endl;
	std::cout << std::endl;

	stack_empty.push(1);
	stack_empty.push(2);
	stack_empty.push(3);
	stack_empty.push(4);
	std::cout << "Stack elements: ";
	for (; !stack_empty.empty();) {
		std::cout << stack_empty.top() << " ";
		stack_empty.pop();
	}
	std::cout << std::endl;

	try {
		stack_empty.pop();
	}
	catch (const std::out_of_range& e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
}
