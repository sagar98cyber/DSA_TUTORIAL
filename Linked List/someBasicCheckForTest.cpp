///////////////// JUST WANT TO SEE IF THE MEMORY LOCATION is the SAME or not!?

#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int data;
    ListNode *next;

    ListNode(int data1, ListNode *next1)
    {
        data = data1;
        next = next1;
    }

    ListNode(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

void traversingLL(ListNode *head)
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

    ListNode *head = new ListNode(12);

    ListNode *mover = head;

    cout << "The value stored is:  " << head->data << endl;

    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        ListNode *temp = new ListNode(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    // PART 1 of the LL
    ListNode *h1 = new ListNode(12);
    h1->next = head;

    // PART 2 of the LL
    vector<int> arr2 = {2};

    ListNode *h2 = new ListNode(1);
    mover = h2;
    for (int i = 0; i < arr2.size(); i++)
    {
        ListNode *temp = new ListNode(arr2[i]);
        mover->next = temp;
        mover = temp;
    }
    mover->next = head;
    cout << "Traversing LL for h1:  " << endl;
    traversingLL(h1);
    cout << "Traversing LL for h2:  " << endl;
    traversingLL(h2);

    ListNode *d = h1->next;
    ListNode *d1 = h2->next->next->next;

    cout << "Well:   " << d->data << "     " << d1->data << endl;
    cout << "Well:   " << d << "     " << d1 << endl;
    if (d1 == d)
    {
        cout << " YES BABY YESSSSS IT IS THE SAME!!!!! " << endl;
    }

    return head->data;
}