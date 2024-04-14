#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int data;
    ListNode *back;
    ListNode *front;

    ListNode(int d, ListNode *b, ListNode *f)
    {
        data = d;
        back = b;
        front = f;
    }

    ListNode(int d)
    {
        data = d;
        back = NULL;
        front = NULL;
    }

    ListNode(int d, ListNode *b)
    {
        data = d;
        back = b;
        front = NULL;
    }
};

ListNode *traverseThroughLLAndReturnHead(ListNode *tail)
{
    ListNode *t = tail;
    ListNode *prev;
    cout << "Traversing through the LL:  " << endl;
    while (t)
    {
        cout << t->data << endl;
        prev = t;
        t = t->back;
    }
    return prev;
}

ListNode *traverseThroughLLAndReturnTail(ListNode *head)
{
    ListNode *t = head;
    ListNode *prev;
    cout << "Traversing through the LL:  " << endl;
    while (t)
    {
        cout << t->data << endl;
        prev = t;
        t = t->front;
    }
    return prev;
}

ListNode *deleteTheHead(ListNode *head)
{
    ListNode *temp = head;
    head = head->front;
    free(temp);
    head->back = nullptr;
    return head;
}

ListNode *deleteTheTail(ListNode *tail)
{
    ListNode *temp = tail;
    tail = tail->back;
    free(temp);
    tail->front = nullptr;
    return tail;
}

void deleteAtK(ListNode *head, int k)
{
    ListNode *temp = head;
    int count = 1;
    while (temp)
    {
        if (count != k)
        {
            temp = temp->front;
            count++;
            continue;
        }

        if (count == k)
        {
            ListNode *a = temp->back;
            ListNode *b = temp->front;

            a->front = b;
            b->back = a;

            free(temp);
            break;
            // return head;
        }
    }
}

ListNode *reverseLL(ListNode *head)
// void reverseLL(Node *head)
{
    ListNode *current = head;
    ListNode *prev = NULL;
    while (current)
    {
        prev = current->back;
        current->back = current->front;
        current->front = prev;
        current = current->back;
    }
    return prev->back;
}

int main()
{
    vector<int> a = {1, 5, 2, 6, 8, 3, 5, 4, 8, 5, 4, 1, 0};
    ListNode *head = new ListNode(a[0]);
    ListNode *b = head;
    ListNode *nNode = new ListNode(NULL);

    // cout<<"Head of data: "<<head->data<<"   "<<nNode->data<<"---  "<<endl;

    for (int i = 1; i < a.size(); i++)
    {
        ListNode *temp = new ListNode(a[i], b);
        // cout<<"    well:  "<<a[i]<<"    "<<temp->data<<endl;
        b->front = temp;
        b = b->front;
    }

    cout << "Done entering all data in " << endl;

    // Node* tail = traverseThroughLLAndReturnTail(head);

    // cout<< "--"<<tail->data;

    // traverseThroughLLAndReturnHead(tail);

    // head = deleteTheHead(head);

    // head = traverseThroughLLAndReturnTail(head);

    // cout << "--" << head->data;

    // tail = deleteTheTail(tail);

    // traverseThroughLLAndReturnHead(tail);

    // deleteAtK(head,3);

    // traverseThroughLLAndReturnTail(head);

    head = reverseLL(head);
    // reverseLL(head);

    traverseThroughLLAndReturnTail(head);
}