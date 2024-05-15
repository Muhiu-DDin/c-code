#include <iostream>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
};

node* insert(node* root_refer , int data){
    if(root_refer == NULL){
        node* new_node = new node();
        new_node->data = data;
        new_node->left = NULL;
        new_node->right = NULL;
        return;
    }
    else if(root_refer->data > data){
        root_refer->left = insert(root_refer->left , data);
    }
    else{
    root_refer->right = insert(root_refer->right , data);
    }
}

void search(node* root_refer , int data){
    if(root_refer == NULL){
        cout<<"empty tree";
    }
    
    if (root_refer->data == data)
    {
        cout << "found" << endl;
        return;
    }

    else if(data > root_refer->data){
        search(root_refer->right , data);
    }
    else if(data < root_refer->data){
        search(root_refer->left , data);
    }

}




int main(){
    
    return 0;
}