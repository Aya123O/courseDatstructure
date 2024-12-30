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

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    void push(int value) {


        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (top == nullptr) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        Node* temp = top;
        int removedValue = top->value;
        top = top->next;
        delete temp;
        return removedValue;
    }

    int peek() {
        if (top == nullptr) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return top->value;
    }

    void display() {
        if (top == nullptr) {
            cout << "Stack is empty" << endl;
            return;
        }
        Node* current = top;
        while (current) {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Stack stack;
     cout << "Push in stack" << endl;
    stack.push(10);
    stack.push(20);
    stack.push(30);
     cout << "Dispaly  stack" << endl;
    stack.display();
     cout << "Pop from stack" << endl;
    cout << stack.pop() << endl;
     cout << "Dispaly  peek" << endl;
    cout << stack.peek() << endl;
     cout << "Dispaly  stack" << endl;
    stack.display();
     cout << "Pop from stack" << endl;
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    cout << stack.pop() << endl;
    return 0;
    }
