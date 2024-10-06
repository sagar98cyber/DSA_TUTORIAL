#include <bits/stdc++.h>

using namespace std;

void setBit(string& s, int i)
{
    if (s[i] == '1')
    {
        cout<< "INSIDE IF!"<<endl;
        s[i] = '0';
    }
    else
    {
        cout << "INSIDE ELSE!" << endl;
        s[i] = '1';
    }
    // cout<<s<<endl;
    // return s;
}

int main()
{
    int i = 2;
    string res = "101010101";
    // res = 
    setBit(res, i);
    cout << res;
    return 0;
}