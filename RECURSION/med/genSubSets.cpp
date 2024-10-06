#include <bits/stdc++.h>

using namespace std;

void gen(vector<vector<int>> &a, vector<int> &val, int n, vector<int> &nums)
{
    if (nums.size() == n)
    {
        a.push_back(val);
        return;
    }
    a.push_back(val);
    for (int i = n + 1; i < nums.size(); i++)
    {
        val.push_back(nums[i]);
        gen(a, val, i, nums);
        val.pop_back();
    }
}

vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> a;
    vector<int> val;
    int n = -1;

    gen(a, val, n, nums);
    for (auto i : a)
    {
        for (auto j : i)
        {
            cout << j << ",";
        }
        cout << endl;
    }
    return a;
}

int main()
{
    vector<int> nums = {1, 2, 3};
    subsets(nums);
    return 0;
}