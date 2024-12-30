#include <iostream>

using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data) {
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }
};
class LinkedList {
private:


public:

    Node* head;
    Node* tail;

    LinkedList() {
        head = nullptr;
        tail = nullptr;

    }

    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    void add(int data) {
        Node* newnode = new Node(data);
        if (head == nullptr) {
            head = newnode;
            tail = newnode;

            return;
        }
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;

    }

    void print() {
        if (head == nullptr) {
            cout << "No Data Found" << endl;
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
     void mergeLinkedList ( LinkedList &other) {
        if (this->head == nullptr && other.head == nullptr) {
        return;
    }

   if(this->head == nullptr) {
   this->head =other.head ;
   this->tail =other.tail;
   return ;
   }
   if(other.head == nullptr){

     return ;
     }

    this->tail->next =other.head;
    other.head->prev =this->tail;
    this->tail =other.tail;




  }
   };

int main()
{
     LinkedList l;
    l.add(8);
    l.add(15);
    l.add(10);
    l.add(20);

    cout <<"linked List one " <<endl;

    l.print();
      LinkedList l2;
    l2.add(8);
    l2.add(15);
    l2.add(10);
    l2.add(20);


cout <<"linked List Two " <<endl;
    l2.print();
    l.mergeLinkedList(l2);
cout <<"Merge two  linked List " <<endl;
    l.print();

    return 0;
}
