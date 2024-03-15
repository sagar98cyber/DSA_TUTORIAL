#include <bits/stdc++.h>
using namespace std;

int lengthOfLoop(Node *head)
{
    // Write your code here

    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast)
        {
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
        }
    }

    if (NULL == fast || fast->next == NULL)
        return 0;
    
    return slow;
}