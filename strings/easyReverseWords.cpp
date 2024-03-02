#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s)
{
    int i = 0, j = 0;
    string result;
    int n = s.length();
    cout << "N:  " << n << "  s[n-1]: " << s[n - 1] << "  s[n]: " << s[n] <<endl<<endl<< endl;
    while (j < n)
    {
        while (i < n && s[i] == ' ')
        {
            i++;
        }
        if (i >= n)
            break;
        j = i + 1;
        while (j < n && s[j] != ' ')  
        {
            j++;
        }
        string sub = s.substr(i, j - i);                       //  "  hello world   "
        cout<<"SUBSTRING:  "<<sub<<endl;
        if (result.length() == 0)
            result = sub;
        else
            result = sub + ' ' + result;
        i = j + 1;
        cout<<"I:  "<<i<<"  J: "<<j<<endl;
    }
    return result;
}

int main()
{
    cout << endl << endl << endl << "Final:  " << reverseWords("  hello world  ");
}


