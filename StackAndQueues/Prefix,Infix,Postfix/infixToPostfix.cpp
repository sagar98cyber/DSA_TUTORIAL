#include <bits/stdc++.h>

using namespace std;

int getVal(char c)
{
    switch (c)
    {
    case '^':
        return 3;
    case '*':
        return 2;
    case '/':
        return 2;
    case '+':
        return 1;
    case '-':
        return 1;
    default:
        return 0;
    }
}

string infixToPostfix(string s)
{
    // Your code here
    if (s.length() == 0)
    {
        return s;
    }
    stack<char> st;
    string ans;

    for (int i = 0; i < s.length(); i++)
    {
        // cout << "1.  " << s[i] << "   " << endl;
        if (!st.empty())
        {
            // cout << "2.  " << st.top() << "   " << endl;
        }
        if ((s[i] != '^') && (s[i] != '*') && (s[i] != '/') && (s[i] != '+') && (s[i] != '-') && (s[i] != '(') && (s[i] != ')'))
        {
            // cout << "Inside IF!" << endl;
            ans += s[i];
            continue;
        }
        else
        {
            // cout << "Inside ELSE!" << endl;
            if (s[i] == '(')
            {
                // cout << "Inside '('" << endl;
                st.push('(');
                continue;
            }
            else if (s[i] == ')')
            {
                // cout << "Inside ')'" << endl;
                while (st.top() != '(')
                {
                    ans += st.top();
                    st.pop();
                }
                st.pop();
                continue;
            }
            else
            {
                // cout << "Inside ELSE2!" << endl;
                if (st.empty())
                {
                    st.push(s[i]);
                    continue;
                }
                int a = getVal(st.top()), b = getVal(s[i]);
                // cout << "a: " << a << "  st.top(): " << st.top() << "  b: " << b << "   s[i]:  " << s[i] << "  i: " << i << endl;
                if (b > a)
                {
                    // cout << "b>a" << endl;
                    st.push(s[i]);
                    continue;
                }
                else
                {
                    // cout << "b<a" << endl;
                    a = getVal(st.top());
                    while (a >= b && !st.empty())
                    {
                        // cout << "INside while:  " << a << "  " << b << endl;
                        if ((st.top() != '(') && (st.top() != ')'))
                        {
                            ans += st.top();
                        }
                        st.pop();
                        if (!st.empty())
                        {
                            a = getVal(st.top());
                        }
                        // cout << "INside while block end:  " << a << "  " << b << endl;
                    }
                    // cout << "While loop ended!   " << st.top() << endl;
                    st.push(s[i]);
                }
            }
        }
    }

    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    // cout << ans << endl;
    return ans;
}

int main()
{
    string s = "a^b*(c^d-e)^(f+g*h)-i";
    // s = "a+b*(c^d-e)^(f+g*h)-i";
    s = "A*(B+C)/D";
    string ans = infixToPostfix(s);
    cout << ans << endl;
    // int a = getVal('^');
    // int b = getVal('*');
    // int c = getVal('/');
    // int d = getVal('+');
    // int e = getVal('-');
    // cout << a << "  " << b << "  " << c << "  " << d << "  " << e << "  " << endl;
    return 1;
}