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
        next = NULL;
    }

    ListNode(int d, ListNode *n)
    {
        val = d;
        next = n;
    }
};

int traverseLLAndReturnCount(ListNode *head)
{
    cout << "Traversing throught the LL: " << endl;
    ListNode *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        cout << temp->val << endl;
        temp = temp->next;
        ++count;
    }
    cout << endl;
    return count;
}

void basicLLCreation(ListNode *n1, ListNode *n2)
{
    vector<int> a = {4, 3};
    a = {9, 9, 9, 9, 9, 9};

    vector<int> b = {6, 4};
    b = {9, 9, 9};

    ListNode *t1 = n1;
    ListNode *t2 = n2;

    for (int i = 0; i < a.size(); i++)
    {
        // cout << "Considering:  " << a[i] << "    " << b[i] << endl;
        ListNode *temp1 = new ListNode(a[i]);
        t1->next = temp1;
        t1 = t1->next;
    }

    for (int i = 0; i < b.size(); i++)
    {
        ListNode *temp2 = new ListNode(b[i]);
        t2->next = temp2;
        t2 = t2->next;
    }
}

ListNode *sumOf2LL(ListNode *n1, ListNode *n2)
{
    int carry = 0;
    ListNode *t1 = n1, *t2 = n2, *n = new ListNode(-1), *head = n;

    while (t1 != NULL || t2 != NULL)
    {
        int sum = carry;
        if (t1)
            sum += t1->val;
        if (t2)
            sum += t2->val;

        if (sum > 9)
        {
            carry = 1;
            sum = sum - 10;
        }
        else
        {
            carry = 0;
        }

        ListNode *nn = new ListNode(sum);
        n->next = nn;

        if (t1)
            t1 = t1->next;
        if (t2)
            t2 = t2->next;

        n = n->next;
    }

    if (carry != 0)
    {
        ListNode *nn = new ListNode(carry);
        n->next = nn;
    }

    return head->next;
}

int main()
{
    ListNode *n1 = new ListNode(2);
    ListNode *n2 = new ListNode(5);
    n1->val = 9;
    n2->val = 9;
    // n1->val = 0;
    // n2->val = 0;
    // n1->val = 5;
    // n2->val = 5;

    ListNode *t1 = n1;
    ListNode *t2 = n2;

    // basicLLCreation(n1, n2);

    cout << "Traversing N1" << endl;
    int n1L = traverseLLAndReturnCount(n1);

    cout << "Traversing N2" << endl;
    int n2L = traverseLLAndReturnCount(n2);

    ListNode *newHead = sumOf2LL(n1, n2);
    cout << "Traversing Sum of NEW HEAD: " << endl;
    traverseLLAndReturnCount(newHead);
    return 0;
}