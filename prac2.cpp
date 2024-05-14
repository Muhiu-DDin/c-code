#include <iostream>
#include <queue>
using namespace std;

// Queue implementation
struct QueueNode {
    int data;
    QueueNode* next;
};

struct Queue {
    QueueNode* front;
    QueueNode* rear;
};

Queue* createQueue() {
    Queue* q = new Queue();
    q->front = q->rear = nullptr;
    return q;
}

void enqueue(Queue* q, int data) {
    QueueNode* newNode = new QueueNode();
    newNode->data = data;
    newNode->next = nullptr;

    if (q->rear == nullptr) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

void dequeue(Queue* q) {
    if (q->front == nullptr) {
        cout << "Queue is empty." << endl;
        return;
    }
    QueueNode* temp = q->front;
    q->front = q->front->next;
    delete temp;
    if (q->front == nullptr) {
        q->rear = nullptr;
    }
}

int peek(Queue* q) {
    if (q->front == nullptr) {
        cout << "Queue is empty." << endl;
        return -1; // Return some default value indicating queue is empty
    }
    return q->front->data;
}

bool isEmpty(Queue* q) {
    return q->front == nullptr;
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
    int parent; // Store parent vertex for path reconstruction
};

void insertVertex(vertex*& head_refer, int data){
    vertex* new_node = new vertex();
    new_node->data = data;
    new_node->next = NULL;
    new_node->edgeList = NULL;
    new_node->visited = false;
    new_node->parent = -1; // Initialize parent to -1 (indicating no parent)

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

void getPath(vertex* start, vertex* end, int path[], int& pathLength) {
    int currentVertex = end->data;
    while (currentVertex != -1) {
        path[pathLength++] = currentVertex;
        vertex* current = start;
        while (current != nullptr && current->data != currentVertex) {
            current = current ->next;
        }
        currentVertex = current->parent;
    }
}

void BFS(vertex*& start) {
    if (start == nullptr) return;

    start->visited = true; 
    start->parent = -1;

    Queue* q = createQueue();
    enqueue(q, start->data);

    while (!isEmpty(q)) {
        int currentVertexData = peek(q);
        dequeue(q);

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
            if (adjacentVertex != nullptr && !adjacentVertex->visited) {
                adjacentVertex->visited = true;
                adjacentVertex->parent = currentVertex->data; // Set parent for path reconstruction
                enqueue(q, adjacentVertex->data);
            }
            currentEdge = currentEdge->next;
        }
    }
}

int main() {
    vertex* head = NULL;

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

    // Perform BFS
    BFS(head);

    // Path between vertex 0 and vertex 4
    int path[100]; // Assuming maximum path length
    int pathLength = 0;
    vertex* start = head;
    vertex* end = head;
    while (start != nullptr && start->data != 0) {
        start = start->next;
    }
    while (end != nullptr && end->data != 4) {
        end = end->next;
    }
    getPath(head, end, path, pathLength);
    
    // Print the path
    cout << "\nPath from 0 to 4: ";
    for (int i = pathLength - 1; i >= 0; --i) {
        cout << path[i] << " ";
    }
    cout << endl;

    return 0;
}
