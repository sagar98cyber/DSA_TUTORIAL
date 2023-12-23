#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    sort(nums.begin(),nums.end());
    vector<vector<int>> ans;
    int i = 0, n = nums.size();
    
    for(int i=0; i<n; i++){
        if(i!=0 && nums[i] == nums[i-1]){
            continue;
        }
        int j = i + 1, k = n - 1;
        
        while (j < k)
        {
            int result = nums[i] + nums[j] + nums[k];
            if(result>0)
            {
                k--;
            }
            if(result<0)
            {
                j++;
            }
            if(result == 0)
            {
                vector<int> temp = {nums[i], nums[j], nums[k]};
                ans.push_back(temp);
                j++;
                k--;
                // skip the duplicates:
                while (j < k && nums[j] == nums[j - 1])
                    j++;
                while (j < k && nums[k] == nums[k + 1])
                    k--;
            }
        }

    }


    return ans;
}

int main(){
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    threeSum(nums);
}