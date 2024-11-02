#include <bits/stdc++.h>

using namespace std;

long long mo = 1000000007;

int lengthAfterTransformations(string s, int t)
{
    vector<long long> c(26, 0), n(26, 0);

    // string d = s;

    for (int i = 0; i < s.length(); i++)
    {
        c[s[i] - 'a']++;
        // cout << 'a' + i << "  " << (s[i] - 'a') << "   " << c[s[i] - 'a'] << endl;
    }
    // n = c;
    for (int j = 0; j < t; j++)
    {
        // cout << "Before transformation " << j << endl;
        // for (int i = 0; i < 26; i++)
        // {
        //     char a = 'a' + i;
        //     cout << a << "   " << c[i] << "  " << n[i] << endl;
        // }
        for (int i = 0; i < 26; i++)
        {
            if (i == 0)
            {
                n[0] = 0;
                n[1] = c[0];
                continue;
            }
            if (i != 25)
            {
                n[i + 1] = c[i];

                // char z = 'a' + i + 1;
                // cout << "Making " << z << c[i] << endl;
            }
            else
            {
                // cout << "Came in else for: " << i << "   " << c[i] << endl;
                n[0] = (c[25] + n[0]);
                n[1] = (c[25] + n[1]);
            }
        }

        cout << "After transformation " << j << endl;
        for (int i = 0; i < 26; i++)
        {
            char a = 'a' + i;
            cout << a << "   " << c[i] << "  " << n[i] << endl;
        }
        c = n;
    }
    int ans = 0;
    for (int i = 0; i < 26; i++)
    {
        ans += c[i];
        ans = (ans % mo);
    }
    // cout << "ANS:" << ans << endl;
    return ans % mo;
}

int main()
{
    // string s = "abcyy";
    // int t = 2;
    string s = "azbk";
    int t = 1;
    // s = "k";
    // t = 10;
    s = "v";
    t = 7;
    // string s = "jqktcurgdvlibczdsvnsg";
    // int t = 7517;

    int ans = lengthAfterTransformations(s, t);
    cout << endl
         << endl
         << endl
         << ans << endl;
}