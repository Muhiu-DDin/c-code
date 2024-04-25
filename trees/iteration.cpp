#include <iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

node *insert(node *root_refer, int data)
{

    node *new_node = new node();
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    if (root_refer == NULL)
    {
        root_refer = new_node;
        return root_refer;
    }

    else
    {
        node *current = root_refer;
        while (true)
        {
            if (data > current->data)
            {
                if (current->right == NULL)
                {
                    current->right = new_node;
                    return root_refer;
                }
                else
                {
                    current = current->right;
                }
            }

            else if (data < current->data)
            {
                if (current->left == NULL)
                {
                    current->left = new_node;
                    return root_refer;
                }
                else
                {
                    current = current->left;
                }
            }
            else
            {
                delete new_node;
                return root_refer;
            }
        }
    }
    return root_refer;
}

void search(node *root_refer, int data)
{
    if (root_refer == NULL)
    {
        cout << "not found";
        return;
    }

    else
    {
        node *current = root_refer;
        while (current != NULL)
        {
            if (current->data == data)
            {
                cout << "found";
                return;
            }

            else if (current->data < data)
            {

                current = current->right;
            }

            else
            {

                current = current->left;
            }
        }

        cout << "not found";
    }
}

node *findMin(node *current)
{
    while (current->left != NULL)
    {
        current = current->left;
    }
    return current;
}

node *deleted(node *root_refer, int data)
{

    if (root_refer == NULL)
    {
        cout << "not found";
        return root_refer;
    }

    node *current = root_refer;
    node *parent = NULL;

    while (current != NULL)
    {
        if (data > current->data)
        {
            parent = current;
            current = current->right;
        }
        else if (data < current->data)
        {
            parent = current;
            current = current->left;
        }
        else
        {
            if (current->left == NULL && current->right == NULL)
            {
                // if the deleted root is root of the tree
                if (parent == NULL)
                {
                    delete current;
                    return root_refer;
                }
                if (parent->right == current)
                {
                    delete current;
                    parent->right = NULL;
                     return root_refer;
                }
                if (parent->left == current)
                {
                    delete current;
                    parent->left = NULL;
                     return root_refer;
                }
                //   return root_refer;
            }
            else if (current->left == NULL && current->right != NULL)
            {
                if (parent == NULL)
                {
                    root_refer = current->right;
                    delete current;
                    return root_refer;
                }
                if (parent->right == current)
                {
                    parent->right = current->right;
                    delete current;
                    return root_refer;
                }
                else if (parent->left == current)
                {
                    parent->left = current->right;
                    delete current;
                    return root_refer;
                }
                //   return root_refer;
            }

            else if (current->left != NULL && current->right == NULL)
            {
                if (parent == NULL)
                {
                    root_refer = current->left;
                    delete current;
                    return root_refer;
                }
                if (parent->right == current)
                {
                    parent->right = current->left;
                    delete current;
                    return root_refer;
                }
                else if (parent->left == current)
                {
                    parent->left = current->left;
                    delete current;
                    return root_refer;
                }
                //   return root_refer;
            }
            else
            {
                node *temp = findMin(root_refer->right);
                current->data = temp->data;
                current->right = deleted(current->right, temp->data);
                return root_refer;
            }
        }
    }
    return root_refer;
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

    root = deleted(root , 127);
    inorder(root);
    return 0;
}