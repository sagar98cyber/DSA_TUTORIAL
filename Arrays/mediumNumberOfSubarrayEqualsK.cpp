#include <bits/stdc++.h>

using namespace std;

int subarraySum(vector<int> &nums, int k)
{

    unordered_map<int, int> mpp;
    mpp[0] = 1;
    int sum = 0, cnt = 0;
    for (int i = 0; i < nums.size(); i++)
    {

        sum += nums[i];
        int sum_k = sum - k;
        cnt += mpp[sum_k];
        mpp[sum] += 1;

        // cout<< "Count: "<<cnt<<"  "<<"   sum_k:  "<<sum_k<<"  "<<"   MPP[sum_k]:  "<<mpp[sum_k]<<"    sum:  "<<sum<<"   MPP[sum]:   "<<mpp[sum]<<endl;
    }
    return cnt;
}


int main()
{
    vector<int> nums = {1, 1, 1};
    int k = 1;

    cout<<"Well:  "<<subarraySum(nums,k);
}