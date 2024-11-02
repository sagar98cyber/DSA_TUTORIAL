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

    void bringBackCacheFront(Cache *ele)
    {
        // Cache *temp1 = ele;
        last = last->front;
        first->front = ele;
        ele->front = NULL;
        ele->back = first;
        first = ele;
    }

    void bringCacheFront(Cache *ele)
    {
        cout << "bringing the CACHE in FRONT:    --- " << ele->data << endl;
        Cache *temp1 = ele->front, *temp2 = ele->back;
        // if (temp1 != NULL)
        // {
        temp1->back = temp2;
        // }
        // if (temp2 != NULL)
        // {
        temp2->back = temp1;
        // }
        //
        first->front = ele;
        ele->front = NULL;
        ele->back = first;
        first = ele;
    }

public:
    int lim = 0, cCap = 0;
    Cache *first = NULL, *last = NULL;
    LRUCache(int capacity)
    {
        lim = capacity;
        cout << lim << endl;
    }

    int get(int key)
    {

        if (first == NULL)
        {
            return -1;
        }

        // int a = cCap/2;
        Cache *temp = first;
        cout << "First key: " << first->key << "  Key:  " << key << endl;
        int ans = 0;
        while (temp != NULL)
        {
            // cout << "Temp Key:  " << temp->key << " Key: " << key << endl;
            if (temp->key == key)
            {
                ans = temp->data;
                if (temp == last)
                {
                    // cout << "Bringing back to front: " << first->data << "  " << last->data << endl;
                    bringBackCacheFront(temp);
                    // cout << "Brought back to front: "     << first->data << "  " << last->data << endl;
                }
                else if (temp != first)
                {
                    bringCacheFront(temp);
                }
                cout << "Changes in first:  " << first->data << "Last:  " << last->data << endl;
                return ans;
            }
            temp = temp->back;
        }

        return -1;
    }

    void put(int key, int value)
    {
        if (first == NULL)
        {
            first = new Cache(key, value);
            last = first;
            cCap++;
            return;
            // cout << "createdFirst  " << last->key << endl;
        }
        Cache *tD = first;
        // while (tD != NULL)
        // {
        //     cout << "INSIDE WHILE LOOP:  " << key << "  " << tD->key << endl;
        //     if (tD->key == key)
        //     {
        //         tD->data = value;
        //         return;
        //     }
        //     tD = tD->back;
        // }

        if (cCap < lim)
        {
            // cout << "cCap: " << cCap << endl;
            Cache *temp = new Cache(value, key, NULL, first);
            first->front = temp;
            first = temp;
            // cout << "Last:  " << last->data << "  First: " << first->data << endl;
        }
        else
        {
            // cout << "In Final Cache: " << endl;
            // create a new CACHE
            Cache *temp = new Cache(value, key, NULL, first);
            // bring it to the FRONT
            first->front = temp;
            first = temp;
            // cout << "First data:  " << first->data << endl;
            // deleting the LAST element
            temp = last;
            // cout << "Last data:  " << last->data << endl;
            last = last->front;
            last->back = NULL;
            temp->front = NULL;
            temp->back = NULL;
            delete (temp);
            // cout << "Back:  " << last->data << endl;
        }
        cCap++;
        // cout << "Capacity: " << cCap << endl;
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

//     ans = obj->get(1);
//     cout << "Answer for 1: " << ans << endl;

//     obj->put(1, 5);
//     cout << "PUT 1,5" << endl;
//     obj->put(1, 2);
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

int main()
{
    int ans;
    LRUCache *obj = new LRUCache(2);
    obj->put(1, 1);
    obj->put(2, 2);
    ans = obj->get(1);
    cout << "Answer for 1: " << ans << endl;
    obj->put(3, 3);
    cout << "For get 2: " << endl;
    ans = obj->get(2);
    cout << "Answer for 2: " << ans << endl;
    obj->put(4, 4);
    ans = obj->get(1);
    cout << "Answer for 1: " << ans << endl;
    ans = obj->get(3);
    cout << "Answer for 3: " << ans << endl;
    ans = obj->get(4);
    cout << "Answer for 4: " << ans << endl;
    return 1;
}

////////////////////////