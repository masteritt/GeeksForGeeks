/* swaps the nodes of linked list without moving data fields.*/

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
    void swapNodes(int x, int y);
    LL(){
        head_ref = NULL; }
    ~LL(){
        while (head_ref != NULL)
        {
            Node * node = head_ref;
            head_ref = head_ref->next;
            delete node;
        }
    }
};

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

void LL::swapNodes(int x, int y)
{
    if (x == y) return;

    Node *prevX = NULL, *currX = head_ref;
    while (currX && currX->data != x)
    {
        prevX = currX;
        currX = currX->next;
    }

    Node *prevY = NULL, *currY = head_ref;
    while (currY && currY->data != y)
    {
        prevY = currY;
        currY = currY->next;
    }

    // If either x or y is not present, nothing to do
    if (currX == NULL || currY == NULL)
        return;

    // If x is not head of linked list
    if (prevX != NULL)
        prevX->next = currY;
    else // Else make y as new head
        head_ref = currY;

    // If y is not head of linked list
    if (prevY != NULL)
        prevY->next = currX;
    else // Else make x as new head
        head_ref = currX;

    // Swap next pointers
    Node *temp = currY->next;
    currY->next = currX->next;
    currX->next = temp;
}

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

    start.printList();
    start.swapNodes(4, 3);
    start.printList();
    start.swapNodes(1, 7);
    start.printList();
    start.swapNodes(6, 7);
    start.printList();
    start.swapNodes(9, 7);
    start.printList();

    return 0;
}
