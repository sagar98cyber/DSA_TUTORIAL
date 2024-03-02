#include <bits/stdc++.h>
using namespace std;

// int main()
// {
//     int temp = 'a' ;
//     char temp2 = temp + 6;
//     cout << 'a' - 'a' << "      " << temp << "     " << temp2 << endl;
//     return 0;
// }

////////   TC -> O(n^n)
// int minimum(vector<int> &mp)
// {
//     int k = INT_MAX;
//     for (auto it : mp)
//     {
//         if (it <= k && it > 0)
//             k = it;
//     }
//     return k;
// }
// int maximum(vector<int> &mp)
// {
//     int k = INT_MIN;
//     for (auto it : mp)
//     {
//         if (it >= k)
//             k = it;
//     }
//     return k;
// }
// int beautySum(string s)
// {
//     int sum = 0;
//     for (int i = 0; i < s.size(); i++)
//     {
//         vector<int> mp(26, 0);
//         for (int j = i; j < s.size(); j++)
//         {
//             mp[s[j] - 'a']++;
//             int mx = maximum(mp);
//             int mn = minimum(mp);
//             sum += mx - mn;
//         }
//     }
//     return sum;
// }


//////////// OPTIMAL SOLUTION
int beautySum(string s)
{
    int res = 0;
    for (auto i = 0; i < s.size(); ++i)
    {
        int cnt[26] = {}, max_f = 0, min_f = 0;
        for (auto j = i; j < s.size(); ++j)
        {
            int idx = s[j] - 'a';
            max_f = max(max_f, ++cnt[idx]);
            if (min_f >= cnt[idx] - 1)
            {
                min_f = cnt[idx];
                for (int k = 0; k < 26; ++k)
                    min_f = min(min_f, cnt[k] == 0 ? INT_MAX : cnt[k]);
            }
            // cout << "   max_f: " << max_f << "     min_f:  " << min_f <<"      max_f - min_f:" << max_f - min_f<<"    res:  " << res << "     String in consideration: " << s.substr(i, j - i)<<endl;
            res += max_f - min_f;
        }
    }
    return res;
}

int main()
{
    cout << beautySum("aabcbaa");
    // cout << beautySum("aabcb");
}
