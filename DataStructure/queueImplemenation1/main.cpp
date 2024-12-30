#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;
    Node(int val) {
        value = val;
        next = nullptr;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (front == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    int dequeue() {
        if (front == nullptr) {
            cout << "Queue Underflow" << endl;
            return -1;
        }
        Node* temp = front;
        int removedValue = front->value;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
        return removedValue;
    }

    int peek() {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return front->value;
    }

    void display() {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
            return;
        }
        Node* current = front;
        while (current) {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Queue queue;
    cout<<"Enqueue in Queue"<<endl;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.display();
     cout<<"Dequeue from Queue"<<endl;
    cout << queue.dequeue() << endl;
    cout<<"Display peek in Queue"<<endl;
    cout << queue.peek() << endl;
    cout<<"Display Queue"<<endl;
    queue.display();

    cout << queue.dequeue() << endl;
    cout << queue.dequeue() << endl;
    cout << queue.dequeue() << endl;
    return 0;
}
