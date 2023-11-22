#pragma once
#include <iostream>
using namespace std;

template<typename T>
class Stack
{
private:
    T* arr;
    int top;
    int capacity;

public:
    Stack(int = 10);
    ~Stack();
    
    void push(T&);
    T pop();
    T peek();

    int size();
    bool isEmpty();
    bool isFull();
};

template<typename T>
Stack<T>::Stack(const int size)
{
    arr = new T[size];
    capacity = size;
    top = -1;
}

template<typename T>
Stack<T>::~Stack()
{
    delete[] arr;
}

template<typename T>
inline void Stack<T>::push(T& value)
{
    if (isFull())
    {
        cout << "Overflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }

    arr[++top] = value;
}

template<typename T>
inline T Stack<T>::pop()
{
    if (isEmpty())
    {
        cout << "Underflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
    return arr[top--];
}

template<typename T>
inline T Stack<T>::peek()
{
    if (!isEmpty())
    {
        return arr[top];
    }
    else
    {
        exit(EXIT_FAILURE);
    }
}

template<typename T>
inline int Stack<T>::size()
{
    return top + 1;
}

template<typename T>
inline bool Stack<T>::isEmpty()
{
    return top == -1;
}

template<typename T>
inline bool Stack<T>::isFull()
{
    return top == capacity - 1;
}