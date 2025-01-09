#include <iostream>
#include <vector>

using namespace std;

// Custom exceptions
struct Overflow : public exception
{
    const char *what() const noexcept override { return "Overflow!"; }
};

struct Underflow : public exception
{
    const char *what() const noexcept override { return "Underflow!"; }
};

// Stack Template
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

template <class Object>
Stack<Object>::Stack(int capacity) : theArray(capacity)
{
    topOfStack = -1;
}

template <class Object>
bool Stack<Object>::isEmpty() const
{
    return topOfStack == -1;
}

template <class Object>
bool Stack<Object>::isFull() const
{
    return topOfStack == theArray.size() - 1;
}

template <class Object>
void Stack<Object>::makeEmpty()
{
    topOfStack = -1;
}

template <class Object>
void Stack<Object>::push(const Object &x)
{
    if (isFull())
        throw Overflow();
    theArray[++topOfStack] = x;
}

template <class Object>
const Object &Stack<Object>::top() const
{
    if (isEmpty())
        throw Underflow();
    return theArray[topOfStack];
}

template <class Object>
void Stack<Object>::pop()
{
    if (isEmpty())
        throw Underflow();
    topOfStack--;
}

template <class Object>
Object Stack<Object>::topAndPop()
{
    if (isEmpty())
        throw Underflow();
    return theArray[topOfStack--];
}

// Queue Template
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
    void printQueue() const;

private:
    vector<Object> theArray;
    int currentSize;
    int front;
    int back;

    void increment(int x);  // แก้ไข: เปลี่ยนเป็นรับค่าปกติ
};

template <class Object>
Queue<Object>::Queue(int capacity) : theArray(capacity)
{
    makeEmpty();
}

template <class Object>
void Queue<Object>::makeEmpty()
{
    currentSize = 0;
    front = 0;
    back = -1;
}

template <class Object>
bool Queue<Object>::isEmpty() const
{
    return currentSize == 0;
}

template <class Object>
bool Queue<Object>::isFull() const
{
    return currentSize == theArray.size();
}

template <class Object>
void Queue<Object>::enqueue(const Object &x)
{
    if (isFull())
        throw Overflow();
    increment(back);
    theArray[back] = x;
    currentSize++;
}

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

template <class Object>
const Object &Queue<Object>::getFront() const
{
    if (isEmpty())
        throw Underflow();
    return theArray[front];
}

// แก้ไข: ฟังก์ชัน increment เป็นรับค่าปกติ
template <class Object>
void Queue<Object>::increment(int x)
{
    if (++x == theArray.size())
        x = 0;
}

// ฟังก์ชันสำหรับแสดงคิว
template <class Object>
void Queue<Object>::printQueue() const
{
    if (isEmpty())
    {
        cout << "Queue is empty!" << endl;
        return;
    }

    int i = front;
    for (int count = 0; count < currentSize; ++count)
    {
        cout << theArray[i] << " ";
        increment(i);  // เรียก increment โดยไม่ใช้อ้างอิง
    }
    cout << endl;
}

// Main Function
int main()
{
    try
    {

        Stack<int> a(7);
        Queue<int> b(7);
        int x;

        a.push(4);
        a.push(1);
        a.push(1); 
        a.push(2);
        a.push(8);
        a.push(8);
        // 4 1 1 2 8 8
        x = a.topAndPop();
        b.enqueue(x);
        x = a.topAndPop();
        b.enqueue(x);
        x = a.topAndPop();
        b.enqueue(x);
        x = a.topAndPop();
        b.enqueue(x);
        x = a.topAndPop();
        b.enqueue(x);
        x = a.topAndPop();
        // 8 8 2 1 1 4
        x = b.dequeue();
        b.enqueue(x);
        x = b.dequeue();
        b.enqueue(x);
        x = b.dequeue();
        b.enqueue(x);
        x = b.dequeue();
        a.push(x);
        x = b.dequeue();
        a.push(x);
        x = b.dequeue();
        b.enqueue(x);
        x = b.dequeue();
        b.enqueue(x);
        x = b.dequeue();
        b.enqueue(x);
        x = b.dequeue();
        a.push(x);
        x = b.dequeue();
        a.push(x);
        x = b.dequeue();
        a.push(x);
        x = b.dequeue();
        a.push(x);
        b.printQueue();  // เรียกใช้ฟังก์ชันแสดงผลคิว
    }
    catch (const exception &e)
    {
        cout << e.what() << endl;
    }

    return 0;
}
