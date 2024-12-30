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

void addNode(Node*& head, int value) {
    Node* newNode = new Node(value);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printList(Node* head) {
    Node* temp = head;
    cout << "Target Found at index : \t";
    while (temp != nullptr) {
        cout << temp->value<<"\t"  ;
        temp = temp->next;
    }

}

void search(int* arr, int size, int target) {
    Node* head = nullptr;
    int count = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            addNode(head, i);
            count++;
        }
    }

    if (count == 0) {
        cout << "Target Not Found" << endl;
    } else {
        cout << "Target " << target << " found " << count << " time(s)." << endl;
        printList(head);
    }
}

int main() {
    int target = 3;
    int arr[10] = {1, 2, 3, 5, 8, 9, 3, 3, 3};
    search(arr, 10, target);

    return 0;
}
