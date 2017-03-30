#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class LL
{
public:
    Node* head_ref;
    void push(int next);
    void printList();
    void reverse();
    LL() { head_ref = NULL; }
    ~LL();
};

LL::~LL()
{
    while (head_ref != NULL)
    {
        Node * node = head_ref;
        head_ref = head_ref->next;
        delete node;
    }
}
void LL::push(int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = head_ref;

    head_ref = new_node;
}

void LL::printList()
{
    Node *node = head_ref;
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

void LL::reverse()
{
    Node* prev = NULL;
    Node* current = head_ref;
    Node* next;
    while (current != NULL)
    {
        next = current->next;

        // N = P, P = C, C = N
        current->next = prev;
        prev = current;
        current = next;
    }
    head_ref = prev;
}
int main()
{
    LL first;

    /*1->2->3->4->5->6->7 */
    first.push(7);
    first.push(6);
    first.push(5);
    first.push(4);
    first.push(3);
    first.push(2);
    first.push(1);
    first.printList();
    first.reverse();
    first.printList();
    
    LL second;
    second.push(1);
    second.printList();
    second.reverse();
    second.printList();

    LL third;
    third.printList();
    second.reverse();
    third.printList();
    return 0;
}
