#include <bits/stdc++.h>

using namespace std;

class Cache
{
public:
    int data, key;
    Cache *prev;
    Cache *next;

    Cache(int da, int ke, Cache *pr, Cache *ne)
    {
        this->key = ke;
        this->data = da;
        this->prev = pr;
        this->next = ne;
    }
    Cache(int da, int ke, Cache *ne)
    {
        this->key = ke;
        this->data = da;
        this->prev = NULL;
        this->next = ne;
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
    map<int, int> keyFreq;
    map<int, Cache *> mpp;
    map<int, 
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

    void fPrintingR()
    {
        // cout << "Just for printing!" << endl;
        fP = tail;
        while (fP != NULL)
        {

            cout << fP->key << "    " << fP->data << endl;

            // GOING TO THE NEXT NODE
            fP = fP->prev;
        }
        // cout << "After printing!" << endl;
    }

    ///////////
    void bringANodeToFront(Cache *n)
    {
        cout << "bringing a NODE TO THE FRONT!" << endl;
        fPrinting();
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
        head->next = n;
        t->prev = n;
        n->next = t;
        fPrinting();
        fPrintingR();
    }

    ////////////////
    void deleteANode(Cache *dNode)
    {
        fPrinting();
        Cache *delNext = dNode->next, *delPrev = dNode->prev;
        // b->dNode -> a
        delNext->prev = delPrev;
        delPrev->next = delNext;
        dNode->next = NULL;
        dNode->prev = NULL;
        delete (dNode);
    }

    /////////////////
    Cache *createANewNodeInStart(int k, int d)
    {
        fPrinting();
        Cache *b = head->next;
        Cache *nNode = new Cache(d, k);
        cout << "New node created:   " << nNode->data << ",  " << head->data << ",  " << b->data << endl;
        
        nNode->next = b;
        nNode->prev = head;

        head->next = nNode;
        b->prev = nNode;
        cout << "After New node created:   " << endl;
        fPrinting();
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
        cout << "Before the get!" << endl;
        fPrinting();
        // int val = -1;
        auto it = mpp.find(k);
        if (it == mpp.end())
        {
            return -1;
        }

        Cache *temp = mpp[k];
        int ret = temp->data;
        freq[k]++;
        cout << "Got the value:  " << ret << "  For the key: " << k << "   " << freq[k] << endl;
        bringANodeToFront(temp);
        cout << "After the get!" << endl;
        fPrinting();
        return ret;
    }

    void put(int k, int d)
    {
        cout << "Before the put!" << endl;
        fPrinting();
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
            fPrinting();
            freq[k] = 1;
        }
        cout << "After the put!" << endl;
        fPrintingR();
    }
};

int main()
{
    vector<string> commands = {"LFUCache", "put", "put", "get", "get", "get", "put", "put", "get", "get", "get", "get"};
    vector<vector<int>> val = {{3}, {2, 2}, {1, 1}, {2}, {1}, {2}, {3, 3}, {4, 4}, {3}, {2}, {1}, {4}};

    commands = {"LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get", "get"};
    val = {{2}, {1, 1}, {2, 2}, {1}, {3, 3}, {2}, {3}, {4, 4}, {1}, {3}, {4}};

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