#include <bits/stdc++.h>

using namespace std;
////////////////  BRUTE FORCE

// long long findScore(vector<int> &nums)
// {
//     int n = nums.size();
//     long long ans = 0;
//     vector<int> tr(n, 0);
//     int i = 0;
//     // for(; i<n; i++){
//     //     cout<<nums[i]<<" "<<tr[i]<<endl;
//     // }
//     for (int i = 0; i < n; i++)
//     {
//         int minV = INT_MAX, loc = 0;
//         for (int j = 0; j < n; j++)
//         {
//             if (nums[j] == 0)
//             {
//                 continue;
//             }
//             if (minV > nums[j])
//             {
//                 minV = nums[j];
//                 loc = j;
//             }
//         }

//         if (minV != INT_MAX)
//         {
//             ans += minV;
//         }
//         nums[loc] = 0;

//         if (loc + 1< n)
//         {
//             nums[loc + 1] = 0;
//         }

//         if (loc - 1 >= 0)
//         {
//             nums[loc - 1] = 0;
//         }
//     }
//     return ans;
// }

////////////////////// OPTIMAL
bool compA(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
    {
        return a.second < b.second;
    }
    return a.first < b.first;
}

long long findScore(vector<int> &nums)
{
    int n = nums.size();
    long long ans = 0;

    vector<pair<int, int>> tr;

    for (int i = 0; i < n; i++)
    {
        pair<int, int> temp = {nums[i], i};
        tr.push_back(temp);
    }

    sort(tr.begin(), tr.end(), compA);
    for (auto &i : tr)
    {
        int minV = i.first, loc = i.second;
        cout << minV << " " << loc << endl;
    }

    for (auto &i : tr)
    {
        int minV = i.first, loc = i.second;

        if (nums[loc] != 0)
        {
            ans += nums[loc];
            nums[loc] = 0;

            if (loc + 1 < n)
            {
                nums[loc + 1] = 0;
            }

            if (loc - 1 >= 0)
            {
                nums[loc - 1] = 0;
            }
        }
        else
        {
            continue;
        }
    }

    return ans;
}

int main()
{
    vector<int> nums = {2, 1, 3, 4, 5, 2};
    nums = {2, 3, 5, 1, 3, 2};
    long long ans = findScore(nums);
    cout << "Final ans:  " << ans << endl;
    return 0;
}