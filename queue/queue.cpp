#include "queue.h"
#include <iostream>

template <typename t>
Queue<t>::Queue(int size)
{
    rear = -1;
    front = 0;
    capacity = size;
    data = new t[capacity];
}

template <typename t>
Queue<t>::~Queue()
{
    delete data;
}

template <typename t>
void Queue<t>::push(t element)
{
    rear = (rear + 1) % capacity;
    data[rear] = element;
    current_size++;
}

template <typename t>
t Queue<t>::pop()
{
    t ret = data[front];
    front = (front + 1) % capacity;
    current_size--;
    return ret;
}

int main()
{
    Queue<int> q(5);
    q.push(1);
    q.push(2);
    q.push(3);
    std::cout << q.pop() << std::endl;
    std::cout << q.pop() << std::endl;
    std::cout << q.pop() << std::endl;
}