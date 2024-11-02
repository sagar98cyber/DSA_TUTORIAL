#include <bits/stdc++.h>

using namespace std;

int possibleStringCount(string s)
{

    int count = 1, ans = 0, low = 0, high = 0, n = s.length();
    while (low < n && high < n)
    {
        while (s[low] == s[high])
        {
            if (low != high)
            {
                count++;
            }
            // cout << "Incrementing at: " << low << " , " << high << "Count was: " << count << "count is: " << count + 1 << "   -  " << s[low] << "   -  " << s[high] << endl;
            high++;
        }
        // cout << "1   The new low is: " << low << "  high is: " << high << "  Count: " << count << endl;
        ans += (count - 1);
        count = 1;

        // high++;
        low = high;
        // cout << "The new low is: " << low << "  high is: " << high << endl;
    }
    if (!ans)
    {
        return 1;
    }
    return ans + 1;
}

int main()
{
    string s = "abcd";
    s = "abbcccc";
    // s = "aaaa";
    int a = possibleStringCount(s);
    cout << a << endl;
    return 1;
}