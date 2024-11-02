#include <bits/stdc++.h>

using namespace std;

string postfixToPrefix(string s)
{
    if (s == "")
    {
        return s;
    }

    int n = s.length();

    stack<string> st;
    string ans;

    for (int i = 0; i < n; i++)
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
            st.push(s[i] + b + a);
        }
    }
    return st.top();
}

int main()
{
}