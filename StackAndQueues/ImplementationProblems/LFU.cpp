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
        this->key = ke;
        this->data = da;
        this->prev = fr;
        this->next = ba;
    }
    Cache(int da, int ke, Cache *ba)
    {
        this->key = ke;
        this->data = da;
        this->prev = NULL;
        this->next = ba;
    }
    Cache(int da, int ke)
    {
        this->key = ke;
        this->data = da;
        this->prev = NULL;
        this->next = NULL;
    }
};

class LFUCache
{
public:
    int limit = 0;
    Cache *head, *tail, *fP;

    map<int, Cache *> mpp;
    map<int, int> freq;

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

    ///////////
    void bringANodeToFront(Cache *n)
    {
        Cache *nodePrev = n->prev;
        Cache *nodeNext = n->next, *t = head->next;

        // close the gap
        nodePrev->next = nodeNext;
        nodeNext->prev = nodePrev;

        // bringing the NODE to FRONT
        //     next  next
        // head -> n -> t
        //
        //     prev  prev
        // head <- n <- t

        n->prev = head;
        t->prev = n;
        head->next = n;
        n->next = t;
    }

    ////////////////
    void deleteANode(Cache *dNode)
    {
        Cache *a = dNode->next, *b = dNode->prev;
        // b->dNode -> a
        a->prev = b;
        b->next = a;

        delete (dNode);
    }

    /////////////////
    Cache *createANewNodeInStart(int k, int d)
    {
        Cache *a = head, *b = head->next, *nNode = new Cache(d, k, a, b);

        a->next = nNode;
        b->prev = nNode;

        return nNode;
    }

    ////////////////
    int getLeastFrequentlyUsedKey()
    {
        int keyToRet = -1;
        int minFreq = INT_MAX;
        map<Cache *, int> multiNodes;

        for (auto i = freq.begin(); i != freq.end(); i++)
        {
            if (minFreq > i->second)
            {
                minFreq = i->second;
            }
        }

        for (auto i = freq.begin(); i != freq.end(); i++)
        {
            if (minFreq == i->second)
            {
                int k = i->first;
                Cache *t = mpp[k];
                multiNodes.insert({t, k});
            }
        }

        if (multiNodes.size() == 1)
        {
            auto itrB = multiNodes.begin();
            keyToRet = itrB->second;
            Cache *t = itrB->first;
            bringANodeToFront(t);
            freq[keyToRet]++;
            return keyToRet;
        }

        Cache *dupTail = tail->prev;

        while (dupTail != head)
        {

            auto it = multiNodes.find(dupTail);

            if (it != multiNodes.end())
            {
                keyToRet = dupTail->key;
                bringANodeToFront(dupTail);
                break;
            }

            dupTail = dupTail->prev;
        }
        return keyToRet;
    }

    LFUCache(int capacity)
    {
        limit = capacity;
        head = new Cache(-1, -1);
        tail = new Cache(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int k)
    {
        int val = -1;
        auto it = mpp.find(k);
        if (it == mpp.end())
        {
            return -1;
        }

        Cache *a = mpp[k];
        int ret = a->data;
        freq[k]++;
        bringANodeToFront(a);
        return ret;
    }

    void put(int k, int d)
    {
        auto it = mpp.find(k);

        if (it != mpp.end())
        {
            // cout << it. ;
            freq[k]++;
            Cache *eNode = mpp[k];
            // cout
            eNode->data = d;
            bringANodeToFront(eNode);
            return;
        }

        if (mpp.size() < limit)
        {
            Cache *newCache = createANewNodeInStart(k, d);
            mpp.insert({k, newCache});
            freq[k] = 1;
        }
        else
        {
            int nK = getLeastFrequentlyUsedKey();
            freq.erase(nK);
            deleteANode(mpp[nK]);
            mpp.erase(nK);
            Cache *nNode = createANewNodeInStart(k, d);
            mpp.insert({k, nNode});
            freq[k] = 1;
        }
    }
};

// int main()
// {
//     int ans;
//     LFUCache *obj = new LFUCache(2);
//     obj->put(1, 1);
//     // cout << "Inserted 1,1 " << endl;
//     obj->put(2, 2);
//     // cout << "Inserted 2,2 " << endl;
//     ans = obj->get(1);
//     cout << "Answer for getting 1:  " << ans << endl;
//     obj->put(3, 3);
//     // cout << "Inserted 3,3 " << endl;
//     ans = obj->get(2);
//     cout << "Answer for getting 2:  " << ans << endl;
//     ans = obj->get(3);
//     cout << "Answer for getting 3:  " << ans << endl;
//     obj->put(4, 4);
//     // cout << "Inserted 4,4 " << endl;
//     ans = obj->get(1);
//     cout << "Answer for getting 1:  " << ans << endl;
//     ans = obj->get(3);
//     cout << "Answer for getting 3:  " << ans << endl;
//     ans = obj->get(4);
//     cout << "Answer for getting 4:  " << ans << endl;
//     obj->fPrinting();
//     return 1;
// }

int main()
{
    vector<string> commands = {"LFUCache", "put", "put", "get", "get", "get", "put", "put", "get", "get", "get", "get"};
    vector<vector<int>> val = {{3}, {2, 2}, {1, 1}, {2}, {1}, {2}, {3, 3}, {4, 4}, {3}, {2}, {1}, {4}};
    int i = 0, ans = 0;
    LFUCache *obj;
    for (auto stri : commands)
    {
        if (stri == "LFUCache")
        {
            obj = new LFUCache(val[i][0]);
        }
        else if (stri == "put")
        {
            obj->put(val[i][0], val[i][1]);
            // cout << "Inserted " << val[i][0] << ", " << val[i][1] << endl;
        }
        else
        {
            ans = obj->get(val[i][0]);
            cout << "Answer for getting: " << val[i][0] << " :  " << ans << endl;
        }
        i++;
    }
    obj->fPrinting();
}