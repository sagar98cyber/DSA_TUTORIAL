#include <bits/stdc++.h>

using namespace std;

string genBinStr(int l, string t)
{
    if(l == 0)
    {
        cout<<t<<endl;
        return t;
    }

    l--;

    string d = t;
    d.append("0");
    genBinStr(l, d);
    
    if(t.back() != '1')
    {
        string e = t;
        e.append("1");
        genBinStr(l, e);
    }
}

int main()
{
    int l = 3;
    genBinStr(l,"");
    // generateAllBinaryStrings(l); 
    return 0;
}