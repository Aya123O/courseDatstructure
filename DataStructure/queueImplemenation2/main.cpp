#include <iostream>
using namespace std;

class Queue {
private:
    int* arr;
    int front;
    int rear;
    int size;
    int count;

public:
    Queue(int capacity) {
        if (capacity <= 0) {
            cout << "Invalid capacity! Capacity should be a positive integer.\n";
            return;
        }

        size = capacity;
        front = 0;
        rear = -1;
        count = 0;


        arr = new int[size];
    }

    ~Queue() {
        delete[] arr;
    }


    void enqueue(int value) {
        if (count == size) {
            cout << "Queue Overflow" << endl;
            return;
        }


        if (rear == size - 1) {
            rear = 0;
        } else {
            rear++;
        }

        arr[rear] = value;
        count++;
    }

    int dequeue() {
        if (count == 0) {
            cout << "Queue Underflow" << endl;
            return -1;
        }

        int removedValue = arr[front];
        if (front == size - 1) {
            front = 0;
        } else {
            front++;
        }
        count--;
        return removedValue;
    }


    int peek() {
        if (count == 0) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }


    void display() {
        if (count == 0) {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Queue elements: ";
        int index = front;
        for (int i = 0; i < count; i++) {
            cout << arr[index] << " ";
            if (index == size - 1) {
                index = 0;
            } else {
                index++;
            }
        }
        cout << endl;
        cout << "Front: " << arr[front] << ", Rear: " << arr[rear] << endl;
    }
    //////////////////////////////////////////////////////////reverse////////////////////////////////////////////////////////////////////
    void display2() {
        if (count == 0) {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Queue elements: ";
        int index = rear;
        for (int i = 0; i < count; i++) {
            cout << arr[index] << " ";
            if (index == 0) {
                index = size -1;
            } else {
                index--;
            }
        }
        cout << endl;
    }
};

int main() {
    int capacity = 5;
    Queue queue(capacity);


    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    queue.enqueue(50);
    queue.display();

    queue.enqueue(60);

    queue.dequeue();
    queue.dequeue();
    queue.display();

    queue.enqueue(60);
    queue.display();
    queue.display2();

    return 0;
}
