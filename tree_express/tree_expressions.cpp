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
        return;
    }
    node *current = top_refer;
    top_refer = current->next;
    delete current;
}

void printStack(node *&top_refer)
{
    node *current = top_refer;
    while (current != NULL)
    {
        cout << current->data << endl;
        current = current->next;
    }
}

int precedence(char op)
{
    if (op == '*' || op == '/' || op == '%')
        return 6;
    if (op == '+' || op == '-')
        return 5;
    if (op == '<' || op == '>' || op == '<=' || op == '=>')
        return 4;
    if (op == '==' || op == '!=')
        return 3;
    if (op == '&&')
        return 2;
    if (op == '||')
        return 1;
    return 0;
}


string infixToPostfix(node*& top_refer , string infix)
{

    string postfix = "";

    for (int a = 0; a < infix.length(); a++)
    {
        char chaar = infix[a];

        if ((chaar >= 'a' && chaar <= 'z') || (chaar >= 'A' && chaar <= 'Z') || (chaar >= '0' && chaar <= '9'))
        {
            postfix += chaar;
        }
        else if (chaar == '(')
        {
            push(top_refer , chaar);
        }
        else if (chaar == ')')
        {
            while (top_refer != NULL && top_refer->data != '(') {

                postfix += top_refer->data;
                pop(top_refer);
            }
            if(top_refer != NULL){
                pop(top_refer);
            }
        }
        else{

        while(top_refer != NULL && precedence(chaar) <= precedence(top_refer->data)){
                postfix += top_refer->data;
                pop( top_refer);
            }
            push(top_refer , chaar);
        }
    }
    while(top_refer!= NULL){
        postfix += top_refer->data;
        pop(top_refer);

    }
    return postfix;
}

int main()
{

    node *top = NULL;

     string infixExpress = "a+(b*c/(x+e)*(y-x*d))";
    cout << "Infix Expression: " << infixExpress << endl;
    cout<<"Postfix Expression:";
    string  postfixExpression = infixToPostfix(top ,infixExpress);
    cout <<  postfixExpression ;

    return 0;
}
