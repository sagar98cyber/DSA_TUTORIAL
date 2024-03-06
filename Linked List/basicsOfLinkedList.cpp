#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

int main()
{
    vector<int> arr = {1, 5, 2, 9, 0};

    Node *head = new Node(12);

    Node *mover = head;

    cout << "The value stored is:  " << head->data << endl;

    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head->data;
}