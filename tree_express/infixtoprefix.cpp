#include <iostream>
using namespace std;

struct node
{
    char data;
    node *next;
};

void push(node *&top_refer, char data)
{
    node *new_node = new node();
    new_node->data = data;
    new_node->next = NULL;

    if (top_refer == NULL)
    {
        top_refer = new_node;
    }
    else
    {
        new_node->next = top_refer;
        top_refer = new_node;
    }
}

void pop(node *&top_refer)
{
    if (top_refer == NULL)
    {
        cout << "empty stack";
    }
    else
    {
        node *current = top_refer;
        top_refer = current->next;
        delete current;
    }
}

int precedence(char chaar)
{
    if (chaar == '/' || chaar == '*' || chaar == '%')
    {
        return 6;
    }
    else if (chaar == '+' || chaar == '-')
    {
        return 5;
    }
    else if (chaar == '>' || chaar == '<' || chaar == '>=' || chaar == '<=')
    {
        return 4;
    }
    else if (chaar == '==' || chaar == '!=')
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

string infixToPrefix(node *&top_refer, string infix)
{
    string prefix = "";

    for (int a = infix.length() - 1; a >= 0; a--)
    {
        char chaar = infix[a];

        if ((chaar >= 'a' && chaar <= 'z') || (chaar >= 'A' && chaar <= 'Z'))
        {
            // prepending
            prefix = chaar + prefix; 
        }
        else if (chaar == ')')
        {
            push(top_refer, chaar);
        }
        else if (chaar == '(')
        {
            while (top_refer != NULL && top_refer->data != ')')
            {
                prefix = top_refer->data + prefix;
                pop(top_refer);
            }
            // removing ')'
            if (top_refer != NULL && top_refer->data == ')')
            {
                pop(top_refer);
            }
        }
        else
        {
            while (top_refer != NULL && precedence(chaar) < precedence(top_refer->data))
            {
                prefix = top_refer->data + prefix;
                pop(top_refer);
            }
            push(top_refer, chaar);
        }
    }
    // emptying stack;
    while (top_refer != NULL)
    {
        prefix = top_refer->data + prefix;
        pop(top_refer);
    }

    return prefix;
}



int main()
{
    node *top = NULL;
    string infixExpression = "a+(b*c/(x+e)*(y-x*d))";
    cout << "infixExpression:  " << infixExpression << endl;

    cout << "prefixExpression  " << infixToPrefix(top, infixExpression) << endl;
}

