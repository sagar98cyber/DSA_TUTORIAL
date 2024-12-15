#include <bits/stdc++.h>

using namespace std;

// int pageFaults(int n, int c, int pages[])
// {
//     int ans = 0;
//     int i = 0, l = 0;
//     map<int, int> mpp;
//     for (; i < c; i++)
//     {
//         // cout << "Worked for: " << pages[i] << endl;
//         mpp[pages[i]]++;
//     }
//     // for (auto i = mpp.begin(); i != mpp.end(); ++i)
//     // {
//     //     cout << i->first << ": " << i->second << endl;
//     // }
//     // cout << i << i << endl;
//     for (; i < n; i++)
//     {

//         int ele = pages[i];
//         if (mpp[ele] <= 0)
//         {
//             mpp[pages[l]]--;
//             l++;
//         }
//         // cout << i << " " << mpp[ele] << endl;
//         if (mpp[ele] > 0)
//         {
//         }
//         else
//         {
//             // cout << "increasing for: " << pages[i] << endl;
//             ans++;
//         }
//         mpp[pages[i]]++;
//         // int temp = mpp[l];
//     }

//     return ans + c;
// }

int pageFaults(int N, int C, int pages[])
{

    // unordered_map for store the element with their index
    unordered_map<int, int> ump;

    // for count page fault
    int cnt = 0;

    // go through all the pages
    for (int i = 0; i < N; i++)
    {
        // if map size is less than capacity and the current pages doesn't exit
        if (ump.size() < C && ump.find(pages[i]) == ump.end())
        {
            cnt++;
            ump[pages[i]] = i;
        }

        // if map size is equal to capacity and the current pages doesn't exit
        else if (ump.size() == C && ump.find(pages[i]) == ump.end())
        {
            cnt++;

            int min_ind = INT_MAX;
            int first_ele = 0;
            for (auto it : ump)
            {
                if (it.second < min_ind)
                {
                    min_ind = it.second;
                    first_ele = it.first;
                }
            }
            // remove the least recently used page from map and put the current element
            ump.erase(first_ele);
            ump[pages[i]] = i;
        }

        // if current element already present then its it page hit. simply update the index and move on
        else if (ump.find(pages[i]) != ump.end())
        {
            ump[pages[i]] = i;
        }
    }

    // return final count of page fault
    return cnt;
}
int main()
{
    int n = 8;
    // int pages[8] = {2, 3, 1, 3, 1, 3, 1, 2};
    int c = 3;

    n = 9;
    c = 4;
    int pages[9] = {5, 0, 1, 3, 2, 4, 1, 0, 5};

    for (int i = 0; i < n; i++)
    {
        cout << pages[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << endl;

    int ans = pageFaults(n, c, pages);
    cout << "final ans: " << ans << endl;
}