#pragma once
#include <iostream>

class Stack {
private:
    int size;
    int* stack;
    int top;

public:
    Stack(int initialSize = 100) : size(initialSize), stack(new int[initialSize]), top(-1) {}
    ~Stack();
    void push(int item);
    int pop();
    bool isEmpty() const;
    bool isFull() const;
    int peek() const;
    int getSize() const;
private:
    void resizeStack();
};