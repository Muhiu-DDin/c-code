#include <iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
    int height;
};

int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int height(node *root_refer)
{
    if (root_refer == NULL)
    {
        return 0;
    }
    return max(height(root_refer->left), height(root_refer->right)) + 1;
}

int balanceFact(node *root_refer)
{
    if (root_refer == NULL)
    {
        return 0;
    }
    return (height(root_refer->left) - height(root_refer->right));
}

node *rightRotate(node *root_refer)
{
    node *y = root_refer;
    node *x = y->left;
    node *t = x->right;

    x->right = y;
    y->left = t;

    // updating hights;
    
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

node *leftRotate(node *root_refer)
{
    node *y = root_refer;
    node *x = y->right;
    node *t = x->left;

    x->left = y;
    y->right = t;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

node *insert(node *root_refer, int data)
{
    if (root_refer == NULL)
    {
        node *new_node = new node();
        new_node->data = data;
        new_node->left = NULL;
        new_node->right = NULL;
        new_node->height = 1;

        return new_node;
    }
    
    else
    {

        if (data > root_refer->data)
        {
            root_refer->right = insert(root_refer->right, data);
        }
        else
        {
            root_refer-> left = insert(root_refer->left, data);
        }
    }

    root_refer->height = 1 + max(height(root_refer->left), height(root_refer->right));
    int balance = balanceFact(root_refer); 

    // if (balance > 1 && data < root_refer->left->data)
    // {
    //     return rightRotate(root_refer);
    // }

    // if (balance < -1 && data > root_refer->right->data)
    // {
    //     return leftRotate(root_refer);
    // }

    // if (balance > 1 && data > root_refer->left->data)
    // {
    //     root_refer->left = leftRotate(root_refer->left);
    //     return rightRotate(root_refer);
    // }

    // if (balance < -1 && data < root_refer->right->data)
    // {
    //     root_refer->right = rightRotate(root_refer->right);
    //     return leftRotate(root_refer);
    // }

     // Left Left Case
        if (balance > 1 && balanceFact(root_refer->left) >= 0)
            return rightRotate(root_refer);

        // Right Right Case
        if (balance < -1 && balanceFact(root_refer->right) <= 0)
            return leftRotate(root_refer);

        // Left Right Case
        if (balance > 1 && balanceFact(root_refer->left) < 0)
        {
            root_refer->left = leftRotate(root_refer->left);
            return rightRotate(root_refer);
        }

        // Right Left Case
        if (balance < -1 && balanceFact(root_refer->right) > 0)
        {
            root_refer->right = rightRotate(root_refer->right);
            return leftRotate(root_refer);
        }

    return root_refer;
}

void search(node *root_refer, int data)
{
    if (root_refer == NULL)
    {
        cout << "not found";
        return;
    }
    if (root_refer->data == data)
    {
        cout << "found";
        return;
    }
    else
    {
        if (data > root_refer->data)
        {
            search(root_refer->right, data);
        }
        else
        {
            search(root_refer->left, data);
        }
    }
}

node *min(node *root_refer)
{
    while (root_refer->left != NULL)
    {
        root_refer = root_refer->left;
    }
    return root_refer;
}
node *deleted(node *root_refer, int data)
{
    if (root_refer == NULL)
    {
        cout << "not found";
         return root_refer;
    }

    if (data > root_refer->data)
    {
        root_refer->right = deleted(root_refer->right, data);
    }
    else if (data < root_refer->data)
    {
        root_refer->left = deleted(root_refer->left, data);
    }
    else
    {
        if (root_refer->left == NULL && root_refer->right == NULL)
        {
            delete root_refer;
            root_refer = NULL;
            return root_refer;
        }
        else if (root_refer->right != NULL && root_refer->left == NULL)
        {
            node *temp = root_refer;
            root_refer = root_refer->right;
            delete temp;
            return root_refer;
        }
        else if (root_refer->right == NULL && root_refer->left != NULL)
        {
            node *temp = root_refer;
            root_refer = root_refer->left;
            delete temp;
            return root_refer;
        }
        else
        {
            node *temp = min(root_refer->right);
            root_refer->data = temp->data;
            root_refer->right = deleted(root_refer->right, temp->data);
        }

        root_refer->height = 1 + max(height(root_refer->left), height(root_refer->right));

        int balance = balanceFact(root_refer);

        // Left Left Case
        if (balance > 1 && balanceFact(root_refer->left) >= 0)
            return rightRotate(root_refer);

        // Right Right Case
        if (balance < -1 && balanceFact(root_refer->right) <= 0)
            return leftRotate(root_refer);

        // Left Right Case
        if (balance > 1 && balanceFact(root_refer->left) < 0)
        {
            root_refer->left = leftRotate(root_refer->left);
            return rightRotate(root_refer);
        }

        // Right Left Case
        if (balance < -1 && balanceFact(root_refer->right) > 0)
        {
            root_refer->right = rightRotate(root_refer->right);
            return leftRotate(root_refer);
        }
    }
    return root_refer;
}

void inorder(node *root_refer)
{
    if (root_refer != NULL)
    {
        inorder(root_refer->left);
        cout << root_refer->data << " ";
        inorder(root_refer->right);
    }
}

int main()
{

    node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    // search(root, 205);
   root =  deleted(root, 10);

    inorder(root);
    cout << endl;

    return 0;
}
