#include <iostream>
using namespace std;

const int capacity = 10;
int queue[capacity];
int rear = -1;
int front = -1;

void enqueue(int data)
{

    if (rear == capacity - 1)
    {
        cout << "overflow queue";
    }

    else if (rear == -1 && front == -1)
    {
        rear = 0;
        front = 0;
        queue[rear] = data;
    }
    else
    {
        rear++;
        queue[rear] = data;
    }
}

void dequeue()
{
    if (rear == -1 && front == -1)
    {
        cout << "empty queue";
    }
    else if (rear == front)
    {
        rear = -1;
        front = -1;
    }
    else
    {
        front++;
    }
}

void print()
{
    // we can also use for loop;
    while (front != rear)
    {
        cout << queue[front];
        front++;
    }
    cout<<queue[front];
}

int main()
{

    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);

    print();

    return 0;
}