#include <bits/stdc++.h>
using namespace std;


Node *dummy = new Node(0);
Node *itr = head;
temp = dummy;
Node *fast;

while (itr != NULL)
{
    fast = itr->next->next;
    temp->next = itr->next;
    itr->next = fast;
    temp = temp->next;
    itr = fast;
}
return dummy->next;