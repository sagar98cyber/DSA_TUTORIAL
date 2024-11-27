#include <bits/stdc++.h>

using namespace std;

bool hasIncresingEle(vector<int> &nums, int k, bool &found1, int idx)
{
    if ((idx + k - 1) >= nums.size())
    {
        cout << "returning false due to size!" << endl;
        return false;
    }
    cout << endl
         << endl
         << endl
         << "Starting index: " << idx << "   " << nums[idx] << endl;
    int t = idx, j = 0;
    while (((t + 1) < nums.size()) && (j < k - 1))
    {
        j++;
        cout << "Considering: " << nums[t] << "   " << nums[t + 1] << endl;
        if (nums[t] >= nums[t + 1])
        {
            cout << "returning False!" << endl;
            return false;
            break;
        }
        t++;
    }
    return true;
}

bool hasIncreasingSubarrays(vector<int> &nums, int k)
{
    bool found1 = false, found2 = false;
    int n = nums.size(), i = 0;
    while (i < n - k)
    {
        int t = i;
        found1 = true;
        found1 = hasIncresingEle(nums, k, found1, i);
        if (found1)
        {
            int startIndex = k + i;
            found2 = hasIncresingEle(nums, k, found2, startIndex);
        }
        cout << "found1:  " << found1 << "   found2:  " << found2 << endl;
        if (found1 && found2)
        {
            return true;
        }
        i++;
    }
    return false;
}

int main()
{
    vector<int> nums;
    int k;
    // nums = {1, 2, 3, 4, 4, 4, 4, 5, 6, 7};
    // k = 5;
    // nums = {2, 5, 7, 8, 9, 2, 3, 4, 3, 1};
    // k = 3;
    // nums = {-3, -19, -8, -16};
    // k = 2;
    nums = {5, 8, -2, -1};
    k = 2;
    bool ans = hasIncreasingSubarrays(nums, k);
    cout << "Ans:  " << ans << endl;
    return 1;
}