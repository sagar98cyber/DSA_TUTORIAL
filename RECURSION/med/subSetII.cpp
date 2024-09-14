#include <bits/stdc++.h>

using namespace std;

void helperFunction(vector<int> &nums, int index, vector<int> &v, vector<vector<int>> &ans)
{
    if (index == nums.size())
    {
        ans.push_back(v);
        return;
    }
    // picking element
    v.push_back(nums[index]);
    helperFunction(nums, index + 1, v, ans);
    v.pop_back();
    // not picking
    while (index + 1 < nums.size() && nums[index] == nums[index + 1])
        index++;
    helperFunction(nums, index + 1, v, ans);
}

int main()
{
    Solution obj;
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> ans = obj.subsetsWithDup(nums);
    printAns(ans);
    return 0;
}