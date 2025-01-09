#include <iostream>

using namespace std;
template <class Object>
class Stack
{
public:
    explicit Stack(int capacity = 10);

    bool isEmpty() const;
    bool isFull() const;
    const Object &top() const;
    void makeEmpty();
    void pop();
    void push(const Object &x);
    Object topAndPop();

private:
    vector<Object> theArray;
    int topOfStack;
};

// Construct the stack.
template <class Object>
Stack<Object>::Stack(int capacity) : theArray(capacity)
{

    topOfStack = -1;
}

// Test if the stack is logically empty.
template <class Object>
bool Stack<Object>::isEmpty() const
{

    return topOfStack == -1;
}

// Test if the stack is logically full.
template <class Object>
bool Stack<Object>::isFull() const
{
    return topOfStack == theArray.size() - 1;
}

// Make the stack logically empty.
template <class Object>
void Stack<Object>::makeEmpty()
{
    topOfStack = -1;
}

// Push onto a stack
template <class Object>
void Stack<Object>::push(const Object &x)
{
    if (isFull())
        throw Overflow();
    theArray[++topOfStack] = x;
}

// Return top of stack
template <class Object>
const Object &Stack<Object>::top() const
{
    if (isEmpty())
        throw Underflow();
    return theArray[topOfStack];
}

// Pop from stack
template <class Object>
void Stack<Object>::pop()
{
    if (isEmpty())
        throw Underflow();
    topOfStack--;
}

// Pop from stack and return value
template <class Object>
Object Stack<Object>::topAndPop()
{
    if (isEmpty())
        throw Underflow();
    return theArray[topOfStack--];
}