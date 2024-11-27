#include <bits/stdc++.h>

using namespace std;

int totalFruits(vector<int> &nums)
{
    if (nums.size() == 1)
    {
        return 1;
    }
    if (nums.size() == 2)
    {
        return 2;
    }
    int low = 0, high = 1, n = nums.size(), mCount = 0;
    int f1 = -1, f2 = -1;
    map<int, int> mpp;
    f1 = nums[low];
    mpp.insert({f1, 1});

    while ((high < n) && (low < high))
    {
        int nHigh = nums[high];
        if ((f1 == nHigh) || (f2 == nHigh))
        {
            mpp[nHigh]++;
        }
        // else if (f1 == -1)
        // {
        //     f1 = nHigh;
        //     mpp.insert({nHigh, 1});
        // }
        else if (f2 == -1)
        {
            f2 = nHigh;
            mpp.insert({nHigh, 1});
        }
        else // if ((nHigh != f1) && (nHigh != f2))
        {
            // cout << "came inside else! Low:  " << low << "   high: " << high << "   f1: " << f1 << "   f2:  " << f2 << endl;
            while ((low < high) && (f1 != -1) && (f2 != -1))
            {
                int nLow = nums[low];
                // cout << "nLow:  " << nLow << endl;
                if (mpp[nLow] == 1)
                {
                    nLow == f1 ? f1 = -1 : f2 = -1;
                    // cout << "   f1: " << f1 << "   f2:  " << f2 << endl;
                }
                mpp[nLow]--;
                if (mpp[nLow] == 0)
                {
                    // cout << "Erasing nLow: " << nLow << endl;
                    mpp.erase(nums[low]);
                }
                low++;
            }
            if (f1 == -1)
            {
                f1 = f2;
                f2 = -1;
            }
            int t = high - low + 1;
            // cout << "After   Low: " << low << "   high:  " << high << "    t: " << t << endl;
            mCount = max(t, mCount);
            continue;
        }
        // cout << "Before   Low: " << low << "   high:  " << high << endl;
        int t = high - low + 1;
        // cout << "After   Low: " << low << "   high:  " << high << "    t: " << t << endl;
        mCount = max(t, mCount);
        high++;
    }
    return mCount;
}

int main()
{
    vector<int> nums;

    // nums = {2, 1, 2};
    nums = {1, 1, 5, 6, 7, 8, 9};
    /*      0  1  2  3  4  5  6        */

    int ans = totalFruits(nums);
    cout << "Ans: " << ans << endl;
}