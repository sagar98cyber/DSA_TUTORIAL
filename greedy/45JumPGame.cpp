#include <bits/stdc++.h>

using namespace std;

int getMax(int st, int end, vector<int> &nums)
{
    int maxIdx = st, n = nums.size();

    if (st + end >= (n - 1))
    {
        return st + end;
    }

    for (int i = 1; ((maxIdx < n) && (i <= end)); i++)
    {
        cout << "----- i: " << i << endl;
        if (nums[i] == 0)
        {
            continue;
        }
        int t = nums[i] + i;
        maxIdx = max(maxIdx, t);
    }
    return maxIdx;
}

int jump(vector<int> &nums)
{
    int i = 0, ans = 0, n = nums.size(), curIdx = 0;
    if (n == 1)
    {
        return false;
    }
    if (nums[0] == 0)
    {
        if (n >= 1)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    while (i < n)
    {

        int th = nums[i], d = i + nums[i];
        if (i >= (n - 1))
        {
            return ans;
        }
        int t = getMax(i, th, nums);
        i = t;
        ans++;
        cout << "OUT   -   i: " << i << "  th: " << th << "  d: " << d << "  Ans: " << ans << endl;
    }
    cout << "REturning ans: " << ans << endl;
    return ans;
}

int main()
{
    vector<int> t = {3, 2, 1, 3, 4};
    // t = {2, 0, 0, 1, 4};
    // t = {2, 0, 0};
    // t = {3, 0, 8, 2, 0, 0, 1};
    t = {1, 1, 1, 1};
    // t = {2, 3, 0, 1, 4};
    // t = {2, 3, 1, 1, 5};
    // t = {1, 2};
    for (int i = 0; i < t.size(); i++)
    {
        cout << t[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < t.size(); i++)
    {
        cout << i << " ";
    }
    cout << endl;
    int ans = jump(t);
    cout << "FINal Ans:  " << ans << endl;
}