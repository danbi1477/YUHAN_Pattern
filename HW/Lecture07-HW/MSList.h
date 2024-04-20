#pragma once

template <class T>
class MSList {
private:
    struct Node {
        T data;
        Node* next;
        Node(T data) : data(data), next(nullptr) {}
    };
    Node* head;
    int size;

public:
    MSList();
    ~MSList();

    void push_back(T data);
    void pop_back();
    T& at(int index);
    int getSize();
};

