#pragma once
#include <iostream>
#include "baseList.h"

template<typename T>
class singleList : public baseList<T> {
public:

    singleList() : baseList<T>() {}

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
    bool empty() override;
    singleList& operator =(const singleList&);

private:
    void copy(const singleList&);
};

template<typename T>
void singleList<T>::push_back(const T& addValue) {
    typename baseList<T>::Node* n = new typename baseList<T>::Node(addValue);
    n->next = nullptr;

    if (this->empty()) {
        this->head = n;
        this->tail = n;
    }
    else {
        this->tail->next = n;
        this->tail = n;
    }
}

template<typename T>
void singleList<T>::push_front(const T& addValue) {
    if (this->empty())
        this->push_back(addValue);

    typename baseList<T>::Node* n = new typename baseList<T>::Node(addValue);
    n->next = this->head;
    this->head = n;
}

template<typename T>
void singleList<T>::print_list() {
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
void singleList<T>::pop_back() {
    if (this->empty())
        return;

    else if (this->head->next == nullptr) {
        delete this->head;
        this->head = nullptr;
    }

    else {
        typename baseList<T>::Node* prev = this->head;
        typename baseList<T>::Node* curr = this->head->next;
        for (; curr->next != nullptr;) {
            prev = curr;
            curr = curr->next;
        }
        delete curr;
        prev->next = nullptr;
    }
}

template<typename T>
void singleList<T>::pop_front() {
    if (this->empty())
        return;

    else if (this->head->next == nullptr) {
        delete this->head;
        this->head = nullptr;
    }

    else {
        typename baseList<T>::Node* nHead = this->head->next;
        delete this->head;
        this->head = nHead;
    }
}

template<typename T>
void singleList<T>::erase(T index) {
    if (index < 0 || index > this->size() - 1 || this->empty()) {
        throw std::out_of_range("Index is out of range");
        return;
    }

    if (index == 0) {
        delete this->head;
        this->head = nullptr;
    }

    typename baseList<T>::Node* curr = this->head;

    for (int i = 0; curr != nullptr && i < index - 1; ++i) {
        curr = curr->next;
    }

    if (curr == nullptr || curr->next == nullptr) {
        throw std::out_of_range("Index is out of range");
        return;
    }

    typename baseList<T>::Node* temp = curr->next;
    curr->next = temp->next;
    delete temp;
}

template<typename T>
void singleList<T>::clear() {
    if (this->empty())
        return;

    for (; this->head != nullptr;) {
        typename baseList<T>::Node* temp = this->head;
        this->head = this->head->next;
        delete temp;
    }
}

template<typename T>
size_t singleList<T>::size() {
    int sz = 0;
    typename baseList<T>::Node* temp = this->head;
    for (; temp != nullptr;) {
        ++sz;
        temp = temp->next;
    }
    return sz;
}

template<typename T>
typename baseList<T>::Node* singleList<T>::begin() {
    return this->head;
}

template<typename T>
typename baseList<T>::Node* singleList<T>::end() {
    return this->tail;
}

template<typename T>
bool singleList<T>::empty() {
    return this->head == nullptr;
}

template<typename T>
singleList<T>& singleList<T>::operator =(const singleList& other) {
    if (this != &other) {
        clear();
        copy(other);
    }
    return *this;
}

template<typename T>
void singleList<T>::copy(const singleList<T>& other) {

    if (other.head == nullptr)
        return;

    this->head = new typename baseList<T>::Node;
    this->head->value = other.head->value;
    this->head->next = nullptr;

    typename baseList<T>::Node* temp = this->head;
    typename baseList<T>::Node* otherTemp = other.head->next;

    for (; otherTemp != nullptr;) {
        temp->next = new typename baseList<T>::Node;
        temp = temp->next;
        temp->value = otherTemp->value;
        temp->next = nullptr;

        otherTemp = otherTemp->next;
    }
}