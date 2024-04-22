#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
};

void insert(node *array[], int key, int size)
{

    int index = key % size;
    if (array[index] == NULL)
    {
        array[index] = new node();
        array[index]->data = key;
        array[index]->next = NULL;
    }
    else
    {
        node *temp = array[index];
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new node();
        temp->next->data = key;
        temp->next->next = NULL;
    }
}

void search(node *array[], int key, int size)
{
    int index = key % size;

    if (array[index]->data == key)
    {
        cout << "found";
        return;
    }
    else
    {
        node *temp = array[index];
        while (temp != NULL)
        {
            if (temp->data == key)
            {
                cout << "found";
                return;
            }
            else
            {
                temp = temp->next;
            }
        }
        cout << "not found";
    }
}
int main()
{

    const int size = 10;
    node *array[size] = {NULL};

    insert(array, 10, 10);
    insert(array, 20, 10);
    insert(array, 30, 10);
    insert(array, 40, 10);
    insert(array, 50, 10);
    insert(array, 60, 10);
    insert(array, 70, 10);
    insert(array, 80, 10);
    insert(array, 90, 10);
    insert(array, 100, 10);

     for (int i = 0; i < size; i++) {
        node* temp = array[i];
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    return 0;
}