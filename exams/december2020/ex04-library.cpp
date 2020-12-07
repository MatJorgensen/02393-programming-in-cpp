#include "ex04-library.h"

// Task 4(a).  Write a placeholder implementation of LimitedBuffer's
//             constructor and methods
LimitedBuffer::LimitedBuffer(unsigned int max, int dflt) : Buffer() {
    //this->vec = vector(max_capacity, 0);
    this->max = max;
    this->dflt = dflt;
}

// Task 4(b).  Write a working implementation of write() and occupancy()
void LimitedBuffer::write(int v) {
    if (members.size() < max)
        members.push_back(v);
}

unsigned int LimitedBuffer::occupancy() {
    return members.size();
}

// Task 4(c).  Write a working implementation of read()
int LimitedBuffer::read() {
    int v;

    if (members.empty())
        return dflt;
    else {
        v = members.front();
        members.erase(members.begin());
        return v;
    }
}

// Do not modify
Buffer::~Buffer() {
    // Empty destructor
}
