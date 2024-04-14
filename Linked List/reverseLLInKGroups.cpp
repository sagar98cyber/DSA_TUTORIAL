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

int traverseTheLLAndReturnCount(ListNode *head)
{
    int count = 0;
    ListNode *temp = head;
    cout << "Traversing the LL:" << endl;
    while (temp != NULL)
    {
        cout << temp->val << endl;
        temp = temp->next;
        count++;
    }
}

void createTheLL(ListNode *head)
{
    ListNode *temp = head;

    vector<int> a = {2, 3, 4, 5, 6, 7, 8, 9};
    // a = {2, 3, 4, 5};
    for (int i = 0; i < a.size(); i++)
    {
        ListNode *n = new ListNode(a[i]);
        temp->next = n;
        temp = temp->next;
    }
}

// 1 2 3 4 5 6 7 8 9        k=4

// 4 3 2 1 | 8 7 6 5 | 9

// Function to reverse a linked list
// using the 3-pointer approach
ListNode *reverseLinkedList(ListNode *head)
{
    ListNode *temp = head;
    ListNode *prev = NULL;
    while (temp != NULL)
    {
        ListNode *front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

ListNode *getKthNode(ListNode *temp, int k)
{
    k -= 1;
    while (temp != NULL && k > 0)
    {
        k--;
        temp = temp->next;
    }
    return temp;
}

ListNode *kReverse(ListNode *head, int k)
{
    ListNode *temp = head;
    ListNode *prevLast = NULL;

    while (temp != NULL)
    {
        ListNode *kThNode = getKthNode(temp, k);
        if (kThNode == NULL)
        {
            if (prevLast)
            {
                prevLast->next = temp;
            }
            break;
        }
        ListNode *nextNode = kThNode->next;
        kThNode->next = NULL;
        reverseLinkedList(temp);
        if (temp == head)
        {
            head = kThNode;
        }
        else
        {
            prevLast->next = kThNode;
        }
        prevLast = temp;
        temp = nextNode;
    }
    return head;
}

void printLinkedList(ListNode *head)
{
    ListNode *temp = head;
    while (temp != nullptr)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    int k = 2;
    // int k = 14;
    // int k = 4;
    ListNode *head = new ListNode(1);
    createTheLL(head);
    // traverseTheLLAndReturnCount(head);
    // -------------------------------------------------------------------------------------------------------

    head = kReverse(head, k);
    printLinkedList(head);
    return 0;
}
