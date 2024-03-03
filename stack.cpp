#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

void push(node **head_refer, int data)
{
    node *new_node = new node();
    new_node->data = data;
    new_node->next = NULL;

    if (*head_refer == NULL)
    {
        *head_refer = new_node;
    }
    else
    {
        new_node->next = *head_refer;
        *head_refer = new_node;
    }
}

void pop(node** head_refer){
    node*current = *head_refer;
    while (current != NULL)
    {
        int num = current->data;
        *head_refer = current->next;
        free(current);
        current = *head_refer;
        cout<<num<<endl;
    }
}

void printList(node **head_refer)
{
    node *current = *head_refer;
    while (current != NULL)
    {
        cout << current->data<<endl;
        current = current->next;
    }
}

int main()
{

    node *head = NULL;
    push(&head, 0);
    push(&head, 1);
    push(&head, 2);
    push(&head, 3);

    // printList(&head);
    pop(&head);

    return 0;
}