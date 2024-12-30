#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;
    LinkedList() {
        head = nullptr;
    }

    void add(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void print() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << "\t ";
            temp = temp->next;
        }
        cout << endl;
    }

    void BubbleSort() {
        bool swapped;
        Node* current;
        Node* lastSorted = nullptr;
        do {
            swapped = false;
            current = head;
            while (current->next != lastSorted) {
                if (current->data > current->next->data) {
                    int temp = current->data;
                    current->data = current->next->data;
                    current->next->data = temp;
                    swapped = true;
                }
                current = current->next;
            }
            lastSorted = current;
        } while (swapped);
    }
};

int main() {
    LinkedList l;
    l.add(5);
    l.add(3);
    l.add(8);
    l.add(4);
    l.add(2);
    l.add(10);
    l.add(1);
    l.add(7);
    l.print();

    l.BubbleSort();
    cout << "Sorted List: ";
    l.print();

    return 0;
}
