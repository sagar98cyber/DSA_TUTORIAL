#include <bits/stdc++.h>

using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    if (k == 1)
        return nums;

    int i = 0, low = 0, high = 0, n = nums.size(), max = INT_MIN;
    vector<int> ans;
    stack<int> st;
    // cout << low << "  " << high << endl;

    

    return ans;
}

int main()
{
    vector<int> nums, ans;
    nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    nums = {9, 11};
    k = 2;
    nums = {2, 4, 7};
    k = 2;
    nums = {-7, -8, 7, 5, 7, 1, 6, 0};
    k = 4;
    ans = maxSlidingWindow(nums, k);
    for (auto i : ans)
    {
        cout << i << endl;
    }
    return 1;
}