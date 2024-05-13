#include <iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

void insert(node*& head_refer , int data){
    node* new_node = new node();
    new_node->data = data;
    new_node->next = NULL;

    if(head_refer == NULL){
        head_refer = new_node;
    }
    else{
        node* current = head_refer;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = new_node;
    }
}

void search (node*& head_refer , int data)
{
    if(head_refer == NULL){
        cout<<"empty list";
        return;
    }
    else{
        node* current = head_refer;
        int i = 0;
        while(current != NULL){

            if(current->data == data){
                cout<< endl << "found at index" << " " << i ;
                return;
            }
            else{
                current = current->next;
                i++;
            }
        }
         cout<< endl << "not found";
    }
}
// if head_refer changes , then we have to pass pointer of pointer of refence to a pointer , in the case where head node is to be deleted then the code will no work because deleting head lead to change head pointer , whilte the other cases like last node or middle , head refer is not changing therefore then the code will work for these two cases but not for delteing head

void deleted(node* head_refer , int data){

    if(head_refer == NULL){
        cout<<"empty list";
        return;
    }
    else{
        node* prev = NULL;
        node* current = head_refer;

        while(current != NULL){

        if(current->data == data){

        if(prev == NULL){
        head_refer = current->next;
        delete current;
        return;
        } 

        else if(current->next == NULL){
            prev->next = NULL;
            delete current;
            return;
        }
        else{
            prev->next = current->next;
            delete current;
            return;
        }
        }
        else{
            prev = current;
            current = current->next;
        }
        }
        cout<<"not found";
        return;
    }
}

void deleteAll(node*& head_refer){
      node* current = head_refer;
      node* temp = head_refer;

      while(current != NULL){
        current = temp->next;
        head_refer = temp->next;
        delete temp;
         temp = current;
      }
      head_refer = NULL;
      cout<<"list deleted sucessfully";
}

void print(node*& head_refer){
   node* current = head_refer;
   int i = 0;
   while(current != NULL){
    cout<<current->data << " ";
    i++;
    current = current->next;
   }
   cout<<"no. of nodes are"<<" "<<i;
}

int main(){
    
    node* head = NULL;
    insert(head , 10);
    insert(head , 20);
    insert(head , 30);
    insert(head , 40);
    insert(head , 50);
    insert(head , 60);
    insert(head , 70);


    deleted(head , 60);
    // deleteAll(head);
    print(head);
    // search(head , 100);
    
    return 0;
}