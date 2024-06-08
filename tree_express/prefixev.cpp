#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};

void push(node *&top_refer, int data)
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


int postfixEv(node*& head , const string& postfix){
for(int a = postfix.length() ; a >= 0 ; a--){
    char c = postfix[a];
    if(c >= '0' && c <= '9'){
        push(head , c - '0');
    }
    else{
        int op1 = head->data;
        pop(head);
        int op2 = head->data;
        pop(head);
        int result;
        switch (c){
            case '+' : result = op1 + op2;
            break;
            case '-' : result = op1 - op2;
            break;
             case '*' : result = op1 * op2;
            break;
        }
        push(head , result);
    }

}
return head->data;
}

int main(){
    node* head = NULL;
    
    string postfix = "10+5-*";
    cout<<postfixEv(head , postfix);
    return 0;
}

