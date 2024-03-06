#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

void traverseThroughLL(Node *head)
{
    Node *temp = head;
    cout << "Traversing through the LL:  " << endl;
    while (temp)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

Node* deleteAtHead(Node* head)
{
    cout<<"After deleting the head of the LL: "<<endl;
    Node* temp = head->next;
    free(head);
    return temp;
}

Node* deleteTheTailOfLL(Node* head)
{
    cout << "After deleting the tail of the LL: " << endl;
    if(head == NULL || head->next == NULL)
    {
        return NULL;
    }
    Node* temp = head;
    while(temp->next->next != NULL)
    {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
    return head;
}

Node* deleteKthElementOfLL(Node* head, int k)
{
    int i=1;

    Node* temp = head;
    // cout << "After deleting the Kth Element of the LL: " << endl;
    
    if (head == NULL)
    {
        // cout << "GIVEN LL is empty" << endl;
        return NULL;
    }
    else if(k == 1)
    {
        // cout << "DELETING THE HEAD" << endl;

        Node* temp = head->next;
        free(head);
        return temp;
    }
    else if(head->next == NULL && k>1)
    {
        // cout << "ONLY ONE ELEMENT IN THE LL and the INDEX GREATER THAN K"<<endl;
        return head;
    }
    

    // cout << "Executing Default" << endl;
    
    Node* prev = head;
    temp = temp->next;

    // DEFAULT CONDITION
    while(i<=k && temp)
    {
        cout<<"inside while  "<<i<<"  " << k <<endl;
        if( i != k-1)
        {
            ++i;
            prev=prev->next;
            temp = temp->next;
        }

        if(i == k-1 )
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
    cout<<"Returning the Head Default";
    return head;
}

Node *deleteValFromLL(Node *head, int val)
{

    Node *prev = NULL;
    Node *temp = head;
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
    else if(temp->data == val)
    {
        head = head->next;
        free(temp);
        return head;
    }

    prev = temp;
    temp = temp->next;
    Node *p1 = prev;
    while (temp)
    {
        cout<<"Inside WHILE"<<endl;   
        if(temp->data == val)
        {
            prev->next = temp->next;
            Node *p1 = temp;
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

        Node *head = new Node(a[0]);
        Node *temp = head;
        for (int i = 1; i < a.size(); i++)
        {
            Node *x = new Node(a[i]);
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
        
        head = deleteValFromLL(head,3);

        traverseThroughLL(head);


        /*  IF I CAN DO DELETION I CAN DO INSERTION, I DO NOT NEED TO STUDY THAT! */

    }