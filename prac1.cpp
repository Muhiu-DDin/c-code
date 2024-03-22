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
        node *new_node = new node();
        new_node->data = data;
        new_node->left = NULL;
        new_node->right = NULL;
        return new_node;
    }

    else
    {
        if (data > root->data)
        {
            root->right = insert(root->right, data);
        }
        else
        {
            root->left = insert(root->left, data);
        }
    }

    return root;
}

void inorder(node* root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
    return;
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
    }
    else
    {
        if (data > root->data)
        {
            search(root->right, data);
        }
        else if (data < root->data)
        {
            search(root->left, data);
        }
    }
}

node *findMin(node *root)
{
    if (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

node *deletion(node *root, int data)
{
    if (root == NULL)
    {
        cout << "not found";
        return root;
    }

    else if (data > root->data)
    {
        root->right = deletion(root->right, data);
    }
    else if (data < root->data)
    {
        root->left = deletion(root->left, data);
    }

    else
    {
        if (root->right == NULL && root->left == NULL)
        {
            delete root;
            root = NULL;
        }
        else if (root->left == NULL)
        {
            node *temp = root;
            root = root->right;
            delete temp;
            return root;
        }
        else if (root->right == NULL)
        {
            node *temp = root;
            root = root->left;
            delete temp;
            return root;
        }
        else if (root->right != NULL && root->left != NULL)
        {

            node *temp = findMin(root->right);
            root->data = temp->data;
            root->right = deletion(root->right, temp->data);

        
            
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

        inorder(root);
        cout<<endl;
        root = deletion(root , 99);
          inorder(root);

        return 0;
    }