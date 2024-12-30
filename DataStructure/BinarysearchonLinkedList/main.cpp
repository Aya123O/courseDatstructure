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

    Node* findMiddle(Node* start, Node* end) {
        Node* slow = start;
        Node* fast = start;

        while (fast != end && fast->next != end) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    Node* binarySearch(int target) {
        Node* start = head;
        Node* end = nullptr;

        while (start != end) {
            Node* mid = findMiddle(start, end);

            if (!mid)
                return nullptr;

            if (mid->data == target)
                return mid;

            if (mid->data < target)
                start = mid->next;
            else
                end = mid;
        }
        return nullptr;
    }
};

int main() {
    LinkedList l;
    l.add(5);
    l.add(8);
    l.add(10);
    l.add(12);
    l.add(13);
    l.add(15);
    l.add(20);

    cout << "Linked List: ";
    l.print();
        cout <<"******************************************************************"<<endl;

    int target = 100;
    Node* result = l.binarySearch(target);

    if (result) {
        cout << "Element " << target << " found in the linked list." << endl;
        cout <<"******************************************************************"<<endl;
    } else {
        cout << "Element " << target << " not found in the linked list." << endl;
        cout <<"******************************************************************"<<endl;

    }

    return 0;
}
