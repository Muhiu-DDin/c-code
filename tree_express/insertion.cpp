#include <iostream>
using namespace std;

struct node
{
    // using double linked list
    char data;
    node *left, *right;
};

void push(node *&top_refer, node *&new_node_refer)
{

    if (top_refer == NULL)
    {
        top_refer = new_node_refer;
    }
    else
    {
        new_node_refer->right = top_refer;
        top_refer->left = new_node_refer;
        top_refer = new_node_refer;
    }
}

void pop(node *&top_refer)
{
    if (top_refer == NULL)
    {
        cout << "empty stack";
    }
    else
    {
        node *current = top_refer;
        top_refer = current->right;
        if (top_refer != NULL)
        {
            top_refer->left = NULL;
        }
        delete current;
    }
}

void insertion(node *&head_refer, string postfix)
{
    for (int a = 0; a < postfix.length(); a++)
    {
        char data = postfix[a];
        if ((data >= 'a' && data <= 'z') || (data >= 'A' && data <= 'Z'))
        {
            node *new_node = new node();
            new_node->data = data;
            new_node->left = NULL;
            new_node->right = NULL;

            push(head_refer, new_node);
        }
        else
        {
            // by using pointer you have the data , left child and the right child of the node which is crucial for the tree, by just using variable ap1 it just store the data of the node not its child

            node *op1 = head_refer;
            pop(head_refer);
            node *op2 = head_refer;
            pop(head_refer);

            node *new_node = new node();
            new_node->data = data;
            new_node->right = op1;
            new_node->left = op2;

            push(head_refer, new_node);
        }
    }
}

int main()
{
    string postfix = "ab+";
    node *head = NULL;
    insertion(head, postfix);
    return 0;
}
