#include <bits/stdc++.h>
using namespace std;

void reverseString(string s)
{
    // Write your code here
    int len = s.length() - 1;
    for (int i = 0; i < len/2-1; i++)
    {
        swap(s[i], s[len - i]);
    }
    cout<<s<<endl;
}

int main()
{
    string s  = "Hello World!";
    reverseString(s);
    return 0;
}