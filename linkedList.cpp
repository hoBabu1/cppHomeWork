#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        cout << "Inserted " << value << " at the beginning." << endl;
    }

    void deleteNode(int value) {
        if (head == nullptr) {
            cout << "List is empty. Cannot delete element." << endl;
            return;
        }
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Deleted " << value << " from the list." << endl;
            return;
        }
        Node* current = head;
        while (current->next != nullptr && current->next->data != value) {
            current = current->next;
        }
        if (current->next == nullptr) {
            cout << "Element " << value << " not found in the list." << endl;
            return;
        }
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
        cout << "Deleted " << value << " from the list." << endl;
    }
    void display() {
        Node* current = head;
        cout << "Linked list: ";
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};
int main() {
    LinkedList list;
    list.insertAtBeginning(10);
    list.insertAtBeginning(20);
    list.insertAtBeginning(30);
    list.display();
    list.deleteNode(20);
    list.display();
    list.deleteNode(40);
    return 0;
}
