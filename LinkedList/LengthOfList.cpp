include<iostream>
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
    int length();
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

int LL::length()
{
    int length = 0;
    Node* current = head_ref;
    while (current != NULL)
    {
        length++;
        current = current->next;
    }
    return length;
}

/* Driver program to test above function */
int main()
{
    LL start;

    /* The constructed linked list is:
    1->2->3->4->5->6->7 */
    start.push(7);
    start.push(6);
    start.push(5);
    start.push(4);
    start.push(3);
    start.push(2);
    start.push(1);

    cout << start.length() << endl;
    return 0;
}
