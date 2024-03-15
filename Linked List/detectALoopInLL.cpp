#include <bits/stdc++.h>
using namespace std;

bool hasCycle(ListNode *head)
{
    if (head == NULL)
    {
        return false;
    }

    ListNode *slow = head;
    ListNode *fast = head;
    bool ret = true;
    while (fast->next != NULL && fast != NULL )
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return true;
        }
    }
    return false;
}
