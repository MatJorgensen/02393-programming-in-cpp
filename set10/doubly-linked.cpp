#include "doubly-linked.h"

using std::cout;    using std::endl;

/* Implementation of the base List class. */
List::List()
{
    first = NULL;
}

List::~List()
{
    /* empty */
}

void List::insert(int n)
{
    /* create node */
    Node *node = new Node();
    node->val = n;
    node->next = NULL;

    /* check if node is first element */
    if (first == NULL) {
        first = node;
        node->prev = NULL;
        return;
    }

    /* insert new node in list end */
    Node *current = first;
    while (current->next != NULL)
        current = current->next;
    current->next = node;
    node->prev = current;
}

void List::reverse()
{
    Node *current = first;
    Node *tmp = NULL;

    /* iterate to last element while 
       swapping *next and *prev pointers */
    while (current != NULL) {
        tmp = current->prev;
        current->prev = current->next;
        current->next = tmp;
        current = current->prev;
    }

    /* set first element */
    if (tmp != NULL)
        first = tmp->prev;
}

void List::print()
{
    Node *current = first;

    while (current != NULL) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}