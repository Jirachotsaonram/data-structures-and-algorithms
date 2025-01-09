#include <iostream>
		
		using namespace std;
template <class Object>
class Queue
{
public:
    explicit Queue(int capacity = 10);

    bool isEmpty() const;
    bool isFull() const;
    const Object &getFront() const;
    void makeEmpty();
    Object dequeue();
    void enqueue(const Object &x);

private:
    vector<Object> theArray;
    int currentSize;
    int front;
    int back;

    void increment(int &x);
};

// Construct the queue.
template <class Object>
Queue<Object>::Queue(int capacity) : theArray(capacity)
{

    makeEmpty();
}

// Make the queue logically empty.
template <class Object>
void Queue<Object>::makeEmpty()
{

    currentSize = 0;
    front = 0;
    back = -1;
}

// Enqueue - Insert x into the queue.
template <class Object>
void Queue<Object>::enqueue(const Object &x)
{
    if (isFull())
        throw Overflow();
    increment(back);
    theArray[back] = x;
    currentSize++;
}

// Internal method to increment x with wraparound.
template <class Object>
void Queue<Object>::increment(int &x)
{
    if (++x == theArray.size())
        x = 0;
}

// Dequeue – Remove last recently inserted item

template <class Object>
Object Queue<Object>::dequeue()
{
    if (isEmpty())
        throw Underflow();

    currentSize--;
    Object frontItem = theArray[front];
    increment(front);
    return frontItem;
}