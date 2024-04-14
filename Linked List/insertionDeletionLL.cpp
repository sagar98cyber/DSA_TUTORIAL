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

void traverseThroughLL(ListNode *head)
{
    ListNode *temp = head;
    cout << "Traversing through the LL:  " << endl;
    while (temp)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

ListNode *deleteAtHead(ListNode *head)
{
    cout << "After deleting the head of the LL: " << endl;
    ListNode *temp = head->next;
    free(head);
    return temp;
}

ListNode *deleteTheTailOfLL(ListNode *head)
{
    cout << "After deleting the tail of the LL: " << endl;
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    ListNode *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
    return head;
}

ListNode *deleteKthElementOfLL(ListNode *head, int k)
{
    int i = 1;

    ListNode *temp = head;
    // cout << "After deleting the Kth Element of the LL: " << endl;

    if (head == NULL)
    {
        // cout << "GIVEN LL is empty" << endl;
        return NULL;
    }
    else if (k == 1)
    {
        // cout << "DELETING THE HEAD" << endl;

        ListNode *temp = head->next;
        free(head);
        return temp;
    }
    else if (head->next == NULL && k > 1)
    {
        // cout << "ONLY ONE ELEMENT IN THE LL and the INDEX GREATER THAN K"<<endl;
        return head;
    }

    // cout << "Executing Default" << endl;

    ListNode *prev = head;
    temp = temp->next;

    // DEFAULT CONDITION
    while (i <= k && temp)
    {
        cout << "inside while  " << i << "  " << k << endl;
        if (i != k - 1)
        {
            ++i;
            prev = prev->next;
            temp = temp->next;
        }

        if (i == k - 1)
        {
            prev->next = temp->next;
            free(temp);
            return head;
        }
    }
    // while( i <= k && temp )
    // {
    //     if(i != k-1)
    //     {
    //         temp = temp->next;
    //         ++i;
    //         continue;
    //     }

    //     if(i == (k-1))
    //     {
    //         Node* t2 = temp;

    //         Node *t3 = temp->next->next; //  This is an EDGE CASE and a reason why this does not work.
    //         // TRY vector<int> a = {1, 4}; & head = deleteKthElementOfLL(head,4); in the INT MAIN()
    //         // t3 cannot get next of next
    //         // Because of that the whole loop is wrong
    //         free(temp->next);
    //         t2->next = t3;
    //         break;
    //     }
    // }
    cout << "Returning the Head Default";
    return head;
}

ListNode *deleteValFromLL(ListNode *head, int val)
{

    ListNode *prev = NULL;
    ListNode *temp = head;
    // cout << "After deleting the Kth Element of the LL: " << endl;

    if (head->data == NULL)
    {
        // cout << "GIVEN LL is empty" << endl;
        return prev;
    }
    else if (head->data != val && head->next == NULL)
    {
        // cout << "DELETING THE HEAD" << endl;

        // Node *temp = head->next;
        free(head);
        return prev;
    }
    else if (head->next == NULL && head->data == val)
    {
        // cout << "ONLY ONE ELEMENT IN THE LL and the INDEX GREATER THAN K"<<endl;
        free(head);
        return prev;
    }
    else if (temp->data == val)
    {
        head = head->next;
        free(temp);
        return head;
    }

    prev = temp;
    temp = temp->next;
    ListNode *p1 = prev;
    while (temp)
    {
        cout << "Inside WHILE" << endl;
        if (temp->data == val)
        {
            prev->next = temp->next;
            ListNode *p1 = temp;
            temp = temp->next;
            free(p1);
        }
        else
        {
            prev = prev->next;
            temp = temp->next;
        }
    }
    return head;
}

int main()
{
    vector<int> a = {1, 4, 6, 8, 9, 4, 2, 1, 8, 0, 9, 4, 4};
    // vector<int> a = {1, 4};
    // vector<int> a = {1};

    ListNode *head = new ListNode(a[0]);
    ListNode *temp = head;
    for (int i = 1; i < a.size(); i++)
    {
        ListNode *x = new ListNode(a[i]);
        temp->next = x;
        temp = temp->next;
    }
    traverseThroughLL(head);

    // head = deleteAtHead(head);

    // traverseThroughLL(head);

    // head = deleteTheTailOfLL(head);

    // traverseThroughLL(head);

    // head = deleteKthElementOfLL(head,4);

    // traverseThroughLL(head);

    head = deleteValFromLL(head, 3);

    traverseThroughLL(head);

    /*  IF I CAN DO DELETION I CAN DO INSERTION, I DO NOT NEED TO STUDY THAT! */
}