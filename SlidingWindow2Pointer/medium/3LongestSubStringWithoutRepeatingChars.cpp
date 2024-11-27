#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s == " " || s.length() == 1)
        {
            return 1;
        }
        vector<int> track(128, 0);
        int n = s.length(), low = 0, high = 1, mCount = 0;
        string bigAns;
        bigAns.push_back(s[low]);
        track[s[low]] = 1;
        while (low <= high && high < n)
        {
            if (track[s[high]] == 0)
            {
                // bigAns.push_back(s[high]);
                // cout<<"Biggest subString:  "<<bigAns<<endl;
            }
            else
            {
                while ((track[s[high]] != 0) && (low < high))
                {
                    track[s[low]]--;
                    low++;
                }
                // bigAns = s.substr(low,high-low+1);
            }

            int c = s[high];
            // cout<<"Current high: "<<high<<"  Low:  "<<low<<" c: "<<c<<endl;

            int temp = high - low + 1;
            mCount = max({mCount, temp});

            track[c]++;
            high++;
        }
        return mCount;
    }
};