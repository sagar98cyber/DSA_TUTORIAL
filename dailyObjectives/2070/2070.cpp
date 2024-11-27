#include <bits/stdc++.h>

using namespace std;

void printEverythingInTheMPP(map<int, int> &mpp)
{
    for (auto i : mpp)
    {
        cout << i.first << "  " << i.second << endl;
    }
}

int getTheOTForI(map<int, int> &mpp, int target)
{
    if (mpp.size() == 0)
    {
        return 0;
    }
    auto t = mpp.begin();
    // cout << t->first << "  " << t->second << endl;
    if (t->first > target)
    {
        return 0;
    }
    int ans = 0;
    for (auto i : mpp)
    {
        // cout << i.first << "  " << i.second << endl;
        if (i.first <= target)
        {
            ans = max(ans, i.second);
        }
        else
        {
            break;
        }
    }
    return ans;
}

vector<int> maximumBeauty(vector<vector<int>> &items, vector<int> &queries)
{
    vector<int> ans;

    map<int, int> mpp;

    for (auto i : items)
    {
        // cout << i[0] << "  " << i[1] << endl;
        if (mpp.find(i[0]) != mpp.end())
        {
            mpp[i[0]] = max(mpp[i[0]], i[1]);
        }
        else
        {
            mpp.insert({i[0], i[1]});
        }
    }
    printEverythingInTheMPP(mpp);
    for (auto i : queries)
    {
        if (mpp.find(i) != mpp.end())
        {
            ans.push_back(mpp[i]);
        }
        else
        {
            int a = getTheOTForI(mpp, i);
            ans.push_back(a);
        }
    }

    return ans;
}

int main()
{

    vector<vector<int>> items;
    vector<int> queries, ans;
    // items = {{1, 2}, {3, 2}, {2, 4}, {5, 6}, {3, 5}};
    // queries = {1, 2, 3, 4, 5, 6};

    // items = {{1, 2}, {1, 2}, {1, 3}, {1, 4}};
    // queries = {1};

    // items = {{10, 1000}};
    // queries = {5};

    // items = {{193, 732}, {193, 523}, {781, 962}, {864, 954}, {749, 627}, {136, 746}, {478, 548}, {640, 908}, {210, 799}, {567, 715}, {914, 388}, {487, 853}, {533, 554}, {247, 919}, {958, 150}, {176, 656}, {395, 469}, {763, 821}, {542, 946}, {701, 676}};
    // queries = {885, 1445, 1580, 1309, 205, 1788, 1214, 1404, 572, 1170, 989, 265, 153, 151, 1479, 1180, 875, 276, 1584};

    items = {{743, 617}, {773, 350}, {937, 643}, {395, 585}, {126, 690}, {284, 656}, {999, 401}, {239, 316}, {214, 811}, {269, 539}, {693, 633}, {653, 801}, {108, 465}, {383, 169}, {676, 956}, {155, 329}, {872, 275}, {510, 557}, {423, 169}};
    queries = {506, 294, 743, 203, 553, 1790, 588, 1550, 1007, 1946, 1263, 1544};

    ans = maximumBeauty(items, queries);

    cout << endl
         << endl;
    for (auto i : ans)
    {
        cout << i << "  ";
    }
    return 1;
}