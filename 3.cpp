/******begin your code here******/
#include "LinkedList.h"
#include <iostream>
using namespace std;

LinkedList::LinkedList() : size(0) {
    head = new Node;
}

LinkedList::LinkedList(const LinkedList& rhs) : size(rhs.size) {
    head = new Node;
    Node* p = head;
    for (Node* q = rhs.head->next; q; q = q->next) {
        p->next = new Node(q->data, q->next);
        p = p->next;
    }
}

LinkedList::LinkedList(int const a[], int n) : size(n) {
    head = new Node;
    Node* p = head;
    for (int i = 0; i < size; ++i) {
        p->next = new Node(a[i], nullptr);
        p = p->next;
    }
}

LinkedList::LinkedList(int n, int value) : size(n) {
    head = new Node;
    Node* p = head;
    for (int i = 0; i < size; ++i) {
        p->next = new Node(value, nullptr);
        p = p->next;
    }
}

LinkedList::~LinkedList() {
    while (getSize()) {
        remove(0);
    }
    delete head;
}

LinkedList::Node* LinkedList::advance(int pos) const
{
    Node* p = head;
    for (int i = -1; i < pos; ++i)
    {
        p = p->next;
    }
    return p;
}

void LinkedList::insert(int pos, int value)
{
    Node* p = advance(pos - 1);
    Node* q = new Node(value, p->next);
    p->next = q;
    ++size;
}

void LinkedList::remove(int pos)
{
    Node* p = advance(pos - 1);
    Node* q = p->next;
    p->next = q->next;
    delete p;
    --size;
}

int LinkedList::at(int pos) const
{
    return advance(pos)->data;
}

void LinkedList::modify(int pos, int newValue)
{
    advance(pos)->data = newValue;
}

void LinkedList::disp() const
{
    for (Node* p = head->next; p; p = p->next)
    {
        cout << p->data << " ";
    }
    cout << endl;
}

LinkedList& LinkedList::operator = (const LinkedList& rhs)
{
    if (this != &rhs)
    {
        while (getSize())   remove(0);
        Node* q = head;
        for (Node* p = rhs.head->next; p; p = p->next)
        {
            q->next = new Node(p->data, p->next);
            q = q->next;
        }
        size = rhs.size;
    }
    return *this;
}

LinkedList& LinkedList::operator += (const LinkedList& rhs)
{
    if (this != &rhs)
    {
        Node* q = advance(size - 1);
        for (Node* p = rhs.head->next; p; p = p->next)
        {
            q->next = new Node(p->data, p->next);
            q = q->next;
        }
        size += rhs.size;
    }
    return *this;
}

int& LinkedList::operator [] (int pos)
{
    return advance(pos)->data;
}

const int& LinkedList::operator [] (int pos) const
{
    return const_cast<int&>((static_cast<const LinkedList*>(this))->operator [] (pos));
}
/******end your code******/