// https : // leetcode.com/problems/single-number-iii/

#include <bits/stdc++.h>

using namespace std;

//////////////////////////////////  BRUTE FORCE SOLUTION
// vector<int> singleNumber(vector<int> &nums)
// {
//     if (nums.size() == 2)
//     {
//         return nums;
//     }

//     map<int, int> cnt;
//     vector<int> ans;
//     for (auto i : nums)
//     {
//         cnt[i]++;
//     }

//     for (auto i : cnt)
//     {
//         if (i.second == 1)
//         {
//             ans.push_back(i.first);
//         }
//     }
//     return ans;
// }
///////  TC :- O(n)
///////  SC :- O(2)

//////////////////////////////////  BETTER SOLUTION
vector<int> singleNumber(vector<int> &nums)
{
    int firstXorSec = 0, mask = 1, first = 0;
    // get xor of first and sec
    for (auto &num : nums)
        firstXorSec ^= num;
    cout<<"XORRR:   "<<firstXorSec<<endl;
    // get rightmost set bit in above xor
    while (not(firstXorSec & mask))
        mask <<= 1;
    // get first distinct number
    for (auto &num : nums)
        if (num & mask)
            first ^= num;
    // return ans
    return {first, firstXorSec ^ first};
}

///////  TC :- O(n + n) -> O(n)
///////  SC :- O(1)

int main()
{
    // vector<int> nums = {1,1,2,3,3,4};
    // vector<int> nums = {1, 1, 2, 2, 3, 4};
    // vector<int> nums = {1, 1, 2, 3, 4, 4};
    // vector<int> nums = {0, 1, 2, 2};
    vector<int> nums = {1, 2, 1, 3, 2, 5};
    // vector<int> nums = {1, 1, 0, -2147483648};
    // vector<int> nums = {-1, 2147483647};
    vector<int> ans = singleNumber(nums);
    cout << "Final response is: " << endl;
    for (auto i : ans)
    {
        cout << i << endl;
    }
    return 1;
}