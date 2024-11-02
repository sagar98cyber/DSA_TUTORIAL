#include <bits/stdc++.h>

using namespace std;

string postToInfix(string s)
{
    int n = s.length();
    // Write your code here
    if (s.length() == 0)
    {
        return s;
    }
    stack<string> st;
    string ans;

    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i] != '^') && (s[i] != '*') && (s[i] != '/') && (s[i] != '+') && (s[i] != '-'))
        {
            string t;
            t.push_back(s[i]);
            st.push(t);
        }
        else
        {
            string a = st.top(), temp;
            st.pop();
            string b = st.top();
            st.pop();
            st.push('(' + b + s[i] + a + ')');
        }
    }
    cout << st.top() << endl;
    return st.top();
}

int main()
{
    string s = "ab*c+";
    string ans = postToInfix(s);
    return 1;
}

