#include <bits/stdc++.h>

using namespace std;

vector<int> getVect(string s)
{
    vector<int> temp;
    int count = 1, low = 0, high = 0, n = s.length();

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

        --count;
        temp.push_back(count);
        count = 1;

        low = high;
        // cout << "The new low is: " << low << "  high is: " << high << endl;
    }
    return temp;
}

int resp()
{
    
}

int possibleStringCount(string s, int k)
{
    vector<int> temp = getVect(s);

    int sum = 0, canDed = s - k, n = s.length();

    if (n <= k)
    {
        return 1;
    }

    for (i : temp)
    {
        sum += i;
    }



    return ans + 1;
}

int main()
{
    string s = "abcd";
    s = "abbcccc";
    // s = "aaaa";
    s = "aaabbb"; //// k=3
    int a = possibleStringCount(s, 3);
    cout << a << endl;
    return 1;
}