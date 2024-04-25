#include <iostream>
using namespace std;

const int size = 10;
int array [size];
int rear = -1;
int front = -1;

void enqueue(int data){
    if(rear ==-1 && front == -1){
        rear = 0;
        front = 0;
        array[rear] = data;
    }
    else if( (rear+1)%size == front){
        cout<<"overflow queue";
        return;
    }
    else{
        rear = (rear+1)%size;
        array[rear] = data;
    }
}
void dequeue(){
    if(rear == -1 && front == -1){
        cout<<"empty queue";
    }
    else if(rear == front){
        rear = -1;
        front = -1;
    }
    else{
        front = (front+1)%size;
    }
}
void print(){
    while(front!=rear){
        cout<<array[front];
        front = (front+1)%size;
    }
    cout<<array[front];
}

















int main(){
    

    return 0;
}