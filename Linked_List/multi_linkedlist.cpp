#include <iostream>
using namespace std;

struct student
{
    int S_ID;
    student *next;
};
struct course
{
    int C_ID;
    course *next;
    student *std;
};

void c_Insert(course *&head_refer, int C_ID)
{
    course *new_node = new course();
    new_node->C_ID = C_ID;
    new_node->next = NULL;
    new_node->std = NULL;

    if (head_refer == NULL)
    {
        head_refer = new_node;
    }
    else
    {
        course *temp = head_refer;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void s_Insert(course *&head_refer, int S_ID, int C_ID)
{

    student *new_node = new student();
    new_node->S_ID = S_ID;
    new_node->next = NULL;

    course *current = head_refer;

    while (current != NULL)
    {
        if (current->C_ID == C_ID)
        {
            if (current->std == NULL)
            {
                current->std = new_node;
            }
            else
            {
                student *ptr = current->std;
                while (ptr->next != NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next = new_node;
            }
            return;
        }
        else
        {
            current = current->next;
        }
    }
}

void deleted(course *&head_refer, int S_ID)
{

    if (head_refer == NULL)
    {
        cout << "not found";
    }
    else
    {
        course *current = head_refer;

        while (current != NULL)
        {
            student *ptr = current->std;
            student *prev = NULL;

            while (ptr != NULL)
            {
                if (ptr->S_ID == S_ID)
                {
                    if (prev == NULL)
                    {
                        current->std = ptr->next;
                        delete ptr;
                        return;
                    }
                    if (ptr->next == NULL)
                    {
                        prev->next = NULL;
                        delete ptr;
                        return;
                    }
                    else
                    {
                        prev->next = ptr->next;
                        delete ptr;
                        return;
                    }
                }

                else
                {
                    prev = ptr;
                    ptr = ptr->next;
                }
            }
            current = current->next;
        }
    }
}

void print(course *&head_refer)
{
    course *temp = head_refer;
    while (temp != NULL)
    {
        cout << temp->C_ID << " student IDs : ";

        if (temp->std != NULL)
        {
            student *current = temp->std;
            while (current != NULL)
            {
                cout << current->S_ID << " ";
                current = current->next;
            }
        }
        cout << endl;
        temp = temp->next;
    }
}

int main()
{
    course *head = NULL;

    c_Insert(head, 101);
    c_Insert(head, 102);
    c_Insert(head, 103);
    c_Insert(head, 104);
    c_Insert(head, 105);
    c_Insert(head, 106);

    s_Insert(head, 1, 101);
    s_Insert(head, 2, 101);
    s_Insert(head, 3, 102);
    s_Insert(head, 4, 102);
    s_Insert(head, 5, 101);
    s_Insert(head, 6, 101);
    s_Insert(head, 7, 101);
    s_Insert(head, 8, 101);
    s_Insert(head, 9, 102);


    deleted(head , 8 );
    print(head);

    return 0;
}