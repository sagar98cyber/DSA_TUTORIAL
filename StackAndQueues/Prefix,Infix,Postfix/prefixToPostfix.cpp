#include <bits/stdc++.h>

using namespace std;

string prefixToPostfix(string s)
{
    if (s == "")
    {
        return s;
    }

    int n = s.length();

    stack<string> st;
    string ans;

    for (int i = n - 1; i >= 0; i--)
    {
        if ((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            string t;
            t += s[i];
            st.push(t);
        }
        else
        {
            string a = st.top();
            st.pop();
            string b = st.top();
            st.pop();
            st.push(a + b + s[i]);
        }
    }
    return st.top();
}

int main()
{
    string s = "*-A/BC-/AKL";
    // s = "*-A/BC-/AKL";
    // cout<<s<<endl;
    string ans = prefixToPostfix(s);
    cout << ans << endl;
    return 1;
}