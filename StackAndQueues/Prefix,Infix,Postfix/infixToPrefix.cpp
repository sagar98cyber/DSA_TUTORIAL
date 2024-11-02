#include <bits/stdc++.h>

using namespace std;

int getVal(char c)
{

    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return 0;
}

string infixToPrefix(string s)
{
    int n = s.length();
    if (s == "")
    {
        return s;
    }

    string ans;
    stack<char> st;

    for (int i = n - 1; i >= 0; i--)
    {
        // cout << "1.  " << i << "   " << s[i] << endl;
        if ((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            // cout << s[i] << endl;
            ans += s[i];
            // continue;
        }
        else
        {
            if (st.empty())
            {
                st.push(s[i]);
                // continue;
            }
            else if (s[i] == ')')
            {
                st.push(')');
                // continue;
            }
            else if (s[i] == '(')
            {
                // cout << "Came here 1   " << st.top() << "   " << getVal(st.top()) << s[i] << "   " << getVal(s[i]) << endl;
                while (!st.empty() && (st.top() != ')'))
                {
                    // cout << "Came here 3   " << st.top() << "   " << getVal(st.top()) << s[i] << "   " << getVal(s[i]) << endl;
                    ans += st.top();
                    st.pop();
                }
                st.pop();
                // continue;
            }
            else
            {
                // cout << "Came here 1 " << endl;
                if (st.top() == ')')
                {
                    st.push(s[i]);
                    continue;
                }
                else if (getVal(st.top()) >= getVal(s[i]))
                {
                    // cout << "Came here 2 " << endl;
                    while (!st.empty() && (getVal(st.top()) > getVal(s[i])))
                    {
                        // cout << "Came here 3   " << st.top() << "   " << getVal(st.top()) << s[i] << "   " << getVal(s[i]) << endl;
                        ans += st.top();
                        // if (!st.empty())
                        // {
                        st.pop();
                        // }
                        // cout << "came here 4 : " << ans << "  " << st.empty() << endl;
                    }
                    // cout << "came here 5 : " << ans << endl;
                    st.push(s[i]);
                }
                else if (getVal(st.top()) <= getVal(s[i]))
                {
                    st.push(s[i]);
                }
            }
        }
        // cout << "NExt Considering.  " << i - 1 << "   " << s[i - 1] << endl;
    }
    // cout << "DD  "; //<< ans << endl;
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    cout << ans << endl;
    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{
    string s = "a^b*(c^d-e)^(f+g*h)-i";
    // s = "a+b*(c^d-e)^(f+g*h)-i";
    // s = "A*(B+C)/D";
    // s = "(p+q)*(c-d)";
    string ans = infixToPrefix(s);
    cout << ans << endl;
    return 1;
}