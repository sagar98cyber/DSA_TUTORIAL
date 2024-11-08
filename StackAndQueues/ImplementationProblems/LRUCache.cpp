#include <bits/stdc++.h>

using namespace std;

class LRUCache
{
public:
public:
    class node
    {
    public:
        int key;
        int val;
        node *next;
        node *prev;
        node(int _key, int _val)
        {
            key = _key;
            val = _val;
        }
    };

    node *head = new node(-1, -1);
    node *tail = new node(-1, -1);

    int cap;
    unordered_map<int, node *> m;

    LRUCache(int capacity)
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addnode(node *newnode)
    {
        node *temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }

    void deletenode(node *delnode)
    {
        node *delprev = delnode->prev;
        node *delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }

    int get(int key_)
    {
        if (m.find(key_) != m.end())
        {
            node *resnode = m[key_];
            int res = resnode->val;
            m.erase(key_);
            deletenode(resnode);
            addnode(resnode);
            m[key_] = head->next;
            return res;
        }

        return -1;
    }

    void put(int key_, int value)
    {
        if (m.find(key_) != m.end())
        {
            node *existingnode = m[key_];
            m.erase(key_);
            deletenode(existingnode);
        }
        if (m.size() == cap)
        {
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }

        addnode(new node(key_, value));
        m[key_] = head->next;
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
