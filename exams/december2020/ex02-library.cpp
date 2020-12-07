#include <iostream>
#include "ex02-library.h"
using namespace std;

// Task 2(a).  Implement this function
unsigned int length(Elem *list) {
    if (list == nullptr)
        return 0;
    else 
        return list->times + length(list->next);
}

// Task 2(b).  Implement this function
Elem* append(Elem *list, int v) {
    Elem *current = list;
    Elem *newElem = new Elem();  
    newElem->value = v;
    newElem->times = 1;
    newElem->next = nullptr;
    if (list == nullptr)
        return newElem;
    if (list->value == v) {
        list->times++;
        return list;
    }
    list->next = append(list->next, v);
    return list;
}

// Task 2(c).  Implement this function
Elem* buildRLEList(int *data, unsigned int n) {
    int i;
    Elem *list = nullptr;
    for (i = 0; i < n; i++)
        list = append(list, data[i]);
    return list;
}

// Do not modify
void displayRLEList(Elem *list) {
    if (list == nullptr) {
        return;
    }
    cout << " " << list->value << " (x" << list->times << ")";
    displayRLEList(list->next);
}
