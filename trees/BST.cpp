#include <iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};


// if we use pointer of pointer then we do not need to return nodes and the function return type would be void
// the commented return statement in the delete function is not neccessory because your are updating root in each case of deletion function , and after all  return root; which is in the last line.. return the updated root to the caller which is in the main function , and set to the root , root = deletion( , );
// but writing return root in each case is a good practice;


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
        cout << "not found" << endl;
        return;
    }

    if (root->data == data)
    {
        cout << "found" << endl;
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

void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
    return;
}

node *findMin(node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    // the min value after return will save in pointer temp
    return root;
}

node *deleted(node *root, int data)
{
    if (root == NULL)
    {
        cout << "not found";
        return root;
    }
    if (data > root->data)
    {
        root->right = deleted(root->right, data);
    }
    else if (data < root->data)
    {
        root->left = deleted(root->left, data);
    }
    else
    {
        if (root->right == NULL && root->left == NULL)
        {
            delete root;
            root = NULL;
            // return root;
        }
        else if (root->left == NULL)
        {
            node *temp = root;
            // updating the pointer of current node to its right child
            root = root->right;
            delete temp;
            // return root;
        }
        else if (root->right == NULL)
        {
            node *temp = root;
            root = root->left;
            delete temp;
            // return root;
        }
        else if (root->right != NULL && root->left != NULL)
        {

            node *temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleted(root->right, temp->data);
            //  return root; 
        }
    }
    return root;
}

int main()
{

    node *root = NULL;

    root = insert(root, 100);
    insert(root, 98);
    insert(root, 127);
    insert(root, 256);
    insert(root, 112);
    insert(root, 76);
    insert(root, 99);
    insert(root, 300);
    insert(root, 250);
    insert(root, 251);

    root = deleted(root, 251);
    inorder(root);

    return 0;
}

