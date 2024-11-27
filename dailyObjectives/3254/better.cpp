#include <bits/stdc++.h>

using namespace std;

int findNextUnevenPoint(int low, int high, vector<int> &nums)
{
    // cout<<"called at-> Low: "<<low<<"   "<<high<<endl;
    int notTrueAt = high;
    for (int i = low + 1; i <= high; i++)
    {
        if ((nums[i - 1] >= nums[i]) || ((nums[i - 1] + 1) != nums[i]))
        {
            notTrueAt = i - 1;
            break;
        }
    }
    // cout<<"Returning at:  "<<notTrueAt<<endl;
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
    int notTrueAt = -1;
    while (high < n) // O(n)
    {
        // notTrueAt = findNextUnevenPoint(low, high, nums);               // O(k)
        // cout<<"Low:  "<<low<<" Value:  "<<nums[low]<<"   High: "<<high<<"    Value: "<<nums[high]<<endl;
        // cout<<"Low:  "<<nums[low]<<"   High: "<<nums[high]<<"   NotTrueAt: "<<notTrueAt<<endl;
        if ((notTrueAt == high - 1) && (nums[high - 1] + 1 == nums[high]))
        {
            notTrueAt = high;
            // cout<<"Insiede FIrst If: Low:  "<<nums[low]<<"   High: "<<nums[high]<<"   NotTrueAt: "<<notTrueAt<<endl;
            ans.push_back(nums[high]);
        }
        else if (notTrueAt < low)
        {
            notTrueAt = findNextUnevenPoint(low, high, nums);
            continue;
        }
        else if (notTrueAt == high)
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
}
;
