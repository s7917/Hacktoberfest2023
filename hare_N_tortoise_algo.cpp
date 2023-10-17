#include <iostream>

struct Node {
    int data;
    Node* next;
};

bool hasCycle(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return false; // No cycle if the list is empty or has only one node
    }

    Node* tortoise = head; // Slow pointer
    Node* hare = head->next; // Fast pointer

    while (tortoise != hare) {
        if (hare == nullptr || hare->next == nullptr) {
            return false; // If hare reaches the end, no cycle
        }

        tortoise = tortoise->next; // Move tortoise one step
        hare = hare->next->next; // Move hare two steps
    }

    return true; // If tortoise and hare meet, there is a cycle
}

int main() {
    // Example usage
    Node* head = new Node{1, nullptr};
    head->next = new Node{2, nullptr};
    head->next->next = new Node{3, nullptr};
    head->next->next->next = head->next; // Creating a cycle, 3 points to 2

    if (hasCycle(head)) {
        std::cout << "The linked list has a cycle." << std::endl;
    } else {
        std::cout << "The linked list does not have a cycle." << std::endl;
    }

    // Clean up the memory (not shown in the code)
    return 0;
}
