#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};


Node* insert(Node* root, int value) {
    if (root == nullptr) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }
    if (root->left == nullptr) {
        root->left = insert(root->left, value);
        if (root->left->data > root->data) {
            swap(root->left->data, root->data);
        }
    } else if (root->right == nullptr) {
        root->right = insert(root->right, value);
        if (root->right->data > root->data) {
            swap(root->right->data, root->data);
        }
    } else {
        if (root->left != nullptr) {
            root->left = insert(root->left, value);
            if (root->left->data > root->data) {
                swap(root->left->data, root->data);
            }
        } else {
            root->right = insert(root->right, value);
            if (root->right->data > root->data) {
                swap(root->right->data, root->data);
            }
        }
    }
    return root;
}


Node* inorderPre(Node*& root , int data){
Node*pre = NULL;
while(root!=NULL){
    if(root->data < data){
        pre = root;
        root = root->right;
    }
    else if(root->data > data){
        root = root->left;
    }
}
return pre;
}

Node* inorderSucc(Node*& root , int data){
Node*succ= NULL;
while(root!=NULL){
    if(root->data < data){
        root = root->right;
    }
    else if(root->data > data){
        succ = root;
        root = root->left;
    }
}
return succ;
}

void inOrderTraversal(Node* root) {
    if (root == nullptr) return;
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

int main() {
    Node* root = nullptr;

    root = insert(root, 70);
    insert(root, 10);
    insert(root, 50);
    insert(root, 90);
    insert(root, 20);
    insert(root, 60);

    cout << "In-order traversal of BST: ";
    inOrderTraversal(root);

    // int value = 50 ;
    // Node* pre = inorderPre(root , value);
    // if(pre == NULL){
    //     cout<<"no predeccessor";
    // }
    // else{
    //     cout<<"predeccessor of " << value << " is " << pre->data;
    // }

    return 0;
}
