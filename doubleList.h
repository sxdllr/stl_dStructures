#pragma once
#include <iostream>
#include "baseList.h"

template<typename T>
class doubleList : public baseList<T> {
public:

    doubleList() : baseList<T>() {}

    void push_back(const T&) override;
    void push_front(const T&) override;
    void print_list() override;
    void pop_back() override;
    void pop_front() override;
    void erase(T) override;
    void clear() override;
    size_t size() override;
    typename baseList<T>::Node* begin() override;
    typename baseList<T>::Node* end() override;
    T back();
    bool empty() override;
    doubleList& operator =(const doubleList&);

private:
    void copy(const doubleList&);
};

template<typename T>
void doubleList<T>::push_back(const T& addValue) {
    typename baseList<T>::Node* n = new typename baseList<T>::Node(addValue);
    n->next = nullptr;
    n->prev = nullptr;

    if (this->empty()) {
        this->head = this->tail = n;
    }
    else {
        this->tail->next = n;
        n->prev = this->tail;
        this->tail = n;
    }
}

template<typename T>
void doubleList<T>::push_front(const T& addValue) {
    if (this->empty())
        this->push_back(addValue);

    typename baseList<T>::Node* n = new typename baseList<T>::Node(addValue);
    n->next = this->head;
    n->prev = nullptr;
    this->head->prev = n;
    this->head = n;
}

template<typename T>
void doubleList<T>::print_list() {
    if (this->empty()) {
        std::cout << "List is empty" << std::endl;
    }

    typename baseList<T>::Node* temp = this->head;
    for (; temp != nullptr;) {
        std::cout << temp->value << ' ';
        temp = temp->next;
    }
    std::cout << std::endl;
}

template<typename T>
void doubleList<T>::pop_back() {
    if (this->empty())
        return;

    else if (this->head == this->tail) {
        delete this->tail;
        this->head = this->tail = nullptr;
    }

    else {
        typename baseList<T>::Node* temp = this->tail;
        this->tail = this->tail->prev;
        this->tail->next = nullptr;
        delete temp;
    }
}

template<typename T>
void doubleList<T>::pop_front() {
    if (this->empty())
        return;

    else if (this->head == this->tail) {
        delete this->tail;
        this->head = this->tail = nullptr;
    }

    else {
        typename baseList<T>::Node* nHead = this->head->next;
        delete this->head;
        this->head = nHead;
        nHead->prev = nullptr;
    }
}

template<typename T>
void doubleList<T>::erase(T index) {
    if (index < 0 || index >= this->size() || this->empty()) {
        throw std::out_of_range("Index is out of range");
        return;
    }

    if (index == 0) {
        typename baseList<T>::Node* temp = this->head;
        this->head = this->head->next;
        if (this->head != nullptr)
            this->head->prev = nullptr;
        delete temp;
        return;
    }

    typename baseList<T>::Node* curr = this->head;
    for (int i = 0; curr != nullptr && i < index; ++i) {
        curr = curr->next;
    }

    if (curr == nullptr) {
        throw std::out_of_range("Index is out of range");
        return;
    }

    if (curr->prev != nullptr)
        curr->prev->next = curr->next;
    if (curr->next != nullptr)
        curr->next->prev = curr->prev;

    delete curr;
}

template<typename T>
void doubleList<T>::clear() {
    if (this->empty())
        return;

    for (; this->head != nullptr;) {
        typename baseList<T>::Node* temp = this->head;
        this->head = this->head->next;
        delete temp;
    }
}

template<typename T>
size_t doubleList<T>::size() {
    size_t sz = 0;
    typename baseList<T>::Node* temp = this->head;
    for (; temp != nullptr;) {
        ++sz;
        temp = temp->next;
    }
    return sz;
}

template<typename T>
typename baseList<T>::Node* doubleList<T>::end() {
    return this->tail;
}

template<typename T>
T doubleList<T>::back() {
    if (this->empty()) {
        throw std::out_of_range("List is empty");
    }
    return this->tail->value;
}

template<typename T>
typename baseList<T>::Node* doubleList<T>::begin() {
    return this->head;
}

template<typename T>
bool doubleList<T>::empty() {
    return this->head == nullptr;
}

template<typename T>
doubleList<T>& doubleList<T>::operator =(const doubleList<T>& other) {
    if (this != &other) {
        this->clear();
        this->copy(other);
    }
    return *this;
}

template<typename T>
void doubleList<T>::copy(const doubleList<T>& other) {

    if (other.head == nullptr)
        return;

    this->head = new typename baseList<T>::Node;
    this->head->value = other.head->value;
    this->head->next = nullptr;
    this->head->prev = nullptr;

    typename baseList<T>::Node* temp = this->head;
    typename baseList<T>::Node* otherTemp = other.head->next;

    for (; otherTemp != nullptr;) {
        temp->next = new typename baseList<T>::Node;
        temp->next->prev = temp;
        temp = temp->next;
        temp->value = otherTemp->value;
        temp->next = nullptr;

        otherTemp = otherTemp->next;
    }
}