#include <iostream>
using namespace std;

struct node{
    int data;
    node* next;
    node* prev;
};

void insert(node*& head_refer , int data){

node*new_node = new node();
new_node->data = data;
new_node->next = NULL;
new_node->prev = NULL;

if(head_refer == NULL){
    head_refer = new_node;

}

else{
    node* current = head_refer;
    while(current->next != NULL){
        current = current->next;
    }
    current->next = new_node;
    new_node->prev = current;

}
}


void deleted(node*& head_refer , int data){
    if(head_refer == NULL){
        cout<<"empty list";
    }
    else{

     node* current = head_refer;
     while(current != NULL){
       if(current->data == data){

        if(current->prev == NULL){
            head_refer = current->next;
            head_refer->prev = NULL;
            delete current;
            return;
        }
        else if(current->next == NULL){
            current->prev->next = NULL;
            delete current;
            return;
        }
        else{
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
            return;
        }
       }
       else{
        current = current->next;
       }
     }
    cout<<"not found";
    return;

    }
}

void deleteList(node*& head_refer){
     node* current = head_refer;
      node* temp = head_refer;
    while(current != NULL){
        temp = current -> next;
        delete current;
        current = temp;
    }
    head_refer = NULL;
}

void print(node* head_refer){
node* current = head_refer;
while(current != NULL){
    cout<<current->data << " ";
    current = current->next;
}
}

int length(node* head_refer){
    node* current = head_refer;
    int length = 0;
    while(current != NULL){
        length++;
        current = current->next;
    }
    return length;
}

void copyListToArray(node* head_refer , int* arr){
    node* current = head_refer;
    int i = 0;
    while(current != NULL){
        arr[i] = current->data;
        current = current->next;
        i++;  
    }
}
void copyArrayToList(node*& head_refer , int* arr , int len){
    deleteList(head_refer);
    for(int i = 0 ; i < len ; i++){
        insert(head_refer,arr[i]);
    }
}

int findPivot(int arr[] , int low , int high){
int pivot = arr[high];
int j = low-1;
for(int i = low ; i < high ; i++){
    if(arr[high] > arr[i]){
        j++;
        int temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;
    }
}
j++;
int temp = arr[j];
arr[j] = arr[high];
arr[high] = temp;
return j;
}

void quickSort(int arr[] , int low , int high){
    if(low<high){
        int pivot = findPivot(arr , low , high);
        quickSort(arr , low , pivot-1);
        quickSort(arr , pivot+1 , high);
    }
}


void sortLinkedList(node*& head_refer){
    int len = length(head_refer);
    int* arr = new int[len];

    copyListToArray(head_refer , arr);
    quickSort(arr , 0 , len-1);
    copyArrayToList(head_refer , arr , len);

}


int main(){
    
    node* head = NULL;

    insert(head , 50);
    insert(head , 20);
    insert(head , 10);
    insert(head , 60);
    insert(head , 70);
    insert(head , 30);

    cout<<"unsorted"<<endl;
    print(head);

    sortLinkedList(head);

    cout<<endl;
     cout<<"sorted"<<endl;
     print(head);
    return 0;
}
