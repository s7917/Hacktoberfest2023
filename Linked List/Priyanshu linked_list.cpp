#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    // Function to add a node at the end of the linked list
    void append(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next) {
            current = current->next;
        }

        current->next = newNode;
    }

    // Function to display the linked list
    void display() {
        Node* current = head;
        while (current) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }

    // Function to perform selection sort on the linked list
    void selectionSort() {
        Node* current = head;

        while (current) {
            Node* min = current;
            Node* temp = current->next;

            while (temp) {
                if (temp->data < min->data) {
                    min = temp;
                }
                temp = temp->next;
            }

            // Swap the data of 'current' and 'min'
            int tempData = current->data;
            current->data = min->data;
            min->data = tempData;

            current = current->next;
        }
    }
};

int main() {
    LinkedList list;
    list.append(64);
    list.append(34);
    list.append(25);
    list.append(12);
    list.append(22);

    std::cout << "Original linked list: ";
    list.display();

    list.selectionSort();

    std::cout << "Linked list after selection sort: ";
    list.display();

    return 0;
}
