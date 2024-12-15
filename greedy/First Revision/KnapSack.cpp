#include <bits/stdc++.h>

using namespace std;

struct Item
{
    int value;
    int weight;
};

bool compA(Item a, Item b)
{
    return ((double)a.value / (double)a.weight) > ((double)b.value / (double)b.weight);
}

double fractionalKnapsack(vector<int> &val, vector<int> &wt, int capacity)
{
    // Your code here
    int n = val.size();
    double ans = 0.0;
    Item d;
    vector<Item> temp(n, d);
    for (int i = 0; i < n; i++)
    {
        temp[i].value = val[i];
        temp[i].weight = wt[i];
    }

    // for (int i = 0; i < n; i++)
    // {
    //     cout << temp[i].value << " " << temp[i].weight << endl;
    // }

    // cout << endl;
    double cap = capacity;
    sort(temp.begin(), temp.end(), compA);
    // for (int i = 0; i < n; i++)
    // {
    //     cout << temp[i].value << " " << temp[i].weight << endl;
    // }
    // int i = 0;
    // int v = temp[i].value, w = temp[i].weight;
    for (int i = 0; i < n; i++)
    {
        int v = temp[i].value, w = temp[i].weight;
        if (w <= cap)
        {
            ans += v;
            cap -= w;
        }
        else
        {
            // int remain =
            ans += ((v / (double)w) * ((double)cap));
            break;
        }
    }
    return ans;
}

int main()
{
    vector<int> val, wt;
    int cap;
    double ans = 0.0;

    val = {100, 120, 60};
    wt = {20, 30, 10};
    cap = 50;

    val = {100, 60};
    wt = {20, 10};
    cap = 50;

    val = {10, 20, 30};
    wt = {5, 10, 15};
    cap = 100;

    val = {8, 2, 10, 1, 9, 7, 2, 6, 4, 9};
    wt = {10, 1, 7, 7, 5, 1, 8, 6, 8, 7};
    cap = 21;

    ans = fractionalKnapsack(val, wt, cap);
    cout << "Final Ans: " << (double)ans << endl;
    return 0;
}












