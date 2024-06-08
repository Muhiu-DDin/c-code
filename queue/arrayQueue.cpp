#include <iostream>
using namespace std;

const int capacity = 10;
int queue[capacity];
int rear = -1;
int front = -1;

void enqueue(int data)
{

    if (rear == -1 && front == -1)
    {
        rear = 0;
        front = 0;
        queue[rear] = data;
    }
    else if (rear == capacity - 1)
    {
        cout << "overflow queue";
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
    cout << queue[front];
}

// or

 void print(int list[] , int rear , int front , int size){
    for(int a = front ; a <= rear ; a++){
        cout<< list[a]<<" ";
    }
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