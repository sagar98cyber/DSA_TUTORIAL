#include <bits/stdc++.h>

using namespace std;

int maxScore(vector<int> &nums, int k)
{
    int low = 0, n = nums.size(), high = n - 1, cK = 0, mScore = 0;
    while ((low <= high) && (cK != k))
    {
        cK++;
        cout << nums[low] << "   " << nums[high] << endl;
        if (nums[low] > nums[high])
        {
            mScore += nums[low];
            low++;
        }
        else
        {
            mScore += nums[high];
            high--;
        }
    }
    return mScore;
}

int main()
{
    vector<int> nums;
    int k;

    // nums = {1, 2, 3, 4, 5, 6, 1};
    // k = 3;

    // nums = {2, 2, 2};
    // k = 2;

    // nums = {9, 7, 7, 9, 7, 7, 9};
    // k = 7;

    // nums = {1, 2, 3, 4, 5, 6, 1};
    // k = 3;

    nums = {1, 2, 3, 4, 5, 6, 1};
    k = 3;

    int ans = maxScore(nums, k);
    cout << "Ans: " << ans << endl;
}