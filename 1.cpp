/********** BEGIN **********/
#include "LinkedList.h"

LinkedList::LinkedList() :size(0)
{
    head = new Node;
}

LinkedList::LinkedList(const LinkedList& rhs) :size(rhs.size)
{
    head = new Node;
    Node* p = head;
    for (Node* q = rhs.head->next; q; q = q->next)
    {
        p->next = new Node(q->data, q->next);
        p = p->next;
    }
}

LinkedList::LinkedList(int const a[], int n) : size(n)
{
    head = new Node;
    Node* p = head;
    for (int i = 0; i < size; ++i)
    {
        p->next = new Node(a[i], nullptr);
        p = p->next;
    }
}

LinkedList::LinkedList(int n, int value) : size(n)
{
    head = new Node;
    Node* p = head;
    for (int i = 0; i < size; ++i)
    {
        p->next = new Node(value, nullptr);
        p = p->next;
    }
}

LinkedList::~LinkedList()
{
    Node* p = head;
    while (p)
    {
        Node* q = p->next;
        delete p;
        p = q;
    }
}
/********** End **********/