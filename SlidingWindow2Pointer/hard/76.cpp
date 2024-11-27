#include <bits/stdc++.h>

using namespace std;

void printMap(map<int, int> tMpp)
{
    for (auto i : tMpp)
    {
        cout << i.first << " - " << i.second << endl;
    }
}

string minWindow(string s, string t)
{
    string ans;
    int n = t.length(), m = s.length(), low = 0, high = 0;
    vector<int> track(128, 0);
    map<int, int> tMpp, sMpp;
    for (int i = 0; i < n; i++)
    {
        tMpp[t[i]]++;
        track[t[i]] = 1;
    }

    printMap(tMpp);

    for (auto i : tMpp)
    {
        int temp = i.first;
        char c = temp;
        cout << c << endl;
        while (tMpp[temp] > sMpp[temp])
        {
            if (track[temp] == 1)
            {
                sMpp[temp]++;
            }
            high++;
        }
    }
    // first string - longest answer!
    ans = s.substr(low, high - low + 1);
    cout << "Ans:  " << ans << "  " << high << endl;

    if ((high == m) && (sMpp != tMpp))
    {
        // cout<<"Returning : Empty!"<<endl;
        return "";
    }
    cout << "Came here : " << low << "  " << high << "  " << m << endl;
    while (high < m)
    {
        cout << "Came inside while: " << low << "  " << high << endl;
        int temp = s[low];
        if (track[temp] != 1)
        {
            low++;
            continue;
        }
        sMpp[temp]--;
        if (sMpp[temp] < tMpp[temp])
        {
            cout << "Came inside if: " << low << "  " << high << endl;
            sMpp[temp]++;
            high++;
            sMpp[s[high]]++;
        }
        else
        {
            cout << "Came inside else: " << low << "  " << high << endl;
            while (low <= high)
            {
                int temp = s[low];
                if (track[temp] != 1)
                {
                    low++;
                    continue;
                }
                if ((sMpp[temp] - 1) > tMpp[temp])
                {
                    sMpp[temp] -= 1;
                    low++;
                }
                else
                {
                    break;
                }
            }
            if (ans.length() > (high - low + 1))
            {
                ans = s.substr(low, (high - low + 1));
            }
        }
    }

    return ans;
}

int main()
{
    string s, t, ans;
    // s = "ADOBECODEBANC";
    s = "acccbobaoeaabbcc";
    t = "abbc";
    ans = minWindow(s, t);
    cout << "Final :  " << ans << endl;
}