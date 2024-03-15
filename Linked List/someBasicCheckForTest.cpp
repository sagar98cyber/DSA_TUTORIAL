///////////////// JUST WANT TO SEE IF THE MEMORY LOCATION is the SAME or not!?

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

void traversingLL(Node *head)
{
    while (head != NULL)
    {
        cout << "Value:   " << head->data << endl;
        head = head->next;
    }
}

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

    // PART 1 of the LL
    Node *h1 = new Node(12);
    h1->next = head;

    // PART 2 of the LL
    vector<int> arr2 = {2};

    Node *h2 = new Node(1);
    mover = h2;
    for (int i = 0; i < arr2.size(); i++)
    {
        Node *temp = new Node(arr2[i]);
        mover->next = temp;
        mover = temp;
    }
    mover->next = head;
    cout << "Traversing LL for h1:  " << endl;
    traversingLL(h1);
    cout << "Traversing LL for h2:  " << endl;
    traversingLL(h2);

    Node *d = h1->next;
    Node *d1 = h2->next->next->next;

    cout << "Well:   " << d->data << "     " << d1->data << endl;
    cout << "Well:   " << d << "     " << d1 << endl;
    if (d1 == d)
    {
        cout << " YES BABY YESSSSS IT IS THE SAME!!!!! " << endl;
    }

    return head->data;
}