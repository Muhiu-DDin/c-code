#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

void printList(node **head_refer)
{
    node *current = *head_refer;
    int index = 0;
    while (current != NULL)
    {
        cout << current->data << " at index " << index << endl;
        current = current->next;
        index++;
    }
}

void insertAtFirst(node **head_refer, int data)
{
    node *new_node = new node();
    new_node->data = data;
    new_node->next = *head_refer;
    *head_refer = new_node;
}

void insert(node **head_refer, int data)
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
        node *current = *head_refer;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_node;
    }
}


void deleteNode(node **head_refer)
{

    node *current = *head_refer;
    int to_Delete;
    cout << "enter the number you want to delete";
    cin >> to_Delete;

    node *prev = NULL;
    while (current != nullptr)
    {
        if (current->data == to_Delete)
        {
            if (current->next == nullptr)
            {
                prev->next = nullptr;
                free(current);
                return;
            }

            if (prev == NULL)
            {
                *head_refer = current->next;
                free(current);
                return;
            }

            prev->next = current->next;
            free(current);
            return;
        }

        prev = current;
        current = current->next;
    }
    cout << "not found" << endl;
}

void Deletelist(node **head_refer)
{
    node *current = *head_refer;
    node *next = *head_refer;

    while (current != NULL)
    {
        next = current->next;
        *head_refer = current->next;
        free(current);
        current = next;
    }
    *head_refer = NULL;
    cout << "list have been deleted successfully";
}

void search(node **head_refer)
{
    int to_find;
    cout << "enter your desire node" << endl;
    cin >> to_find;
    node *current = *head_refer;

    // cout<<"enter the data of new_node";
    // int data;
    // cin>>data;

    while (current != NULL)
    {

        if (current->data == to_find)
        {
            cout << "found";

            // node* new_node = new node();
            // new_node->data = data;
            // new_node->next = current->next;
            // current->next = new_node;
            return;
        }

        current = current->next;
    }
    cout << "not found";
    return;
}

int main()
{

    node *head = NULL;
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 5);

    Deletelist(&head);

    printList(&head);

    return 0;
}