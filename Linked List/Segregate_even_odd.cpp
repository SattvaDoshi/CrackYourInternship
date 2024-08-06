#include <bits/stdc++.h> 
using namespace std; 

class Node 
{ 
public: 
    int data; 
    Node *next; 
    Node (int d) {
        data = d;
        next = nullptr;
    }
}; 

void segregateEvenOdd(struct Node** head_ref)
{
    Node* evenStart = nullptr;
    Node* evenEnd = nullptr;
    Node* oddStart = nullptr;
    Node* oddEnd = nullptr;
    Node* currNode = *head_ref;

    while (currNode != nullptr) {
        int val = currNode->data;
        if (val % 2 == 0) {
            if (evenStart == nullptr) {
                evenStart = currNode;
                evenEnd = evenStart;
            }
            else {
                evenEnd->next = currNode;
                evenEnd = evenEnd->next;
            }
        }
        else {
            if (oddStart == nullptr) {
                oddStart = currNode;
                oddEnd = oddStart;
            }
            else {
                oddEnd->next = currNode;
                oddEnd = oddEnd->next;
            }
        }
        currNode = currNode->next;
    }
    if (oddStart == nullptr || evenStart == nullptr)
        return;

    evenEnd->next = oddStart;
    oddEnd->next = nullptr;
    *head_ref = evenStart;
}

void printList(Node *node) 
{ 
    while (node != nullptr) 
    { 
        cout << node->data <<" "; 
        node = node->next; 
    } 
} 

/* Driver code*/
int main() 
{ 
    Node* head = new Node(0);
    head->next = new Node(2);
    head->next->next = new Node(4);
    head->next->next->next = new Node(6);
    head->next->next->next->next = new Node(8);
    head->next->next->next->next->next = 
                                   new Node(10);
    head->next->next->next->next->next->next = 
                                   new Node(11);

    cout << "Original Linked list "; 
    printList(head); 

    segregateEvenOdd(&head); 

    cout << "\nModified Linked list "; 
    printList(head); 

    return 0; 
} 
