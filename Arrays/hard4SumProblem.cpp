#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    int n = nums.size();
    
    sort(nums.begin(), nums.end());
    
    vector<vector<int>> result;

    for (int i = 0; i < n; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            {
                continue;
            }
    
        for( int j=i+1; j<n; j++)
        {
            if (j > i + 1 && nums[j] == nums[j - 1])
                {
                    continue;
                }
    
            int k = j+1;
            int l = n-1;
          
            while(k<l)
            {
                
                long long sum = nums[i] + nums[j] + nums[k] + nums[l];
                if (sum == target)
                {
                    vector<int> temp = { nums[i] , nums[j] , nums[k] , nums[l] };
                    result.push_back(temp);
                    k++;l--;
                    while (k < l && nums[k] == nums[k - 1])
                    {
                        k++;
                    }
                    while (k < l && nums[l] == nums[l + 1])
                    {
                        l--;
                    }
                }
                else if(sum<target)
                {
                    k++;
                }
                else
                {
                    l--;
                }
            }
        }
    }
    return result;

    // for(int i = 0; i<result.size(); i++)
    // {
    //     for( int j=0; j<result[i].size(); j++)
    //     {
    //         cout<<result[i][j]<<"  ";
    //     }
    //     cout<<endl;
    // }
}



int main()
{
    vector<int> nums = { 1, 0, -1, 0, -2, 2 }; 
    int target = 0;
    fourSum(nums,target);
}