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
    // Use the cyclic property of modulus to get the index of the rear end of the queue. Note the initial value of rear
    rear = (rear + 1) % capacity;
    data[rear] = element;
    current_size++;
}

template <typename t>
t Queue<t>::pop()
{
    // Use the cyclic property of modulus to get the index of the front end of the queue. Note the initial value of front
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