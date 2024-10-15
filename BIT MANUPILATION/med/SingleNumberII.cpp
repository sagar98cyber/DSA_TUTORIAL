// https : // leetcode.com/problems/single-number-ii

#include <bits/stdc++.h>

using namespace std;

//////////////////////////////////  BRUTE FORCE SOLUTION
// int singleNumber(vector<int> &nums)
// {
//     map<int, int> cnt;
//     for (auto i : nums)
//     {
//         cnt[i]++;
//     }
//     for (auto i : cnt)
//     {
//         if (i.second == 1)
//         {
//             return i.first;
//         }
//     }
//     return 0;
// }
///////  TC :- O(n)
///////  SC :- O(n/3) - approximately

//////////////////////////////////  BETTER SOLUTION
// int singleNumber(vector<int> &nums)
// {
//     int ans = 0;
//     for (int i = 0; i <= 31; i++)
//     {
//         int count = 0;
//         for (auto j : nums)
//         {
//             if (j & (1 << i))
//             {
//                 count++;
//             }
//         }
//         if ((count % 3) == 1)
//         {
//             // cout<<"Ans: "<<ans<<"    "<<(1<<i)<<endl;
//             ans = (ans + (1 << i));
//         }
//     }
//     return ans;
// }
///////  TC :- O(n*32)
///////  SC :- O(1)

//////////////////////////////////  OPTIMIZING THE ABOVE SOLUTION
// int singleNumber(vector<int> &nums)
// {
//     sort(nums.begin(), nums.end());
//     for (auto i : nums)
//     {
//         cout << i << endl;
//     }
//     int n = nums.size();
//     int i = 1;
//     while (i < n)
//     {
//         // cout<<"i is: "<<i<<"   N is: "<<n<<endl;
//         if (nums[i] != nums[i - 1])
//         {
//             return nums[i - 1];
//         }
//         // cout<<"Here: "<<endl;
//         i += 3;
//         // cout << "i is: " << i << "   N is: " << n << endl;
//     }
//     // cout << "Value of i:  " << i << endl;
//     i = (i - 3);
//     // cout<<"Value of i:  "<<i<<"   " << (i+2)<<endl;

//     return nums[(i + 2)];
// }
///////  TC :- O((n*LOGn)+(n/3))
///////  SC :- O(1)

//////////////////////////////////  OPTIMAL SOLUTION
int singleNumber(vector<int> &nums)
{
    int one = 0, two = 0;
    for (auto i : nums)
    {
        one = (one ^ i) & (~(two));
        two = (two ^ i) & (~(one));
    }
    return one;
}
///////  TC :- O((n)+(1))
///////  SC :- O(1)

int main()
{
    vector<int> nums = {2, 2, 3, 2};
    int res = singleNumber(nums);
    cout << "Result: " << res;
    return 1;
}