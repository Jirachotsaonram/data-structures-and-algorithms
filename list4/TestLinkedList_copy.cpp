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
  
  List<int> a(7);
    int x;

    a.push(4);
    a.push(1);
    a.push(1);
    a.push(2);
    a.push(8);
    a.push(8);
    printList(a);
    return 0;
}
