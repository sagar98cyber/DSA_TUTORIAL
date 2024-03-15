#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node(int d, Node *n)
    {
        val = d;
        next = n;
    }

    Node(int d)
    {
        val = d;
        next = nullptr;
    }
};

Node *add1(Node *head)
{
    int carry = 1;
    Node *temp = head;
    Node *prev = NULL;
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
        Node *n = new Node(1);
        prev->next = n;
    }
    return head;
}

Node *revereseLL(Node *head)
{

    Node *curr = head;
    Node *prev = NULL;
    while (curr != NULL)
    {
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void traverseLL(Node *head)
{
    Node *temp = head;

    cout << "Traversing through the LL!" << endl;

    while (temp != NULL)
    {
        cout << temp->val << endl;
        temp = temp->next;
    }
    cout << endl;
}

void OOf3NSoln(Node *head)
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

int helperFunc(Node *temp)
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

Node *NSoln(Node *head)
{
    int carry = helperFunc(head);

    if (carry == 1)
    {
        Node *o = new Node(1);
        o->next = head;
        return o;
    }

    return head;
}

int main()
{
    Node *head = new Node(9);

    vector<int> a;
    a = {1, 3, 5, 7, 8, 0, 10, 11};
    ////////////////          VARIANTS OF TEST CASES  !!!!!!!
    // a = {3, 9};
    // a = {9, 9, 9};
    // a = {8, 9, 9};
    // a = {8, 9, 2};
    a = {8, 1, 9};

    Node *temp = head;

    for (int i = 0; i < a.size(); i++)
    {
        Node *n = new Node(a[i]);
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