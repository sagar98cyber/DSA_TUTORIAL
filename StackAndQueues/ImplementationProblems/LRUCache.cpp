#include <bits/stdc++.h>

using namespace std;

class Cache
{
public:
    int data, key;
    Cache *front;
    Cache *back;

    Cache(int d, int k, Cache *f, Cache *b)
    {
        key = k;
        data = d;
        front = f;
        back = b;
    }
    Cache(int d, int k, Cache *b)
    {
        key = k;
        data = d;
        front = NULL;
        back = b;
    }
    Cache(int k, int d)
    {
        key = k;
        data = d;
        front = NULL;
        back = NULL;
    }
};
class LRUCache
{
public:
    Cache *head = NULL, *tail = NULL, *fP;

    int lim = 0, cCap = 0;

    ///////////////////// PRINT THE CURRENT LL
    void fPrinting()
    {
        // cout << "Just for printing!" << endl;
        fP = head;
        while (fP != NULL)
        {

            cout << fP->key << "    " << fP->data << endl;

            // GOING TO THE NEXT NODE
            fP = fP->back;
        }
        // cout << "After printing!" << endl;
    }

    ///////////////////// WILL BE USED MOSTLY FOR GET OPERATION.
    void bringTailFront()
    {
        // cout << "called bringTailFront()" << endl;
        Cache *temp = tail, *tF = tail->front;
        tail = tF;
        tF->back = NULL;
        temp->back = head;
        temp->front = NULL;
        head->front = temp;
        head = temp;
    }
    ///////////////////// WILL BE USED MOSTLY FOR GET OPERATION.
    void bringCacheFront(Cache *ele)
    {
        Cache *temp1 = ele->front, *temp2 = ele->back;
        // Bringing the CACHE FRONT
        ele->front = NULL;
        ele->back = head;
        head = ele;
        // closing the gap
        temp1->back = temp2;
        temp2->front = temp1;
    }

    ///////////////////////// DECIDING FACTOR
    void bringValueToTheFront(Cache *d)
    {
        if (d == head)
        {
            return;
        }
        else if (d == tail)
        {
            bringTailFront();
        }
        else
        {
            bringCacheFront(d);
        }
    }

    LRUCache(int capacity)
    {
        lim = capacity;
    }

    int get(int key)
    {
        if (head == NULL)
        {
            return -1;
        }
        Cache *temp = head;
        while (temp != NULL)
        {
            // cout << "INSIDE WHILE LOOP:   " << temp->data << endl;
            if (temp->key == key)
            {
                int a = temp->data;
                if (temp == head)
                {
                    return a;
                }
                bringValueToTheFront(temp);
                return a;
            }
            temp = temp->back;
        }
        return -1;
    }

    void put(int keyy, int value)
    {
        if (head == NULL)
        {
            head = new Cache(keyy, value);
            tail = head;
            cCap++;
            return;
        }
        Cache *d = head;
        while (d != NULL)
        {
            // cout << "INSIDE WHILE LOOP --- PUT:   " << d->data << endl;
            if (d->key == keyy)
            {
                d->data = value;
                bringValueToTheFront(d);
                // cout << "Before returning:  " << endl;
                return;
            }
            // GOING TO THE NEXT NODE
            d = d->back;
        }

        if (cCap < lim)
        {
            cCap++;
            Cache *n = new Cache(value, keyy, head);
            head->front = n;
            head = n;
            // cout << "INSIDE --- PUT ---- IF CONDITION:   " << head->key << "   " << head->data << endl;
            return;
        }
        else
        {
            if (tail != head)
            {
                cout << "INSIDE PUT: PUTTING    - " << keyy << "  " << value << endl;
                Cache *tDup = tail, *tFDup = tDup->front;
                // cout << tDup->data << endl;
                // string a = head->back == NULL ? "NULL" : "NOT NULL", b = tDup->back == NULL ? "NULL" : "NOT NULL";
                // cout << a << endl;
                // cout << tFDup->data << "   " << tDup->data << endl;
                // // Disconnecting the tail from the LL
                tail = tail->front;
                // cout << "Flag 1" << tDup->data << "   " << tail->data << endl;
                tail->back = NULL;
                // cout << "Flag 2" << endl;
                tDup->front = NULL;
                // cout << "Flag 3" << endl;
                // cout << tDup->data << "   " << tail->data << endl;
                delete (tDup);
                // cout << "Done deleting" << endl;
                // Adding the new value to the front
                Cache *nHead = new Cache(value, keyy, head);
                head->front = nHead;
                head = nHead;

                // cout << "DONE PUTTING" << endl;
            }
            else
            {
                head->data = value;
                head->key = keyy;
            }
        }
    }
};

//////////////////////////////////

// int main()
// {
//     int ans;
//     LRUCache *obj = new LRUCache(2);
//     ans = obj->get(2);
//     cout << "Answer for 2: " << ans << endl;
//     obj->put(2, 6);
//     // obj->fPrinting();
//     ans = obj->get(1);
//     cout << "Answer for 1: " << ans << endl;
//     cout << "BEFORE PUT 1,5" << endl;
//     obj->put(1, 5);
//     cout << "AFTER       PUT 1,5" << endl;
//     // obj->fPrinting();
//     obj->put(1, 2);
//     // obj->fPrinting();
//     cout << "PUT 1,2" << endl;
//     ans = obj->get(1);
//     cout << "Answer for 1: " << ans << endl;
//     ans = obj->get(2);
//     cout << "Answer for 2: " << ans << endl;
//     return 1;
// }

////////////////////////////////

////////////////////////////////

// int main()
// {
//     int ans;
//     LRUCache *obj = new LRUCache(1);
//     ans = obj->get(0);
//     cout << "Answer for 0: " << ans << endl;
//     return 1;
// }

/////////////////////////

///////////////////////

// int main()
// {
//     int ans;
//     LRUCache *obj = new LRUCache(2);
//     // cout << "Attempting 1,1" << endl;
//     obj->put(1, 1);
//     // cout << "INserted 1,1" << endl;
//     obj->put(2, 2);
//     // cout << "INserted 2,2" << endl;
//     ans = obj->get(1);
//     cout << "Answer for 1: " << ans << endl;
//     obj->put(3, 3);
//     // cout << "For get 2: " << endl;
//     ans = obj->get(2);
//     cout << "Answer for 2: " << ans << endl;
//     obj->put(4, 4);
//     ans = obj->get(1);
//     cout << "Answer for 1: " << ans << endl;
//     ans = obj->get(3);
//     cout << "Answer for 3: " << ans << endl;
//     ans = obj->get(4);
//     cout << "Answer for 4: " << ans << endl;
//     return 1;
// }

////////////////////////

////////////////////////

int main()
{
    int ans;
    LRUCache *obj = new LRUCache(1);

    cout << "Attempting 2,1" << endl;
    obj->put(2, 1);
    cout << "INserted 2,1" << endl;
    ans = obj->get(2);
    cout << "Answer for 2: " << ans << endl;
    cout << "Attempting 3,2" << endl;
    obj->put(3, 2);
    cout << "INserted 3,2" << endl;
    ans = obj->get(2);
    cout << "Answer for 2: " << ans << endl;
    ans = obj->get(3);
    cout << "Answer for 3: " << ans << endl;
    return 1;
}

////////////////////////