// THIS WAS THE BRUTE FORCE SOLUTION

#include <bits/stdc++.h>

using namespace std;

int findElesIncreasing(vector<int> &nums, int idx)
{

    int i = idx, n = nums.size(), count = 1;
    if (idx == n)
    {
        // cout << "REturning ZEROO!!" << endl;
        return 0;
    }
    if (idx == (n - 1))
    {
        return 1;
    }
    while (i < (n - 1))
    {
        if (nums[i] >= nums[i + 1])
        {
            break;
        }
        // count++;
        i++;
    }
    // cout << "Starting INdex:  " << idx << "  Final Index: " << i << endl;

    return i - idx + 1;
}

int maxIncreasingSubarrays(vector<int> &nums)
{

    int n = nums.size(), i = 0, ans = 0;
    for (; i < n - 1; i++)
    {
        int mCount = 0, t = 0;
        int a = findElesIncreasing(nums, i);
        int b = findElesIncreasing(nums, (i + a));
        // cout << "For starting index a: " << i << " - " << nums[i] << " : " << a << "   For starting index b: " << (i + a) << " - " << nums[(i + a)] << " : " << b << endl;
        mCount = min(a, b);
        t = ((a / 2) < (b / 2)) ? (b / 2) : (a / 2);
        mCount = max(mCount, t);
        // cout << "Ans:  " << ans << "  mCount: " << mCount << "   t: " << t << endl;
        ans = max(ans, mCount);
    }
    return ans;
}

int main()
{
    vector<int> nums;
    // int k;
    nums = {1, 2, 3, 4, 4, 4, 4, 5, 6, 7};
    // k = 5;
    // nums = {2, 5, 7, 8, 9, 2, 3, 4, 3, 1};
    //      0  1  2  3  4  5  6  7  8  9
    // k = 3;
    // nums = {-3, -19, -8, -16};
    // k = 2;
    // nums = {5, 8, -2, -1};
    // k = 2;
    nums = {-8, 7, -16, -7, 18};
    int ans = maxIncreasingSubarrays(nums);
    cout << "Ans:  " << ans << endl;
    // return 1;
}