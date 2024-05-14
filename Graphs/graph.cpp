#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

void enqueue(node*& rear, node*& front, int data) {
    node* new_node = new node();
    new_node->data = data;
    new_node->next = NULL;

    if (rear == NULL && front == NULL) {
        rear = new_node;
        front = new_node;
    } else {
        rear->next = new_node;
        rear = new_node;
    }
}

void dequeue(node*& rear, node*& front) {
    if (front == NULL) {
        cout << "Queue is empty." << endl;
        return;
    }

    node* current = front;
    front = current->next;
    if (front == NULL) {
        rear = NULL;
    }
    delete current;
}
// Graph structures
struct edge {
    int data;
    edge* next;
};

struct vertex {
    int data;
    vertex* next;
    edge* edgeList;
    bool visited; 
};

void insertVertex(vertex*& head_refer, int data){
    vertex* new_node = new vertex();
    new_node->data = data;
    new_node->next = NULL;
    new_node->edgeList = NULL;
    new_node->visited = false;

    if (head_refer == NULL) {
        head_refer = new_node;
    } else {
        vertex* current = head_refer;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}
void insertEdge(vertex*& head_refer, int vertexData, int data) {
    edge* new_node = new edge();
    new_node->data = data;
    new_node->next = NULL;

    vertex* current = head_refer;
    while (current != NULL) {
        if (current->data == vertexData) {
            if (current->edgeList == NULL) {
                current->edgeList = new_node;
            } else {
                edge* temp = current->edgeList;
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = new_node;
            }
            return;
        } else {
            current = current->next;
        }
    }
}

void BFS(vertex*& start ,node*& rear, node*& front){
    if (start == nullptr) return;
    start->visited = true;
    enqueue(rear, front, start->data);

    while (rear != NULL && front != NULL) {
        int currentVertexData = front->data;
        cout << currentVertexData << " ";
        dequeue(rear, front);

        vertex* currentVertex = start;
        while (currentVertex != nullptr && currentVertex->data != currentVertexData) {
            currentVertex = currentVertex->next;
        }
        edge* currentEdge = currentVertex->edgeList;
        while (currentEdge != nullptr) {
            vertex* adjacentVertex = start;
            while (adjacentVertex != nullptr && adjacentVertex->data != currentEdge->data) {
                adjacentVertex = adjacentVertex->next;
            }
            if (adjacentVertex != nullptr && adjacentVertex->visited == false) {
                 adjacentVertex->visited = true;
                enqueue(rear, front, adjacentVertex->data);
            }
            currentEdge = currentEdge->next;
        } 
    }
}

int main() {
    vertex* head = NULL;
    node* rear = nullptr;
    node* front = nullptr;

    // Adding vertices
    insertVertex(head, 0);
    insertVertex(head, 1);
    insertVertex(head, 2);
    insertVertex(head, 3);
    insertVertex(head, 4);

    // Adding edges
    insertEdge(head, 0, 1);
    insertEdge(head, 0, 2);
    insertEdge(head, 1, 2);
    insertEdge(head, 2, 0);
    insertEdge(head, 2, 3);
    insertEdge(head, 3, 3);
    insertEdge(head, 3, 4);

    BFS(head , rear , front);

    return 0;
}
