void BFS(vertex* head) {
    if (head == NULL) return;

    node* front = NULL;
    node* rear = NULL;

    // Start BFS from the head vertex
    enqueue(front, rear, head->data);
    head->visited = true;

    while (front != NULL) {
        int currentVertexData = front->data;
        dequeue(front, rear); // Move dequeue here
        cout << currentVertexData << " ";

        vertex* currentVertex = head;
        while (currentVertex != NULL && currentVertex->data != currentVertexData) {
            currentVertex = currentVertex->next;
        }

        if (currentVertex != NULL) {
            edge* currentEdge = currentVertex->edgeList;
            while (currentEdge != NULL) {
                vertex* adjacentVertex = head;
                while (adjacentVertex != NULL && adjacentVertex->data != currentEdge->data) {
                    adjacentVertex = adjacentVertex->next;
                }

                if (adjacentVertex != NULL && !adjacentVertex->visited) {
                    enqueue(front, rear, adjacentVertex->data);
                    adjacentVertex->visited = true;
                }
                currentEdge = currentEdge->next;
            }
        }
    }
}