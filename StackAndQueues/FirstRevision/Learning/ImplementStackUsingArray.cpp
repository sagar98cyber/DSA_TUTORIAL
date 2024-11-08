#include<bits.stdc++.h>

using namespace std;

int top = 0;
int arr[1000];

void MyStack ::push(int x)
{
    // Your Code
    top++;
    arr[top] = x; 
}

// Function to remove an item from top of the stack.
int MyStack ::pop()
{
    // Your Code
    if(top <= 0)
    {
        return -1;
    }

    top--;
    return arr[top+1];
}

int main()
{

}