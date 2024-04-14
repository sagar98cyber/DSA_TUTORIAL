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
    return head->data;
}