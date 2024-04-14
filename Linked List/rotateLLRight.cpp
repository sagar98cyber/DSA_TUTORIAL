#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int d)
    {
        val = d;
        next = nullptr;
    }

    ListNode(int d, ListNode *n)
    {
        next = n;
        val = d;
    }
};


ListNode *rotateRight(ListNode *head, int k)
{

    if (head == NULL)
    {
        return head;
    }

    if (k == 0)
    {
        return head;
    }

    if (head->next == NULL)
    {
        return head;
    }

    for (int i = 0; i < k; i++)
    {
        ListNode *tail = getTail(head);
        ListNode *end = tail->next;
        tail->next = NULL;
        end->next = head;
        head = end;
    }

    return head;
}