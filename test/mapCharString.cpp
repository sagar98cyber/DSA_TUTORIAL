#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<char,string> mpp;

    mpp.insert({'2', "abc"});
    mpp.insert({'3', "def"});
    mpp.insert({'4', "ghi"});
    mpp.insert({'5', "jkl"});
    mpp.insert({'6', "mno"});
    mpp.insert({'7', "pqrs"});
    mpp.insert({'8', "tuv"});
    mpp.insert({'9', "wxyz"});

    string a = "charac";
    char x = '4';
    int i = 1; 
    cout << "Well well well:  " << mpp[x][i] << endl;
    string b = a+mpp[x][i];
    cout << "Well:  " << b << endl;

    return 0;
}