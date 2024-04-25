#include <iostream>
using namespace std;

struct node
{
    char data;
    node *next;
};

void push(node *&head_refer, char data)
{

    node *new_node = new node();
    new_node->data = data;
    new_node->next = NULL;

    if (head_refer == NULL)
    {
        head_refer = new_node;
    }
    else
    {
        new_node->next = head_refer;
        head_refer = new_node;
    }
}
void pop(node *&head_refer)
{

    if (head_refer == NULL)
    {
        cout << "not found";
    }
    else
    {
        node *current = head_refer;
        head_refer = current->next;
        delete current;
    }
}

string prefixToPostfix(node *&head_refer, string prefix)
{

    string postfix = "";

    for (int a = prefix.length() - 1; a >= 0; a--)
    {
        char chaar = prefix[a];

        if (chaar >= 'a' && chaar <= 'z' || chaar >= 'A' && chaar <= 'Z')
        {
            push(head_refer, chaar);
        }
        else
        {
            char op1 = head_refer->data;
            pop(head_refer);
            char op2 = head_refer->data;
            pop(head_refer);

            string temp = "";
            temp += op1;
            temp += op2;
            temp += chaar;

            for (char c : temp)
            {
                push(head_refer, c);
            }
        }
    }
    while (head_refer != NULL)
    {
        postfix += head_refer->data;
        pop(head_refer);
    }
    return postfix;
}

int main()
{
    node *head = NULL;
    string prefixExpression = "*+AB-CD";
    cout << "prefixExpression:  " << prefixExpression << endl;

    cout << "postfixExpression  " << prefixToPostfix(head, prefixExpression) << endl;

    return 0;
}