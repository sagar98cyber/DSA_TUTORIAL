#include <bits/stdc++.h>
using namespace std;


bool wordBreak(string s, vector<string> &wordDict)
{

    int f = 0;

    bool a = allWordsCovered(f, s, wordDict);

    if (!a)
    {
        return false;
    }
    if (f == s.length())
    {
        cout << "returning TRUE! - 2" << endl;
        return true;
    }

    return checkRemainingString(f, s, wordDict);
}

int main()
{
    // string s = "leetcode";
    // vector<string> a = {"leet", "code"};
    // string s = "applepenapple";
    // vector<string> a = {"apple", "pen"};
    // string s = "catsandog";
    // vector<string> a = {"cats", "dog", "sand", "and", "cat"};
    // string s = "applepenapplepepen";
    // vector<string> a = {"apple", "pen"};
    // string s = "applepenpenpenapplepen";
    // vector<string> a = {"apple", "pen"};
    string s = "bb";
    vector<string> a = {"a", "b", "bbb", "bbbb"};
    bool ans = wordBreak(s, a);
    string dd = ans ? "TRUE!" : "FALSE";
    cout << "Final Returning:  " << dd << endl;
    return 0;
}