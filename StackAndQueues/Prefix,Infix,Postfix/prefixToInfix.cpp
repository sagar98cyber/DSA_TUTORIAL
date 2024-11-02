#include <bits/stdc++.h>

using namespace std;

string prefixToInfix(string s)
{
    // reverse(s.begin(), s.end());
    int n = s.length();
    // Write your code here
    if (s.length() == 0)
    {
        return s;
    }
    stack<string> st;
    string ans;

    for (int i = (n - 1); i >= 0; i--)
    {
        if ((s[i] != '^') && (s[i] != '*') && (s[i] != '/') && (s[i] != '+') && (s[i] != '-'))
        {
            string t;
            t.push_back(s[i]);
            st.push(t);
        }
        else
        {
            string a = st.top();
            st.pop();
            string b = st.top();
            st.pop();
            st.push('(' + a + s[i] + b + ')');
        }
    }
    cout << st.top() << endl;
    return st.top();
}

int main()
{
    string s = "*-A/BC-/AKL";
    // cout<<s<<endl;
    string ans = prefixToInfix(s);
    return 1;
}