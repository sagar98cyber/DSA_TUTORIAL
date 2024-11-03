#include <bits/stdc++.h>

using namespace std;

class Cache
{
public:
    int data, key;
    Cache *prev;
    Cache *next;

    Cache(int da, int ke, Cache *fr, Cache *ba)
    {
        key = ke;
        data = da;
        prev = fr;
        next = ba;
    }
    Cache(int da, int ke, Cache *ba)
    {
        key = ke;
        data = da;
        prev = NULL;
        next = ba;
    }
    Cache(int da, int ke)
    {
        key = ke;
        data = da;
        prev = NULL;
        next = NULL;
    }
};

class LRUCache
{
public:
    Cache *tail = new Cache(-1, -1), *head = new Cache(-1, -1, tail), *fP;
    map<int, Cache *> mpp;
    int lim = 0, cCap = 0;

    //////////////////////// Adding a new element to the LL
    void addNewCacheFront(Cache *newNode)
    {
        int k = newNode->key, d = newNode->data;
        Cache *t = head->next;

        newNode->next = t;
        newNode->prev = head;

        t->prev = newNode;
        head->next = newNode;

        mpp.insert({k, newNode});
    }

    ///////////////////// PRINT THE CURRENT LL
    void fPrinting()
    {
        // cout << "Just for printing!" << endl;
        fP = head;
        while (fP != NULL)
        {

            cout << fP->key << "    " << fP->data << endl;

            // GOING TO THE NEXT NODE
            fP = fP->next;
        }
        // cout << "After printing!" << endl;
    }

    ///////////////////// Delete the LRU

    // t1 -> t -> tail
    // t1 -> tail
    // t1 <- tail
    void deleteTheLRU()
    {
        Cache *t = tail->prev;
        if (t != head)
        {
            mpp.erase(t->key);
            Cache *t1 = t->prev;
            t1->next = tail;
            tail->prev = t1;
            delete (t);
        }
    }

    ///////////////////// WILL BE USED MOSTLY FOR GET OPERATION.
    void bringCacheFront(Cache *ele)
    {
        int key = ele->key, value = ele->data;
        Cache *temp1 = ele->prev, *temp2 = ele->next;
        // DELETING THE CACHE
        delete (ele);

        // Bringing the CACHE FRONT
        Cache *nHead = new Cache(value, key);
        addNewCacheFront(nHead);

        // closing the gap
        temp1->next = temp2;
        temp2->prev = temp1;
    }

    LRUCache(int capacity)
    {
        lim = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {
        if (head == NULL)
        {
            return -1;
        }

        // GET THE VALUE FROM THE HASH MAP
        if (mpp.find(key) != mpp.end())
        {
            Cache *a = mpp[key];
            int ans = a->data;
            bringCacheFront(a);
            return ans;
        }

        return -1;
    }

    void put(int keyy, int value)
    {
        // Check if the key exists
        //   If yes then modify the value.
        if ((mpp.find(keyy) != mpp.end()))
        {
            Cache *a = mpp[keyy];
            a->data = value;
            bringCacheFront(a);
            return;
        }

        // Can add new elements as there is still space left
        if (cCap < lim)
        {
            Cache *nHead = new Cache(value, keyy);
            addNewCacheFront(nHead);
            cCap++;
        }
        else
        {
            deleteTheLRU();
            Cache *nHead = new Cache(value, keyy);
            addNewCacheFront(nHead);
        }
    }
};

////////////////////////  FOURTH TEST CASE

int main()
{
    int ans;
    LRUCache *obj = new LRUCache(1);
    // obj->fPrinting();
    // cout << "Attempting 2,1" << endl;
    obj->put(2, 1);
    // cout << "INserted 2,1" << endl;
    ans = obj->get(2);
    cout << "Answer for 2: " << ans << endl;
    // cout << "Attempting 3,2" << endl;
    obj->put(3, 2);
    // cout << "INserted 3,2" << endl;
    ans = obj->get(2);
    cout << "Answer for 2: " << ans << endl;
    ans = obj->get(3);
    cout << "Answer for 3: " << ans << endl;
    return 1;
}

////////////////////////

///////////////////////    THIRD TEST CASE

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
//     // cout << "BEFORE PUT 1,5" << endl;
//     obj->put(1, 5);
//     // cout << "AFTER       PUT 1,5" << endl;
//     // obj->fPrinting();
//     obj->put(1, 2);
//     // obj->fPrinting();
//     // cout << "PUT 1,2" << endl;
//     ans = obj->get(1);
//     cout << "Answer for 1: " << ans << endl;
//     ans = obj->get(2);
//     cout << "Answer for 2: " << ans << endl;
//     return 1;
// }

////////////////////////////////

///////////////////////    SECOND TEST CASE

// int main()
// {
//     int ans;
//     LRUCache *obj = new LRUCache(1);
//     ans = obj->get(0);
//     cout << "Answer for 0: " << ans << endl;
//     return 1;
// }

/////////////////////////

///////////////////////    FIRST TEST CASE

// int main()
// {
//     int ans;
//     LRUCache *obj = new LRUCache(2);
//     // cout << "Attempting 1,1" << endl;
//     obj->put(1, 1);
//     // obj->fPrinting();
//     // cout << "INserted 1,1" << endl;
//     obj->put(2, 2);
//     // obj->fPrinting();
//     // cout << "INserted 2,2" << endl;
//     ans = obj->get(1);
//     cout << "Answer for 1: " << ans << endl;
//     // obj->fPrinting();
//     obj->put(3, 3);
//     // cout << "For get 2: " << endl;
//     // obj->fPrinting();
//     ans = obj->get(2);
//     cout << "Answer for 2: " << ans << endl;
//     // obj->fPrinting();
//     // cout << "Attempting to insert: 4,4" << endl;
//     obj->put(4, 4);
//     // obj->fPrinting();
//     ans = obj->get(1);
//     cout << "Answer for 1: " << ans << endl;
//     // obj->fPrinting();
//     ans = obj->get(3);
//     cout << "Answer for 3: " << ans << endl;
//     // obj->fPrinting();
//     ans = obj->get(4);
//     cout << "Answer for 4: " << ans << endl;
//     return 1;
// }

////////////////////////
