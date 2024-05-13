#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
    node *prev;
};

void insert(node **head_refer, int data)
{

    node *new_node = new node();
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;

    if (*head_refer == NULL)
    {
        *head_refer = new_node;
    }
    else
    {
        node *current = *head_refer;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_node;
        new_node->prev = current;
    }
}

void search(node **head_refer)
{

    int to_find;
    cout << "enter the number to find";
    cin >> to_find;
    int index = 0;

    node *current = *head_refer;
    while (current != NULL)
    {
        if (current->data == to_find)
        {
            cout << "found at index"
                 << " " << index;
            return;
        }
        else
        {
            current = current->next;
        }
        index++;
    }
    cout << "not_Found";
}

void deleteNode(node **head_refer)
{

    int to_delete;
    cout << "enter the no. to delete";
    cin >> to_delete;

    node *current = *head_refer;

    while (current != NULL)
    {

        if (current->data == to_delete)
        {

            if (current->prev == NULL)
            {
                *head_refer = current->next;
                current->next->prev = NULL;
                free(current);
                return;
            }
            if(current->next == NULL){
                current->prev->next = NULL;
                free(current);
                    return;
                    
            }

            current->prev->next = current->next;
            current->next->prev = current->prev;
            free(current);
            return;
        }
        else
        {
            current = current->next;
        }
    }
    cout<<"not found";
    return;
}

void deleteList(node **head_refer)
{
    node *current = *head_refer;
    node *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        delete current;
        current = next;
    }
    *head_refer = NULL;
    cout << "Double Linked List has been deleted successfully" << endl;
}


void printList(node **head_refer)
{

    node *current = *head_refer;
    while (current != NULL)
    {
        cout << current->data << endl;
        current = current->next;
    }
    cout << endl;
}

int main()
{

    node *head = NULL;
    insert(&head, 0);
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);

    deleteNode(&head);
    printList(&head);

    return 0;
}