#include <iostream>
using namespace std;

struct student
{
    int seat_No;
    student *std_next;
};

struct course
{
    int course_No;
    course *cour_next;
    student *std;
};

void cour_Insert(course **head_refer, int course_No)
{
    course *new_node = new course();
    new_node->course_No = course_No;
    new_node->cour_next = NULL;
    new_node->std = NULL;

    if (*head_refer == NULL)
    {
        *head_refer = new_node;
    }
    else
    {
        course *current = *head_refer;
        while (current->cour_next != NULL)
        {
            current = current->cour_next;
        }
        current->cour_next = new_node;
    }
}

void printList(course **head_refer)
{
    course *current = *head_refer;
    while (current != NULL)
    {
         cout << "Course " << current->course_No << ": ";
      

        if (current->std != NULL)
        {
            cout<<"students:"<<" ";
            student *curr = current->std;
            while (curr != NULL)
            {
                cout << curr->seat_No << " ";
                curr = curr->std_next;
            }
        }
        cout<<endl;
        current = current->cour_next;
    }
}

void std_Insert(course **head_refer, int course_No, int seat_No)
{
    student *new_node = new student();
    new_node->seat_No = seat_No;
    new_node->std_next = NULL;

    course *current = *head_refer;

    while (current != NULL)
    {

        if (current->course_No == course_No)
        {

            if (current->std == NULL)
            {

                current->std = new_node;
            }
            else
            {
                student *temp = current->std;

                while (temp->std_next != NULL)
                {
                    temp = temp->std_next;
                }

                temp->std_next = new_node;
            }

            return;
        }

        current = current->cour_next;
    }
    cout<<"course not found";
}

int main()
{

    course *head = NULL;
    cour_Insert(&head, 413);
    cour_Insert(&head, 543);
    cour_Insert(&head, 114);
    cour_Insert(&head, 725);
    cour_Insert(&head, 291);

    std_Insert(&head, 114, 23);
    std_Insert(&head, 543, 23);
    std_Insert(&head, 291, 23);
    std_Insert(&head, 543, 02);
    std_Insert(&head, 543, 42);
    std_Insert(&head, 543, 06);
    std_Insert(&head, 543, 56);

    printList(&head);

    return 0;
}