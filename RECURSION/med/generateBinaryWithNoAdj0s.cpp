#include <bits/stdc++.h>

using namespace std;

void genStr(vector<string> &a, int n, string g)
{
    if (n == 0)
    {
        a.push_back(g);
        return;
    }
    genStr(a, n - 1, g + '1');

    if (g[g.length() - 1] != '0')
    {
        genStr(a, n - 1, g + '0');
    }
}

vector<string> validStrings(int n)
{
    vector<string> a;
    genStr(a, n, "");
    return a;
}

int main()
{
    vector<string> a = validStrings(3);
    for (auto i : a)
    {
        cout << i << "    " << i.back() << endl;
    }
    return 0;
}