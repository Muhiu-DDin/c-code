#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

struct QueueNode {
    Node* data;
    QueueNode* next;
};

void enQueue(QueueNode*& front_refer, QueueNode*& rear_refer, Node* data) {
    QueueNode* new_node = new QueueNode();
    new_node->data = data;
    new_node->next = NULL;

    if (front_refer == NULL && rear_refer == NULL) {
        front_refer = new_node;
        rear_refer = new_node;
    } else {
        rear_refer->next = new_node;
        rear_refer = new_node;
    }
}

Node* deQueue(QueueNode*& front_refer, QueueNode*& rear_refer) {
    if (front_refer == NULL) {
        return nullptr; // Queue is empty
    }
    QueueNode* current = front_refer;
    Node* data = current->data;
    front_refer = current->next;
    if (front_refer == NULL) {
        rear_refer = NULL;
    }
    delete current;
    return data;
}

Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return createNode(value);
    }
    QueueNode* front = nullptr;
    QueueNode* rear = nullptr;

    enQueue(front, rear, root);

    while (true) {
        Node* temp = deQueue(front, rear);

        if (temp->left != nullptr) {
            enQueue(front, rear, temp->left);
        } else {
            temp->left = createNode(value);
            return root;
        }

        if (temp->right != nullptr) {
            enQueue(front, rear, temp->right);
        } else {
            temp->right = createNode(value);
            return root;
        }
    }
}

void inOrderTraversal(const Node* root) {
    if (root == nullptr) return;
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

int main() {
    Node* root = nullptr;

 root = insert(root, 70);
    insert(root, 10);
    insert(root, 50);
    insert(root, 90);
    insert(root, 20);
    insert(root, 60);

    cout << "In-order traversal of Binary Tree: ";
    inOrderTraversal(root);

    return 0;
}
