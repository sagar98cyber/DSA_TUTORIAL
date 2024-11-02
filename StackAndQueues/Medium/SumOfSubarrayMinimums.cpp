#include <bits/stdc++.h>

using namespace std;

void getPSE(vector<int> &nums, vector<int> &left)
{
    int j = -1;
    for (int i = 0; i < nums.size(); i++)
    {
        while (j >= 0 && nums[j] > nums[i])
            j = left[j];
        left[i] = j;
        j = i;
    }
    cout << "left: " << endl;
    for (int i = 0; i < left.size(); i++)
    {
        cout << left[i] << endl;
    }
}

void getNSE(vector<int> &nums, vector<int> &right)
{

    int n = nums.size(), j = n;
    for (int i = n - 1; i >= 0; i--)
    {
        while (j < n && nums[j] >= nums[i])
            j = right[j];
        right[i] = j;
        j = i;
    }
    cout << "RIGHT: " << endl;
    for (int i = 0; i < right.size(); i++)
    {
        cout << right[i] << endl;
    }
}

int sumSubarrayMins(vector<int> &nums)
{
    long long m = 10e9 + 7;
    int ans = 0, n = nums.size();
    vector<int> left(n, 0), right(n, 0);
    getPSE(nums, left);
    getNSE(nums, right);
    for (int i = 0; i < n; i++)
    {
        long count = (i - left[i]) * (right[i] - i);
        ans = (ans + (nums[i] * count)) % m;
    }
    return ans;
}

int main()
{
    vector<int> a = {3, 1, 2, 4};
    int ans = sumSubarrayMins(a);
    cout << ans << endl;
    return ans;
}