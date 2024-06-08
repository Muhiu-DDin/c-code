#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    float value;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* createNode(float value) {
    TreeNode* newNode = new TreeNode;
    newNode->value = value;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

void insertNode(TreeNode* &root, float value) {
    if (root == nullptr) {
        root = createNode(value);
        return;
    }
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();
        if (temp->left == nullptr) {
            temp->left = createNode(value);
            return;
        }
        else {
            q.push(temp->left);
        }
        if (temp->right == nullptr) {
            temp->right = createNode(value);
            return;
        }
        else {
            q.push(temp->right);
        }
    }
}

bool searchNode(TreeNode* root, float x) {
    if (root == nullptr)
        return false;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();
        if (temp->value == x)
            return true;
        if (temp->left != nullptr)
            q.push(temp->left);
        if (temp->right != nullptr)
            q.push(temp->right);
    }
    return false;
}

void findPredecessors(TreeNode* root, float x, vector<float>& predecessors) {
    if (root == nullptr)
        return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();
        if (temp->value < x) {
            predecessors.push_back(temp->value);
        }
        if (temp->left != nullptr)
            q.push(temp->left);
        if (temp->right != nullptr)
            q.push(temp->right);
    }
}

void findSuccessors(TreeNode* root, float x, vector<float>& successors) {
    if (root == nullptr)
        return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();
        if (temp->value > x) {
            successors.push_back(temp->value);
        }
        if (temp->left != nullptr)
            q.push(temp->left);
        if (temp->right != nullptr)
            q.push(temp->right);
    }
}

int countNodes(TreeNode* root) {
    if (root == nullptr){
        return 0;    
    }
    queue<TreeNode*> q;
    q.push(root);
    int count = 0;
    while (!q.empty()) {
        TreeNode* temp = q.front();
        q.pop();
        count++;
        if (temp->left != nullptr)
            q.push(temp->left);
        if (temp->right != nullptr)
            q.push(temp->right);
    }
    return count;
}

int main() {
    TreeNode* root = nullptr;

    insertNode(root, 5);
    insertNode(root, 3);
    insertNode(root, 7);
    insertNode(root, 2);
    insertNode(root, 4);
    insertNode(root, 6);
    insertNode(root, 8);

    float x = 6;
    if (searchNode(root, x)) {
        cout << x << " found" << endl;
    } else {
        cout << x << "not found" << endl;
    }

    vector<float> predecessors;
    findPredecessors(root, x, predecessors);
    cout << "Predecessors of " << x << ": ";
    for (float pred : predecessors) {
        cout << pred << " ";
    }
    cout << endl;

    vector<float> successors;
    findSuccessors(root, x, successors);
    cout << "Successors of " << x << ": ";
    for (float succ : successors) {
        cout << succ << " ";
    }
    cout << endl;

    return 0;
}
