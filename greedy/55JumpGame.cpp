#include <bits/stdc++.h>

using namespace std;

int getMaxPostion(int st, int end, vector<int> &nums)
{
    int pos = st + 1, mxIdx = nums[pos] + pos, mxDis, t = nums[pos] + pos, n = nums.size();

    if (t < n)
    {
        mxDis = nums[nums[pos] + pos];
    }
    if (end >= n - 1)
    {
        return end;
    }
    if (nums[st] == 0)
    {
        return st;
    }
    // cout << pos << " MxDis: " << mxDis << " MxIdx: " << mxIdx << " Start: " << st << " End: " << end << endl;
    for (int i = st + 1; ((i < nums.size()) && (i <= end)); i++)
    {
        if (nums[i] == 0)
        {
            continue;
        }
        int t = nums[i] + i;
        if (t >= n - 1)
        {
            return i;
        }
        if ((t < n) && (mxDis < nums[t]))
        {
            mxDis = nums[nums[i] + i];
            pos = i;
            // if (mxDis >= n - 1)
            // {
            //     return i;
            // }
        }
    }
    // cout << "st: " << st << " pos: " << pos << " Nums[pos]: " << nums[pos] << " MxDis: " << mxDis << endl;
    // cout << "returning: " << pos << endl;
    return pos;
}

bool canJump(vector<int> &nums)
{

    int i = 0, n = nums.size(), lI = -1;
    if (nums[0] == 0)
    {
        if (n > 1)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    if (n == 1)
    {
        return true;
    }
    while ((i < n) && (lI != i))
    {
        // cout << endl
        //      << "Calling! " << i << endl;
        int temp = getMaxPostion(i, nums[i] + i, nums);
        lI = i;
        i = temp;
        if (i >= n - 1)
        {
            return true;
        }
    }

    return 0;
}

int main()
{
    vector<int> t = {3, 2, 1, 0, 4};
    // t = {2, 0, 0, 1, 4};
    // t = {2, 3, 1, 1, 5};
    // t = {2, 0, 0};
    t = {3, 0, 8, 2, 0, 0, 1};
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
    // bool ans = canJump(t);
    // cout << "FINal Ans:  " << ans << endl;
}