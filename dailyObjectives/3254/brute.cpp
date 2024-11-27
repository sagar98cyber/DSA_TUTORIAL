#include <bits/stdc++.h>

using namespace std;

class Solution
{

public:
    int findNextUnevenPoint(int low, int high, vector<int> &nums)
    {
        int notTrueAt = high;
        for (int i = low + 1; i <= high; i++)
        {
            if ((nums[i - 1] >= nums[i]) || ((nums[i - 1] + 1) != nums[i]))
            {
                notTrueAt = i - 1;
                break;
            }
        }
        return notTrueAt;
    }
    vector<int> resultsArray(vector<int> &nums, int k)
    {

        int n = nums.size();
        if (k == 1)
        {
            return nums;
        }
        int low = 0, high = k - 1;
        vector<int> ans;
        int notTrueAt; //= findNextUnevenPoint(low, high, nums);
        // if(notTrueAt == high)
        // {
        //     ans.push_back(nums[high]);
        // }
        // else
        // {
        //     ans.push_back(-1);
        // }
        // cout<<high<<"  "<<nums[high]<<endl;
        while (high < n)
        {

            notTrueAt = findNextUnevenPoint(low, high, nums);
            cout << high << "  " << nums[high] << endl;
            if (notTrueAt == high)
            {
                ans.push_back(nums[high]);
            }
            else
            {
                ans.push_back(-1);
            }
            low++;
            high++;
        }
        return ans;
    }
};