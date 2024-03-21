#include <iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

void push(node**top_refer , int data){

    node* new_node = new node();
    new_node->data = data;
    new_node-> next = NULL;

    if(*top_refer == NULL){
        *top_refer = new_node;
    }
    else{
        

        new_node ->next = *top_refer;
        *top_refer = new_node;

        }
    }


void pop(node** head_refer){
    node*current = *head_refer;
    while (current != NULL)
    {
        int num = current->data;
        *head_refer = current->next;
        free(current);
        current = *head_refer;
        cout<<num<<endl;
    }
}

void printList(node **head_refer)
{
    node *current = *head_refer;
    while (current != NULL)
    {
        cout << current->data<<endl;
        current = current->next;
    }
}

int main(){
    
node* top = NULL;

push(&top , 1);

    return 0;
}