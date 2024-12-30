#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* Right;
    Node* Left;

    Node(int _data) {
        data = _data;
        Right = Left = NULL;
    }
};

class Tree {
private:
    Node* root;

    Node* getNodeByData(int data) {
        Node* current = root;
        while (current != NULL) {
            if (data == current->data) {
                return current;
            } else if (data > current->data) {
                current = current->Right;
            } else {
                current = current->Left;
            }
        }
        return NULL;
    }

    Node* getParent(Node* node) {
        Node* parent = root;
        while (parent != NULL) {
            if (node == parent->Right || node == parent->Left) {
                return parent;
            } else if (node->data > parent->data) {
                parent = parent->Right;
            } else {
                parent = parent->Left;
            }
        }
        return NULL;
    }

    Node* getMaxRight(Node* node) {
        Node* current = node;
        while (current->Right != NULL) {
            current = current->Right;
        }
        return current;
    }

    void display(Node* node) {
        if (node == NULL) {
            return;
        }
        display(node->Left);
        cout << node->data << " ";
        display(node->Right);
    }

public:
    Tree() {
        root = NULL;
    }

    void add(int data) {
        Node* newNode = new Node(data);
        if (root == NULL) {
            root = newNode;
        } else {
            Node* current = root;
            Node* parent = NULL;
            while (current != NULL) {
                parent = current;
                if (data > current->data) {
                    current = current->Right;
                } else {
                    current = current->Left;
                }
            }
            if (data > parent->data) {
                parent->Right = newNode;
            } else {
                parent->Left = newNode;
            }
        }
    }

    int findDataInTree(int data) {
        return getNodeByData(data) != NULL;
    }

    int getParentByData(int data) {
        Node* node = getNodeByData(data);
        if (node == root) {
            throw "The Node is Root and does not have a Parent";
        }
        if (node != NULL) {
            Node* parent = getParent(node);
            if (parent != NULL) {
                return parent->data;
            }
        }
        throw "Node Not Found, Does Not Have Parent";
    }

    int getMaxRightByData(int data) {
        Node* node = getNodeByData(data);
        if (node == NULL) {
            throw "Node Not Found";
        }
        Node* maxR = getMaxRight(node);
        return maxR->data;
    }

    int getMinData() {
        if (root == NULL) {
            throw "Tree is empty. No minimum value.";
        }
        Node* current = root;
        while (current->Left != nullptr) {
            current = current->Left;
        }
        return current->data;
    }

    int getMaxData() {
        if (root == NULL) {
            throw "Tree is empty. No maximum value.";
        }
        Node* current = root;
        while (current->Right != nullptr) {
            current = current->Right;
        }
        return current->data;
    }

    void displayAll() {
        display(root);
    }

    void remove(int data) {
        Node* node = getNodeByData(data);
        if (node == nullptr) {
            throw "Error: Node not found";
        }

        if (node == root) {
            if (root->Right == nullptr && root->Left == nullptr) {
                root = nullptr;
            } else if (root->Left == nullptr) {
                root = root->Right;
            } else if (root->Right == nullptr) {
                root = root->Left;
            } else {
                Node* newRoot = root->Left;
                Node* maxRight = getMaxRight(newRoot);
                maxRight->Right = root->Right;
                root = newRoot;
            }
        } else {
            Node* parent = getParent(node);
            if (node->Left == nullptr && node->Right == nullptr) {
                if (parent->Left == node) {
                    parent->Left = nullptr;
                } else {
                    parent->Right = nullptr;
                }
            } else if (node->Left == nullptr) {
                if (parent->Left == node) {
                    parent->Left = node->Right;
                } else {
                    parent->Right = node->Right;
                }
            } else if (node->Right == nullptr) {
                if (parent->Left == node) {
                    parent->Left = node->Left;
                } else {
                    parent->Right = node->Left;
                }
            } else {
                Node* newRoot = node->Left;
                Node* maxRight = getMaxRight(newRoot);
                maxRight->Right = node->Right;
                if (parent->Left == node) {
                    parent->Left = newRoot;
                } else {
                    parent->Right = newRoot;
                }
            }
        }
    }
};

int main() {
    Tree t;
    t.add(50);
    t.add(30);
    t.add(70);
    t.add(20);
    t.add(40);
    t.add(60);
    t.add(80);

    t.findDataInTree(70) ? cout << "Found\n" : cout << "Not Found\n";
    t.findDataInTree(35) ? cout << "Found\n" : cout << "Not Found\n";
    t.findDataInTree(40) ? cout << "Found\n" : cout << "Not Found\n";
    t.findDataInTree(50) ? cout << "Found\n" : cout << "Not Found\n";
    cout << "***************************************************" << endl;

    try {
        cout << "Parent: " << t.getParentByData(35) << endl;
        cout << "***************************************************" << endl;
        cout << "Max Right: " << t.getMaxRightByData(50) << endl;
        cout << "***************************************************" << endl;
    } catch (const char* msg) {
        cout << msg;
        cout << endl;
    }

    cout << "Before Remove:" << endl;
    t.displayAll();
    cout << endl;
    cout << "***************************************************" << endl;
    t.remove(70);

    cout << "After Remove:" << endl;
    t.displayAll();
    cout << endl;
    cout << "***************************************************" << endl;
    cout << "Min: " << t.getMinData() << endl;
    cout << "***************************************************" << endl;
    cout << "Max: " << t.getMaxData() << endl;
    cout << "***************************************************" << endl;


    return 0;
}
