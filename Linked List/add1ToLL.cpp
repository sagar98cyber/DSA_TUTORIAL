#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int d, ListNode *n)
    {
        val = d;
        next = n;
    }

    ListNode(int d)
    {
        val = d;
        next = nullptr;
    }
};

ListNode *add1(ListNode *head)
{
    int carry = 1;
    ListNode *temp = head;
    ListNode *prev = NULL;
    while (temp != NULL && carry == 1)
    {
        temp->val = temp->val + 1;
        if (temp->val < 10)
        {

            carry = 0;
            return head;
        }
        else
        {
            cout << "Inside Else! " << endl;
            temp->val = 0;
            carry = 1;
        }
        prev = temp;
        temp = temp->next;
    }
    // cout<<After
    if (carry == 1)
    {
        ListNode *n = new ListNode(1);
        prev->next = n;
    }
    return head;
}

ListNode *revereseLL(ListNode *head)
{

    ListNode *curr = head;
    ListNode *prev = NULL;
    while (curr != NULL)
    {
        ListNode *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void traverseLL(ListNode *head)
{
    ListNode *temp = head;

    cout << "Traversing through the LL!" << endl;

    while (temp != NULL)
    {
        cout << temp->val << endl;
        temp = temp->next;
    }
    cout << endl;
}

void OOf3NSoln(ListNode *head)
{
    cout << "Reversing the LL!" << endl;
    head = revereseLL(head);

    traverseLL(head);
    cout << "Adding 1 to the LL!" << endl;
    head = add1(head);
    traverseLL(head);
    cout << "Head:  " << head->val << "  Head Next:  " << head->next->val << endl;
    head = revereseLL(head);
    traverseLL(head);
}

int helperFunc(ListNode *temp)
{

    if (temp == NULL)
    {
        return 1;
    }
    //////// GOING TO THE END OF THE LL
    int carry = helperFunc(temp->next);
    // cout << "carry is:  " << carry << "   temp->val + 1: " << temp->val + 1 << "   Temp->val:  " << temp->val << endl;

    ///////// GETTING THE CARRY OF THE LL FROM THE END
    temp->val = temp->val + carry;

    if (temp->val < 10)
    {
        return 0;
    }

    cout << "Returning 1! " << endl;

    temp->val = 0;

    return 1;
}

ListNode *NSoln(ListNode *head)
{
    int carry = helperFunc(head);

    if (carry == 1)
    {
        ListNode *o = new ListNode(1);
        o->next = head;
        return o;
    }

    return head;
}

int main()
{
    ListNode *head = new ListNode(9);

    vector<int> a;
    a = {1, 3, 5, 7, 8, 0, 10, 11};
    ////////////////          VARIANTS OF TEST CASES  !!!!!!!
    // a = {3, 9};
    // a = {9, 9, 9};
    // a = {8, 9, 9};
    // a = {8, 9, 2};
    a = {8, 1, 9};

    ListNode *temp = head;

    for (int i = 0; i < a.size(); i++)
    {
        ListNode *n = new ListNode(a[i]);
        temp->next = n;
        temp = temp->next;
    }

    traverseLL(head);

    /*
        OOf3NSoln(head);

        TC->O(3N)
        SC->O(1)
    */

    /*
     OPTIMAL SOLUTION IS USING RECURSION, BACK TRACKING
     This will lead to a TIME COMPLEXITY of O(1) and SPACE COMPLEXITY of O(1)

     head = NSoln(head);

     */

    traverseLL(head);
}