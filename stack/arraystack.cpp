#include <iostream>
using namespace std;

const int size = 10;
int array[size];
int top = -1;

void push(int data)
{

    if (top == size - 1)
    {
        cout << "stack overflow";
    }

    else
    {
        top++;
        array[top] = data;
    }
}

void pop()
{
    if (top == -1)
    {
        cout << "empty stack";
    }
    else
    {
        top--;
    }
}

void print()
{
    while (top != -1)
    {
        cout << array[top] << endl;
        top--;
    }
}

int main()
{

    push(10);
    push(20);
    push(30);
    push(40);
    push(50);

    pop();
    print();

    return 0;
}