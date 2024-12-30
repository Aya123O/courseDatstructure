#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node* prev;

    Node(T data) {
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }
};

template <typename T>
class LinkedList {
private:

    Node<T>* getnodeusingdata(T data) {
        Node<T>* current = head;
        while (current != nullptr) {
            if (current->data == data) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

public:
    int counter;
    Node<T>* head;
    Node<T>* tail;

    LinkedList() {
        head = nullptr;
        tail = nullptr;
        counter = 0;
    }

    ~LinkedList() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* next = current->next;
            delete current;
            current = next;
        }
    }

    void add(T data) {
        Node<T>* newnode = new Node<T>(data);
        if (head == nullptr) {
            head = newnode;
            tail = newnode;
            counter++;
            return;
        }
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
        counter++;
    }

    void print() {
        if (head == nullptr) {
            cout << "No Data Found" << endl;
            return;
        }
        Node<T>* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    int find(T data) {
        return getnodeusingdata(data) != nullptr;
    }

    int getcount(){
        if (head == nullptr) {
            cout << "No Data Found" << endl;
            return 0;
        }
        return counter;
    }

    void addafter(T data, T dataafter) {
        Node<T>* current = getnodeusingdata(dataafter);
        if (current == nullptr) {
            cout << "Node " << dataafter << " not found." << endl;
            return;
        }
        Node<T>* newnode = new Node<T>(data);
        newnode->prev = current;
        newnode->next = current->next;
        if (current->next != nullptr) {
            current->next->prev = newnode;
        } else {
            tail = newnode;
        }
        current->next = newnode;
        counter++;
    }

    void addbefore(T data, T dataafter) {
        Node<T>* current = getnodeusingdata(dataafter);
        if (current == nullptr) {
            cout << "Node " << dataafter << " not found." << endl;
            return;
        }
        Node<T>* newnode = new Node<T>(data);
        newnode->next = current;
        newnode->prev = current->prev;
        if (current->prev != nullptr) {
            current->prev->next = newnode;
        } else {
            head = newnode;
        }
        current->prev = newnode;
        counter++;
    }

    T getDataByIndex(int index) {
        if (counter == 0) {
            cout << "No data found." << endl;
            return T();
        }

        if (index >= counter || index < 0) {
            cout << "Index out of scope." << endl;
            return T();
        }

        Node<T>* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp->data;
    }
    T insertDataByIndex(int index , T data ) {
        if (counter == 0) {
            cout << "No data found." << endl;
            return T();
        }

        if (index >= counter || index < 0) {
            cout << "Index out of scope." << endl;
            return T();
        }

        Node<T>* temp = head;
        for (int i = 0; i < index -1; i++) {
            temp = temp->next;
        }
        Node<T>* newnode = new Node<T>(data);
        newnode->next =temp ->next;
        newnode ->prev =temp ;
        if(temp->next != nullptr){
         temp->next->prev =newnode;
        }
           temp->next =newnode;


        counter ++ ;
        return data ;

    }
};

int main() {
    LinkedList<int> l;
    l.add(8);
    l.add(15);
    l.add(10);
    l.add(20);
    l.add(13);
    l.add(5);
    l.add(12);
    l.add(8);
    l.print();


    cout << "***************************************" << endl;

    cout << "Add After => " << endl;
    cout << "***************************************" << endl;
    l.addafter(25, 10);
    l.print();

    cout << "***************************************" << endl;
    cout << "Add After => " << endl;
    cout << "***************************************" << endl;
    l.addafter(25, 60);
    l.print();

    cout << "***************************************" << endl;
    cout << "Add Before => " << endl;
    cout << "***************************************" << endl;
    l.addbefore(2, 5);
    l.print();

    cout << "***************************************" << endl;
    cout << "The Number of Elements in Linked list: " << l.getcount() << endl;
    cout << "***************************************" << endl;
    cout << "Data at index 2: " << l.getDataByIndex(2) << endl;

    cout << "***************************************" << endl;
    cout << "Data at index 10: " << l.getDataByIndex(10) << endl;
    l.insertDataByIndex(2,100);
    l.print();

    return 0;
}
