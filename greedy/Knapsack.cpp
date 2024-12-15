#include <bits/stdc++.h>

using namespace std;

// double fractionalKnapsack(vector<int> &val, vector<int> &wt, int cap)
// {
//     // Your code here
//     int n = val.size(), m = wt.size();
//     //  ratio - <val, wt>
//     vector<pair<int, pair<int, int>>> p;
//     for (int i = 0; i < n; i++)
//     {
//         // cout << wt[i] << "  " << val[i] << endl;
//         int t = val[i] / wt[i];
//         p.push_back(make_pair(t, make_pair(val[i], wt[i])));
//         // p.push_back({t, make_pair(val[i], wt[i])});
//     }
//     sort(p.begin(), p.end());
//     int curCap = 0;
//     double ans = 0.0;
//     // for (int i = 0; i < n; i++)
//     // {
//     //     auto curEle = p[i];
//     //     int weight = curEle.second.second, value = curEle.second.first;
//     //     cout << weight << " " << value << endl;
//     // }
//     // for (int i = n - 1; i >= 0; i--)
//     for (int i = 0; i < n; i++)
//     {
//         auto curEle = p[i].second;
//         int weight = curEle.second, value = curEle.first;
//         // cout << weight << " " << value << endl;
//         if ((curCap + weight) < cap)
//         {
//             // cout << "Adding weight" << weight << "  to curCap: " << curCap << endl;
//             curCap += weight;
//             ans += (double)value;
//         }
//         else
//         {
//             double sCap = value / weight;
//             int requiredCap = cap - curCap;
//             // cout << "Cap: " << cap << " curCap: " << curCap << " Required Cap: " << requiredCap << " sCap: " << sCap << "  ANs: " << ans << endl;
//             curCap += requiredCap;
//             // cout << "Ans: Before: " << ans << endl;
//             ans = ans + (double)(requiredCap * sCap);
//             cout << "Ans: After: " << ans << endl;
//             break;
//         }
//     }
//     return ans;
// }

struct Item
{
    int value;
    int weight;
};

bool static comp(Item a, Item b)
{
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;
    return r1 > r2;
}
// function to return fractionalweights

double fractionalKnapsack(vector<int> &val, vector<int> &wt, int W)
{
    int n = val.size(), m = wt.size();
    //  ratio - <val, wt>
    Item p[n];
    Item temp;
    for (int i = 0; i < n; i++)
    {
        double t = val[i] / wt[i];
        temp = Item({val[i], wt[i]});
        p[i] = temp;
    }

    sort(p, p + n, comp);

    int curWeight = 0;
    double finalvalue = 0.0;

    for (int i = 0; i < n; i++)
    {

        if (curWeight + p[i].weight <= W)
        {
            curWeight += p[i].weight;
            finalvalue += p[i].value;
        }
        else
        {
            int remain = W - curWeight;
            finalvalue += (p[i].value / (double)p[i].weight) * (double)remain;
            break;
        }
    }

    return finalvalue;
}

int main()
{
    vector<int> val, wt;
    int cap;
    double ans = 0.0;

    val = {60, 100, 120};
    wt = {10, 20, 30};
    cap = 50;

    val = {8, 2, 10, 1, 9, 7, 2, 6, 4, 9};
    wt = {10, 1, 7, 7, 5, 1, 8, 6, 8, 7};
    cap = 21;

    ans = fractionalKnapsack(val, wt, cap);
    cout << "Final Ans: " << (double)ans << endl;
    return 0;
}