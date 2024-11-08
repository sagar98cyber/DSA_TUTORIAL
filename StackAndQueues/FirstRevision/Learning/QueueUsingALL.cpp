#include <bits.stdc++.h>

using namespace std;

/* Structure of a node in Queue
struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};

And structure of MyQueue
struct MyQueue {
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() {front = rear = NULL;}
}; */

// Function to push an element into the queue.
QueueNode *front = NULL;
QueueNode *rear = NULL;

void MyQueue::push(int x)
{
    // Your Code
    QueueNode *temp = new QueueNode(x);
    if (front != NULL)
    {
        rear->next = temp;
        rear = rear->next;
    }
    else
    {
        front = temp;
        rear = front;
    }
}

// Function to pop front element from the queue.
int MyQueue ::pop()
{
    // Your Code
    if (front == NULL)
    {
        return -1;
    }
    int a = front->data;
    QueueNode *temp = front;
    front = front->next;
    delete (temp);
    return a;
}