#include <bits/stdc++.h>

using namespace std;

void genPalPar(int index, string s, vector<string> &path, vector<vector<string>> &res)
{
    if (index == s.size())
    {
        res.push_back(path);
        return;
    }
    for (int i = index; i < s.size(); ++i)
    {
        if (checkPalin(s, index, i))
        {
            path.push_back(s.substr(index, i - index + 1));
            genPalPar(index + 1, s, path, a);
            path.pop_back();
        }
    }
}
