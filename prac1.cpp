#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

void enqueue(node*& front, node*& rear, int data) {
    node* new_node = new node();
    new_node->data = data;
    new_node->next = NULL;
    if (front == NULL && rear == NULL) {
        front = new_node;
        rear = new_node;
    } else {
        rear->next = new_node;
        rear = new_node;
    }
}

void dequeue(node*& front, node*& rear) {
    if (front == NULL) return;

    node* temp = front;
    front = front->next;
    if (front == NULL) {
        rear = NULL;
    }
    delete temp;
}

struct edge {
    int data;
    edge* next;
};

struct vertex {
    int data;
    bool visited;
    int parent; // To store the parent vertex
    vertex* next;
    edge* edgeList;
};

void insertVertex(vertex*& head, int data) {
    vertex* new_node = new vertex();
    new_node->data = data;
    new_node->visited = false;
    new_node->parent = -1; // Initialize parent to -1
    new_node->edgeList = NULL;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        vertex* curr = head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = new_node;
    }
}

void insertEdge(vertex* head, int vertexData, int data) {
    edge* new_node = new edge();
    new_node->data = data;
    new_node->next = NULL;
    if (head == NULL) {
        return;
    } else {
        vertex* curr = head;
        while (curr != NULL) {
            if (curr->data == vertexData) {
                if (curr->edgeList == NULL) {
                    curr->edgeList = new_node;
                } else {
                    edge* temp = curr->edgeList;
                    while (temp->next != NULL) {
                        temp = temp->next;
                    }
                    temp->next = new_node;
                }
                return;
            } else {
                curr = curr->next;
            }
        }
    }
}

void BFS(vertex* head) {
    if (head == NULL) return;

    node* front = NULL;
    node* rear = NULL;

    enqueue(front , rear , head->data);
    head->visited = true;
    while(front!=NULL){
        int currVertexData = front->data;
        dequeue(front , rear),
        cout<<currVertexData<<" ";

        vertex* currVertex = head;
        while(currVertex != NULL && currVertex->data != currVertexData){
            currVertex = currVertex->next;
        }
        if(currVertex!=NULL){
            edge* currEdge = currVertex->edgeList;
            while(currEdge!=NULL){
                vertex* adjacent = head;
                while(adjacent!=NULL && adjacent->data != currEdge->data){
                    adjacent = adjacent->next;
                }
                if(adjacent != NULL && adjacent->visited == false){
                    enqueue(front, rear , adjacent->data);
                    adjacent->visited = true;
                    adjacent->parent = currVertex->data; // Record the parent
                }
                currEdge = currEdge->next;
            }
        }

    }
}

void printPath(vertex* start, vertex* end) {
    if (start == nullptr || end == nullptr) return;

    cout << "Path from " << start->data << " to " << end->data << ": ";
    while (end->data != start->data) {
        cout << end->data << " ";
        end = end->next;
    }
    cout << start->data << endl;
}

int main() {
    vertex* head = NULL;

    // Add vertices
    insertVertex(head, 1);
    insertVertex(head, 2);
    insertVertex(head, 3);
    insertVertex(head, 4);
    insertVertex(head, 5);
     
    // Add edges
    insertEdge(head, 1, 2);
    insertEdge(head, 1, 3);
    insertEdge(head, 2, 4);
    insertEdge(head, 3, 4);
    insertEdge(head, 4, 5);

    // Perform BFS starting from the first vertex in the list
    BFS(head);

    // Find and print path from vertex 1 to vertex 5
    vertex* startVertex = head;
    vertex* endVertex = head;
    while (endVertex != nullptr && endVertex->data != 5) {
        endVertex = endVertex->next;
    }

    printPath(startVertex, endVertex);

    return 0;
}
