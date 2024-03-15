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
            fast = fast->next;
            int count = 1;

            while (fast != slow)
            {
                fast = fast->next;
                count++;
            }

            return count;
        }
    }

    if (NULL == fast || fast->next == NULL)
        return 0;

}