#include <bits/stdc++.h>
using namespace std;

///////// SORT A LINKED LIST --- MERGE SORT
// class ListNode
// {
// public:
//     int data;
//     ListNode *next;
// };

// ListNode *SortedMerge(ListNode *a, ListNode *b);

// void FrontBackSplit(ListNode *source, ListNode **frontRef, ListNode **backRef);

// void MergeSort(ListNode **headRef)
// {
//     ListNode *head = *headRef;
//     ListNode *a;
//     ListNode *b;

//     if ((head == NULL) || (head->next == NULL))
//     {
//         return;
//     }

//     FrontBackSplit(head, &a, &b);

//     MergeSort(&a);
//     MergeSort(&b);

//     *headRef = SortedMerge(a, b);
// }

// ListNode *SortedMerge(ListNode *a, ListNode *b)
// {
//     ListNode *result = NULL;

//     if (a == NULL)
//         return (b);
//     else if (b == NULL)
//         return (a);

//     if (a->data <= b->data)
//     {
//         result = a;
//         result->next = SortedMerge(a->next, b);
//     }
//     else
//     {
//         result = b;
//         result->next = SortedMerge(a, b->next);
//     }
//     return (result);
// }

// void FrontBackSplit(ListNode *source, ListNode **frontRef, ListNode **backRef)
// {
//     ListNode *fast;
//     ListNode *slow;
//     slow = source;
//     fast = source->next;

//     while (fast != NULL)
//     {
//         fast = fast->next;
//         if (fast != NULL)
//         {
//             slow = slow->next;
//             fast = fast->next;
//         }
//     }

//     *frontRef = source;
//     *backRef = slow->next;
//     slow->next = NULL;
// }

// void printList(ListNode *node)
// {
//     while (node != NULL)
//     {
//         cout << node->data << " ";
//         node = node->next;
//     }
// }

// void push(ListNode **head_ref, int new_data)
// {
//     ListNode *new_node = new ListNode();
//     new_node->data = new_data;
//     new_node->next = (*head_ref);
//     (*head_ref) = new_node;
// }

// int main()
// {
//     ListNode *res = NULL;
//     ListNode *a = NULL;

//     push(&a, 15);
//     push(&a, 10);
//     push(&a, 5);
//     push(&a, 20);
//     push(&a, 3);
//     push(&a, 2);

//     MergeSort(&a);

//     cout << "Sorted Linked List is: \n";
//     printList(a);

//     return 0;
// }

struct Node
{
    int data;
    Node *next;
};

Node *merge(Node *left, Node *right)
{
    Node *dummy = new Node();
    Node *tail = dummy;

    while (left && right)
    {
        if (left->data < right->data)
        {
            tail->next = left;
            left = left->next;
        }
        else
        {
            tail->next = right;
            right = right->next;
        }
        tail = tail->next;
    }

    if (left)
    {
        tail->next = left;
    }
    else
    {
        tail->next = right;
    }

    return dummy->next;
}

Node *mergeSort(Node *head)
{
    if (!head || !head->next)
    {
        return head;
    }

    Node *slow = head;
    Node *fast = head->next;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *right = mergeSort(slow->next);
    slow->next = nullptr;
    Node *left = mergeSort(head);

    return merge(left, right);
}

int main()
{
    Node *head = new Node{1};
    head->next = new Node{3};
    head->next->next = new Node{2};

    head = mergeSort(head);

    while (head)
    {
        std::cout << head->data << " ";
        head = head->next;
    }

    std::cout << std::endl;

    return 0;
}