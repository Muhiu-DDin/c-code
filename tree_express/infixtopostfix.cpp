#include <iostream>;
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

int precedence(char chaar)
// ascii code used , to check the following conditions;
{
    if (chaar == '/' || chaar == '*' || chaar == '%')
    {
        return 6;
    }
    else if (chaar == '+' || chaar ==  '-')
    {
        return 5;
    }
    else if (chaar == '<' || chaar == '>' || chaar ==  '<=' || chaar ==  '>=')
    {
        return 4;
    }
    else if (chaar == '==' || chaar ==  '!=')
    {
        return 3;
    }
    else if (chaar == '&&')
    {
        return 2;
    }
    else if (chaar == '||')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

string infixToPostfix(string infix, node *&head_refer)
{
    string postfix = "";

    for (int a = 0; a < infix.length(); a++)
    {

        char chaar = infix[a];

        if ((chaar >= 'a' && chaar <= 'z') || ((chaar >= 'A' && chaar <= 'Z')))
        {
            postfix += chaar;
        }

        else if (chaar == '(')
        {
            push(head_refer , chaar);
        }

        else if (chaar == ')')
        {
            while (head_refer != NULL && head_refer->data != '(')
            {
                postfix += head_refer->data;
                pop(head_refer);
            }

             if (head_refer != NULL && head_refer->data == '(')
            {
                pop(head_refer);
            }
        }

        else
        {
            while (head_refer != NULL && precedence(chaar) <= precedence(head_refer->data))
            {

                postfix += head_refer->data;
                pop(head_refer);
            }

            push(head_refer, chaar);
        }
    }
    while(head_refer!=NULL){
        postfix += head_refer->data;
        pop(head_refer);
    }
    return postfix;
}

int main()
{
    node *head = NULL;
    string infixExpression = "a+(b*c/(x+e)*(y-x*d))";
    cout<< "infixExpression:  " << infixExpression << endl;

    cout<< "postfixExpression  "<< infixToPostfix(infixExpression , head) <<endl;
}