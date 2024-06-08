#include <iostream>
#include <string>

// Define a struct for SongNode without a constructor
struct SongNode {
    std::string songName;
    SongNode* next;
    SongNode* prev;
};

// Define a struct for the Playlist (doubly linked list)
struct Playlist {
    SongNode* head;
    SongNode* tail;
};

// Define a struct for StackNode
struct StackNode {
    SongNode* song;
    StackNode* next;
};

// Define a struct for the Stack
struct Stack {
    StackNode* top;
};

// Define a struct for QueueNode
struct QueueNode {
    SongNode* song;
    QueueNode* next;
};

// Define a struct for the Queue
struct Queue {
    QueueNode* front;
    QueueNode* rear;
};

// Initialization functions for each data structure
void initializePlaylist(Playlist& playlist) {
    playlist.head = nullptr;
    playlist.tail = nullptr;
}

void initializeStack(Stack& stack) {
    stack.top = nullptr;
}

void initializeQueue(Queue& queue) {
    queue.front = nullptr;
    queue.rear = nullptr;
}

// Function to create a new song node
SongNode* createSongNode(const std::string& name) {
    SongNode* newSong = new SongNode;
    newSong->songName = name;
    newSong->next = nullptr;
    newSong->prev = nullptr;
    return newSong;
}

// Playlist functions
void addSongToPlaylist(Playlist& playlist, const std::string& name) {
    SongNode* newSong = createSongNode(name);
    if (!playlist.head) {
        playlist.head = playlist.tail = newSong;
    } else {
        playlist.tail->next = newSong;
        newSong->prev = playlist.tail;
        playlist.tail = newSong;
    }
}

void displayPlaylist(const Playlist& playlist) {
    SongNode* current = playlist.head;
    while (current) {
        std::cout << current->songName << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

SongNode* removeHeadFromPlaylist(Playlist& playlist) {
    if (!playlist.head) return nullptr;
    SongNode* temp = playlist.head;
    playlist.head = playlist.head->next;
    if (playlist.head) {
        playlist.head->prev = nullptr;
    } else {
        playlist.tail = nullptr;
    }
    return temp;
}

// Stack functions
void push(Stack& stack, SongNode* songNode) {
    StackNode* newNode = new StackNode;
    newNode->song = songNode;
    newNode->next = stack.top;
    stack.top = newNode;
}

SongNode* pop(Stack& stack) {
    if (!stack.top) return nullptr;
    StackNode* temp = stack.top;
    stack.top = stack.top->next;
    SongNode* song = temp->song;
    delete temp;
    return song;
}

bool isStackEmpty(const Stack& stack) {
    return stack.top == nullptr;
}

// Queue functions
void enqueue(Queue& queue, SongNode* songNode) {
    QueueNode* newNode = new QueueNode;
    newNode->song = songNode;
    newNode->next = nullptr;
    if (!queue.rear) {
        queue.front = queue.rear = newNode;
    } else {
        queue.rear->next = newNode;
        queue.rear = newNode;
    }
}

SongNode* dequeue(Queue& queue) {
    if (!queue.front) return nullptr;
    QueueNode* temp = queue.front;
    queue.front = queue.front->next;
    if (!queue.front) queue.rear = nullptr;
    SongNode* song = temp->song;
    delete temp;
    return song;
}

bool isQueueEmpty(const Queue& queue) {
    return queue.front == nullptr;
}

// Playlist Manager functions
void playNextSong(Playlist& playlist, Stack& history, Queue& upcoming) {
    if (playlist.head) {
        push(history, playlist.head);
        removeHeadFromPlaylist(playlist);
    }
    if (!playlist.head && !isQueueEmpty(upcoming)) {
        playlist.head = dequeue(upcoming);
        playlist.head->prev = nullptr;
    }
}

void playPreviousSong(Playlist& playlist, Stack& history) {
    if (!isStackEmpty(history)) {
        SongNode* prevSong = pop(history);
        prevSong->next = playlist.head;
        if (playlist.head) {
            playlist.head->prev = prevSong;
        }
        playlist.head = prevSong;
    }
}

int main() {
    Playlist playlist;
    Stack history;
    Queue upcoming;

    initializePlaylist(playlist);
    initializeStack(history);
    initializeQueue(upcoming);

    int choice;
    std::string songName;

    while (true) {
        std::cout << "\n1. Add Song to Playlist\n2. Display Current Playlist\n3. Play Next Song\n4. Play Previous Song\n5. Add Song to Queue\n6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter song name: ";
                std::cin.ignore();
                std::getline(std::cin, songName);
                addSongToPlaylist(playlist, songName);
                break;

            case 2:
                std::cout << "Current Playlist: ";
                displayPlaylist(playlist);
                break;

            case 3:
                playNextSong(playlist, history, upcoming);
                break;

            case 4:
                playPreviousSong(playlist, history);
                break;

            case 5:
                std::cout << "Enter song name: ";
                std::cin.ignore();
                std::getline(std::cin, songName);
                SongNode* newSong = createSongNode(songName);
                enqueue(upcoming, newSong);
                break;

            case 6:
                std::cout << "Exiting..." << std::endl;
                return 0;

            default:
                std::cout << "Invalid choice!" << std::endl;
                break;
        }
    }

    return 0;
}
