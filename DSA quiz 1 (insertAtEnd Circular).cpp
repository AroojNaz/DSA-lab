#include <iostream>
struct Node {
    int data;
    Node* next;
};

Node* insertAtBeginning(Node* head, int newData) {
    Node* newNode = new Node;
    newNode->data = newData;

    if (head == NULL) {
        newNode->next = newNode; 
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        head = newNode;
    }

    return head;
}


void displayList(Node* head) {
    if (head == NULL) {
        std::cout << "The list is empty." << std::endl;
        return;
    }

    Node* current = head;
    do {
        std::cout << current->data << " ";
        current = current->next;
    } while (current != head);
    std::cout << std::endl;
}

int main() {
    Node* head = NULL;

    head = insertAtBeginning(head, 3);
    head = insertAtBeginning(head, 2);
    head = insertAtBeginning(head, 1);

    std::cout << "Circular Linked List: ";
    displayList(head);

    return 0;
}
