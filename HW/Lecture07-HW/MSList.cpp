#include "MSList.h"

template <class T>
MSList<T>::MSList() : head(nullptr), size(0) {}

template <class T>
MSList<T>::~MSList() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

template <class T>
void MSList<T>::push_back(T data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    size++;
}

template <class T>
void MSList<T>::pop_back() {
    if (head == nullptr) {
        return;
    }
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
    }
    else {
        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }
    size--;
}

template <class T>
T& MSList<T>::at(int index) {
    if (index < 0 || index >= size) {
        throw "Index out of range";
    }
    Node* temp = head;
    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }
    return temp->data;
}

template <class T>
int MSList<T>::getSize() {
    return size;
}