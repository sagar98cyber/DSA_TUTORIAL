#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *back;
    Node *front;

    Node(int d, Node *b, Node *f)
    {
        data = d;
        back = b;
        front = f;
    }

    Node(int d)
    {
        data = d;
        back = NULL;
        front = NULL;
    }

    Node(int d, Node *b)
    {
        data = d;
        back = b;
        front = NULL;
    }
};

Node *traverseThroughLLAndReturnHead(Node *tail)
{
    Node *t = tail;
    Node *prev;
    cout << "Traversing through the LL:  " << endl;
    while (t)
    {
        cout << t->data << endl;
        prev = t;
        t = t->back;
    }
    return prev;
}

Node *traverseThroughLLAndReturnTail(Node *head)
{
    Node *t = head;
    Node *prev;
    cout << "Traversing through the LL:  " << endl;
    while (t)
    {
        cout << t->data << endl;
        prev = t;
        t = t->front;
    }
    return prev;
}

Node *deleteTheHead(Node *head)
{
    Node *temp = head;
    head = head->front;
    free(temp);
    head->back = nullptr;
    return head;
}

Node *deleteTheTail(Node *tail)
{
    Node *temp = tail;
    tail = tail->back;
    free(temp);
    tail->front = nullptr;
    return tail;
}

void deleteAtK(Node *head, int k)
{
    Node *temp = head;
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
            Node *a = temp->back;
            Node *b = temp->front;

            a->front = b;
            b->back = a;

            free(temp);
            break;
            // return head;
        }
    }
}

Node* reverseLL(Node* head)
// void reverseLL(Node *head)
{
    Node *current = head;
    Node *prev = NULL;
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
    Node *head = new Node(a[0]);
    Node *b = head;
    Node *nNode = new Node(NULL);

    // cout<<"Head of data: "<<head->data<<"   "<<nNode->data<<"---  "<<endl;

    for (int i = 1; i < a.size(); i++)
    {
        Node *temp = new Node(a[i], b);
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

    head=reverseLL(head);
    // reverseLL(head);

    traverseThroughLLAndReturnTail(head);
}