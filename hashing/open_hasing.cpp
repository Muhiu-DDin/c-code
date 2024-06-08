#include <iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

void insert(node* list[] , int key , int size){
    node* new_node = new node();
    new_node->data = key;
    new_node->next = NULL;

    int index = key % size;
    if(list[index] == NULL){
        list[index] = new_node;

    }
    else{
        node* curr = list[index];
        while(curr->next!= NULL){
            curr = curr->next;
        }
        curr->next = new_node;
    }
}

void search(node* list[] , int size , int key){
    int index = key%size;
    if(list[index]->data = key){
        cout<<"found";
        return;
    }
    else{
        node* curr = list[index];
        while(curr != NULL){
            if(curr->data = key){
                cout<<"found";
                return;
            }
            curr = curr->next;
        }
        cout<<"not found";
        return;
    }
}

void print(node* list[] , int size){
    for(int a = 0 ; a < size ; a++){
            node* curr = list[a];
            while(curr!=NULL){
                cout<<curr->data<<" ";
                curr = curr->next;
            }
            cout<<"NULL";
            cout<<endl;
           
    }
}

int main(){
    int size = 10;
    node* list[size] = {NULL};

    insert(list , 30 , size);
    insert(list , 50 , size);
    insert(list , 70 , size);
    insert(list , 55 , size);
    insert(list , 53 , size);
    insert(list , 21 , size);

    print(list , size);



  

    return 0;
}