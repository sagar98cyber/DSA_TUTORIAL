
#include <bits/stdc++.h>

using namespace std;

void printVect(vector<int>& a)
{
    for (auto i:a)
    {
        cout<<i<<endl;
    }
}

void genSubSum(int i, int sum, vector<int> &c, vector<int> &a)
{
    if (i == c.size())
    {
        a.push_back(sum);
        return;
    }

    // a.push_back(sum);

    // for(int x = i; x<c.size(); x++)
    // {
    //     sum+=c[x];
    //     genSubSum(x+1,sum,c,a);
    //     sum-=c[x];
    // }

    sum += c[i];
    genSubSum(i + 1, sum, c, a);
    sum -= c[i];

    genSubSum(i + 1, sum, c, a);
}

vector<int> subsetSums(vector<int> arr, int n)
{
    // Write Your Code here
    vector<int> ans;

    genSubSum(0, 0, arr, ans);

    return ans;
}

int main()
{
    int n = 3;
    vector<int> arr = { 1, 2, 1 };

    vector<int> ans = subsetSums(arr,n);
    sort(ans.begin(), ans.end());
    printVect(ans);
}

