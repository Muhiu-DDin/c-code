#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

void enqueue(node **front_refer, node **rear_refer, int data)
{

    node *new_node = new node();
    new_node->data = data;
    new_node->next = NULL;

    if (*front_refer == NULL && *rear_refer == NULL)
    {
        *front_refer = new_node;
        *rear_refer = new_node;
        new_node->next = *front_refer;
    }
    else
    {
        (*rear_refer)->next = new_node;
        new_node->next = *front_refer;
        (*rear_refer) = (*rear_refer)->next;
    }
}

void dequeue(node **front_refer , node **rear_refer)
{

    node *current = *front_refer;

    do
    {
        int num = current->data;
        *front_refer = current->next;
        (*rear_refer)->next = *front_refer;
        free(current);
        current = *front_refer;
        cout << num << endl;
    } while (current->next != *front_refer);
    cout<<current->data;
}

void printList(node **front_refer, node **rear_refer)
{
    node *current = *front_refer;

    do
    {
        cout << current->data << endl;
        current = current->next;

    } while (current != *front_refer);
}

int main()
{
    node *front = NULL;
    node *rear = NULL;

    enqueue(&front, &rear, 0);
    enqueue(&front, &rear, 1);
    enqueue(&front, &rear, 2);
    enqueue(&front, &rear, 3);

    dequeue(&front, &rear);

    return 0;
}