#include "LinkedList.h"
#include "LinkedList.cpp"

#include <iostream>
using namespace std;

// Simple print method
template <class Object>
void printList(const List<Object> &theList)
{
    if (theList.isEmpty())
        cout << "Empty list" << endl;
    else
    {
        ListItr<Object> itr = theList.first();
        for (; !itr.isPastEnd(); itr.advance())
            cout << itr.retrieve() << " ";
    }

    cout << endl;
}

int main()
{
    cout << "Jirachot Saonram ID:6706021411288 = 4 1 1 2 8 8" << endl;
    List<int> a;
    ListItr<int> b;
    b = a.zeroth();
    a.insert(4, b);
    b.advance();
    a.insert(1, b);
    a.insert(1, b);
    b = a.zeroth();
    b.advance();
    a.insert(2, b);
    b = a.zeroth();
    a.insert(8, b);
    a.insert(8, b);
    printList(a);
    return 0;
}
