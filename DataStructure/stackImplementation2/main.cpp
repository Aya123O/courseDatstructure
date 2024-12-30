#include <iostream>
using namespace std;

class Stack {
private:
    int* arr;
    int top;
    int size;
public:

    Stack(int capacity) {
        if (capacity <= 0) {
            cout << "Invalid capacity! Capacity should be a positive integer.\n";
            return ;
        }

        size = capacity;
        top = -1;
        arr = new int[size];
    }


    ~Stack() {
        delete[] arr;
    }


    void push(int value) {
        if (top == size - 1) {
            cout << "Stack Overflow" << endl;
            return;
        }

        top++;
        arr[top] = value;
    }


    int pop() {
        if (top == -1) {
            cout << "Stack Underflow" << endl;
            return -1;
        }

        int removedValue = arr[top];
        top--;
        return removedValue;
    }


    int peek() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr[top];
    }


    void display() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return;
        }

        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int capacity = 5;
    Stack stack(capacity);


    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);
    stack.display();

    stack.push(60);
    cout << "Popped value: " << stack.pop() << endl;
    cout << "Popped value: " << stack.pop() << endl;
    stack.display();

    stack.push(60);
    stack.display();

    cout << "Top element: " << stack.peek() << endl;

    return 0;
}
