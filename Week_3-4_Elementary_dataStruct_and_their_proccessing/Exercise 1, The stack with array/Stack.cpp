#include "Stack.h"
Stack::~Stack() {
    delete[] stack;
}

void Stack::push(int item) {
    if (isFull()) {
        resizeStack();
    }
    top++;
    stack[top] = item;
}

int Stack::pop() {
    if (isEmpty()) {
        throw std::runtime_error("Stack is empty. Cannot pop.");
    }
    int poppedItem = stack[top];
    top--;
    return poppedItem;
}

bool Stack::isEmpty() const {
    return top == -1;
}

bool Stack::isFull() const {
    return top == size - 1;
}

int Stack::peek() const {
    if (isEmpty()) {
        throw std::runtime_error("Stack is empty. Cannot peek.");
    }
    return stack[top];
}

int Stack::getSize() const {
    return top + 1;
}

void Stack::resizeStack() {
    int newSize = size * 2;
    int* newStack = new int[newSize];
    for (int i = 0; i <= top; i++) {
        newStack[i] = stack[i];
    }
    delete[] stack;
    stack = newStack;
    size = newSize;
}