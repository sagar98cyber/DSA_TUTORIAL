#include <bits/stdc++.h>

using namespace std;

string getTheString(int n)
{
    string s = "";
    int j = 0, i = 0;
    while (j != n)
    {
        if ((1 << i) & n)
        {
            j += (1 << i);
        }
        s += '1';
        i++;
    }
    cout << j << " " << s << endl;
    return s;
}

int getInt(string s)
{
    int n = s.length(), j = 0;
    for (int i = 0; i < n; i++)
    {
        j += (1 << i);
    }
    return j;
}

int main()
{
    string s;
    int j;
    // s = getTheString(3);
    s = getTheString(10);
    // s = getTheString(5);
    j = getInt(s);
    cout << "Final:   " << j << " " << s << endl;
    return 1;
}