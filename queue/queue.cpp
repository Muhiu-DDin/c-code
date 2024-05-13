#include <iostream>
using namespace std;

struct node{
    int data;
    node* next;
};
 
void enQueue(node*& front_refer , node*& rear_refer , int data){

node* new_node = new node();
new_node-> data = data;
new_node->next = NULL;

if(front_refer == NULL && rear_refer == NULL){
    front_refer = new_node;
    rear_refer = new_node;
}
else{
     rear_refer -> next = new_node;
     rear_refer = new_node;
}
}

void deQueue(node*& front_refer , node*& rear_refer){

node* current = front_refer;

front_refer = current->next;
delete current;

}

void printQueue(node*& front_refer)
{
  node* current = front_refer;

  while(current != NULL){
    cout<< current->data<<endl;
    current = current->next;
  }
}

int main(){
    

node* rear = NULL;
 node* front = NULL;


enQueue(front , rear , 10);
enQueue(front , rear , 20);
enQueue(front , rear , 30);
enQueue(front , rear , 40);
enQueue(front , rear , 50);
enQueue(front , rear , 60);

deQueue(front , rear);

printQueue(front);


    return 0;
}