#include <bits/stdc++.h>

using namespace std;

vector<int> track(26, 0);

int characterReplacement(string s, int k)
{
    int low = 0, high = 1, n = s.length(), mCount = 1, ans = 1;

    int cCount = 0;

    while (high < n)
    {
        cCount = high - low + 1;
        
        track[s[high] - 'A']++;
        mCount = max(mCount, track[s[high] - 'A']);
        
        cCount = high - low + 1;
        
        if ((cCount - mCount) > k)
        {
            track[s[low] - 'A']--;
            low++;
        }
        cCount = high - low + 1;
        if ((cCount - mCount) <= k)
        {
            ans = max(ans, cCount);
        }
        high++;
    }

    return ans;
}

int main()
{
    string s;
    int k, ans;
    s = "AABAAABBA";
    k = 1;

    // s = "ABAB";
    // k = 2;

    cout << s << endl;
    for (int i = 0; i < s.length(); i++)
    {
        cout << i;
    }
    cout << endl;
    ans = characterReplacement(s, k);
    cout << "ANS:  " << ans << endl;
}