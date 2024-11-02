#include <bits/stdc++.h>
#include <string.h>

using namespace std;

void getAllChars(char r, vector<string> &a)
{
    string start; 
    if (a.size() != 0)
    {
        int l = a.size() - 1;
        start = a[l];
    }
    char t = 'a';

    start += t;

    a.push_back(start);

    if (start.back() == r)
    {

        return;
    }

    while (t != r)
    {
        t++;
        start.back() = t;
        a.push_back(start);
    }
}

vector<string> stringSequence(string target)
{
    vector<string> ans;
    if (target == "")
    {
        return ans;
    }
    // ans.push_back();

    string start;
    if (target == start)
    {
        return ans;
    }

    int len = target.length();

    for (auto i : target)
    {
        getAllChars(i, ans);
    }
    return ans;
}

int main()
{
    // vector<string> ans = stringSequence("abc");
    vector<string> ans = stringSequence("he");
    for (auto i : ans)
    {
        cout << i << endl;
    }
    return 1;
}