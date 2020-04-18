#include "LList.h"

template <class T>
LList<T> reverseLList(const LList<T>& list) {
    LList<T> res;
    LList<T> tempCopy(list);
    while (tempCopy.getSize())
    {
        res.toEnd(tempCopy.popLast());
    }

    return res;
}

int main() {
    LList<int> linkedList;
    linkedList.toEnd(1);
    linkedList.toEnd(2);
    linkedList.toEnd(3);
    linkedList.toEnd(4);
    linkedList.print();

    reverseLList(linkedList).print();
    linkedList.print();
}