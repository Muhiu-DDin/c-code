#include <iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

node *insert(node *root, int data)
{

    if (root == NULL)
    {
        // base case
        node *new_node = new node();
        new_node->data = data;
        new_node->left = NULL;
        new_node->right = NULL;
        return new_node;
    }
    if (root->data < data)
    {
        root->right = insert(root->right, data);
    }
    else
    {
        root->left = insert(root->left, data);
    }
    return root;
}

void search(node *root, int data)
{
   if (root == NULL)
    {
        cout << "not found";
         return;
    }

    if (root->data == data)
    {
        cout << "found";
        return;
    }

    if (root->data > data)
    {
        search(root->left, data);
    }
    else
    {
        search(root->right, data);
    }
}

int main()
{

    node *root = NULL;

    // 101 , after making new node with data 101, return new_node call , which go and store to the variable root and become the root node of 101
    // This new node (with the value 101) is then returned from the insert function.
    // This returned node becomes the root of the tree and is assigned to the root pointer in the main function.
    // So, when return new_node; is called for the first time while inserting 98, the new node (101) goes back to where the insert function was initially called, which is in the main function, and it becomes the root of the tree.

    root = insert(root, 100);
    insert(root, 98);
    insert(root, 127);
    insert(root, 256);
    insert(root, 112);
    insert(root, 76);
    insert(root, 99);

    search(root , 199);
    return 0;
}