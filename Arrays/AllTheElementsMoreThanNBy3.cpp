#include <bits/stdc++.h>
using namespace std;

//////////////////////////    I REACHED BETTER APPROACH BY MYSELF NOT THE OPTIMAL APPROACH

// vector<int> majorityElement(vector<int> &nums)
// {
//     int n = nums.size();
//     int lim = n/3;
//     vector<int> ans;
//     map<int,int> track;
    
//     for (int i = 0; i < n; i++)
//     {
//         track[nums[i]]+=1;
//     }

//     auto it = track.begin();

//     while (it!=track.end())
//     {
//         // cout << it->first << "    " << it->second << endl;
//         if(it->second>lim)
//         {
//             ans.push_back(it->first);
//         }
//         it++;
//     }

//     return ans;
// }

//////////////////////////          STRIVER'S OPTIMAL SOLUTION
vector<int> majorityElement(vector<int> &nums)
{
    int cnt1=0,cnt2=0,ele1,ele2, n=nums.size();
    for(int i=0; i<n; i++)
    {
        if(cnt1 ==0 && nums[i]!=ele2){
            cnt1=1;
            ele1=nums[i];
        }
        else if(cnt2 ==0 && nums[i]!=ele1)
        {
            cnt2=1;
            ele2 = nums[i];
        }
        else if(nums[i]==ele1){cnt1++;}
        else if (nums[i] == ele2)
        {
            cnt2++;
        }
        else{cnt1--;cnt2--;}
    }
    cnt1=0;
    cnt2=0;
    int lim = n / 3;
    for(int i =0;i<n;i++)
    {
        if(nums[i] == ele1)
        {
            cnt1++;
        }
        if (nums[i] == ele2)
        {
            cnt2++;
        }
    }
    vector<int> ans;
    
    if(cnt1 > lim)
    {
        ans.push_back(ele1);
    }
    
    if (cnt2 > lim)
    {
        ans.push_back(ele2);
    }

    return ans;
}

int main()
{
    vector<int> nums = { 3, 2, 3};
    majorityElement(nums);
}