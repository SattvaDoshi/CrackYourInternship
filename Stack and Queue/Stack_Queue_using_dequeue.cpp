#include <bits/stdc++.h>
using namespace std;

struct DQueNode {
    int value;
    DQueNode* next;
    DQueNode* prev;
};

class Deque {
private:

    DQueNode* head;
    DQueNode* tail;

public:
    Deque()
    {
        head = tail = NULL;
    }

    bool isEmpty()
    {
        if (head == NULL)
            return true;
        return false;
    }

    int size()
    {
        // if list is not empty
        if (!isEmpty()) {
            DQueNode* temp = head;
            int len = 0;
            while (temp != NULL) {
                len++;
                temp = temp->next;
            }
            return len;
        }
        return 0;
    }

    // insert at the first position
    void insert_first(int element)
    {
        // allocating node of DQueNode type
        DQueNode* temp = new DQueNode[sizeof(DQueNode)];
        temp->value = element;

        // if the element is first element
        if (head == NULL) {
            head = tail = temp;
            temp->next = temp->prev = NULL;
        }
        else {
            head->prev = temp;
            temp->next = head;
            temp->prev = NULL;
            head = temp;
        }
    }

    // insert at last position of deque
    void insert_last(int element)
    {
        // allocating node of DQueNode type
        DQueNode* temp = new DQueNode[sizeof(DQueNode)];
        temp->value = element;

        // if element is the first element
        if (head == NULL) {
            head = tail = temp;
            temp->next = temp->prev = NULL;
        }
        else {
            tail->next = temp;
            temp->next = NULL;
            temp->prev = tail;
            tail = temp;
        }
    }

    // remove element at the first position
    void remove_first()
    {
        // if list is not empty
        if (!isEmpty()) {
            DQueNode* temp = head;
            head = head->next;
            if(head) head->prev = NULL;
            delete temp;
            if(head == NULL) tail = NULL;
            return;
        }
        cout << "List is Empty" << endl;
    }

    // remove element at the last position
    void remove_last()
    {
        // if list is not empty
        if (!isEmpty()) {
            DQueNode* temp = tail;
            tail = tail->prev;
            if(tail) tail->next = NULL;
            delete temp;
            if(tail == NULL) head = NULL;
            return;
        }
        cout << "List is Empty" << endl;
    }

    void display()
    {
        if (!isEmpty()) {
            DQueNode* temp = head;
            while (temp != NULL) {
                cout << temp->value << " ";
                temp = temp->next;
            }
            cout << endl;
            return;
        }
        cout << "List is Empty" << endl;
    }
};

class Stack : public Deque {
public:

    void push(int element)
    {
        insert_last(element);
    }
    void pop()
    {
        remove_last();
    }
};

class Queue : public Deque {
public:
    void enqueue(int element)
    {
        insert_last(element);
    }
    void dequeue()
    {
        remove_first();
    }
};

int main()
{
    Stack stk;

    stk.push(7);
    stk.push(8);
    cout << "Stack: ";
    stk.display();

    stk.pop();
    cout << "Stack: ";
    stk.display();

    Queue que;

    que.enqueue(12);
    que.enqueue(13);
    cout << "Queue: ";
    que.display();

    que.dequeue();
    cout << "Queue: ";
    que.display();

    cout << "Size of Stack is " << stk.size() << endl;
    cout << "Size of Queue is " << que.size() << endl;
    return 0;
}
