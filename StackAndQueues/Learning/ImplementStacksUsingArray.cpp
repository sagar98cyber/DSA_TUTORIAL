#include <bits/stdc++.h>

using namespace std;

class MyStack
{
private:
    int arr[1000];
    int top;

public:
    MyStack() { top = -1; }
    int pop();
    void push(int);
};

void MyStack ::push(int x)
{
    // Your Code
    top++;
    arr[top] = x;

}

// Function to remove an item from top of the stack.
int MyStack ::pop()
{
    if (top < 0)
    {
        return -1;
    }
    
    int x = arr[top];
    top--;
    return x;
}
