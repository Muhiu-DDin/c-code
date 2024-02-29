#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

void insert(node **head_refer, int data)
{
    node *new_node = new node();
    new_node->data = data;
    new_node->next = NULL;

    if (*head_refer == NULL)
    {
        *head_refer = new_node;
        new_node->next = *head_refer;
    }
    else
    {
        node *current = *head_refer;
        while (current->next != *head_refer)
        {
            current = current->next;
        }
        current->next = new_node;
        new_node->next = *head_refer;
    }
}

void search(node **head_refer)
{
    cout << "enter the number to find";
    int to_find;
    cin >> to_find;

    node *current = *head_refer;

    do
    {
        if (current->data == to_find)
        {
            cout << "found";
            return;
        }
        else
        {
            current = current->next;
        }

    } while (current != *head_refer);

    cout << "not found";
}

void Delete(node **head_refer)
{

    cout << "enter the no. to delete";

    int to_Delete;
    cin >> to_Delete;

    node *current = *head_refer;
    node *prev = NULL;
    do
    {
        if (current->data == to_Delete)
        {

            if (prev == NULL)
            {
                node *temp = *head_refer;

                while (temp->next != *head_refer)
                {
                    temp = temp->next;
                }

                temp->next = current->next;
                *head_refer = current->next;
                free(current);
                return;
            }

            else
            {
                prev->next = current->next;
                free(current);
                return;
            }
        }

        else
        {
            prev = current;
            current = current->next;
        }

    } while (current != *head_refer);

    cout << "not found";
}

void Deletelist(node** head_refer){

node* current = *head_refer;
node* next = NULL;
do{
    next = current->next;
    *head_refer = next;
    free(current); 
    current = next;

}  while(current!=*head_refer);
*head_refer =NULL;
cout<<"circular list have been deleted successfully";
}


void printList(node **head_refer)
{
    node *current = *head_refer;
    // if we use current -> next != *head_refer then the last element will not be print and then we use while loop not do while loop
    do
    {
        cout << current->data << endl;
        current = current->next;
    } while (current != *head_refer);
}

int main()
{

    node *head = NULL;
    insert(&head, 0);
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);

    Deletelist(&head);
    printList(&head); 

    return 0;
} 