#include <bits/stdc++.h>

using namespace std;

bool checkPalindromeIfTrue(char a, char b)
{
    if (a == b)
    {
        return true;
    }
    return false;
}

bool checkWhiteList(char x, int &position, bool high)
{
    // cout << "Character being checked: " << x << endl;

    if ((x >= 97 && x <= 122) || (x >= 48 && x <= 57) ||
        (x >= 65 && x <= 90) )
    {
        return true;
    }
    high ? --position : ++position;
    cout << "Character being skipped: "
         << "\"" << x << "\"" << endl;
    cout<<"POstion: " << position<<endl;
    return false;
}

bool checkPalindrome(string s)
{
    // Write your code here.
    int len = s.size();
    cout<<"Length: "<<len<<endl;
    int low = 0, high = len - 1;
    bool palindromeFlag = true;
    while (low <= high && palindromeFlag == true)
    {
        char strA = tolower(s[low]);
        char strB = tolower(s[high]);

        bool testA = checkWhiteList(strA, low,false);
        while (testA != true)
        {
            strA = tolower(s[low]);
            testA = checkWhiteList(strA, low,false);
        }

        // cout << "Checking low: --" << testA << "---" << strA << "---" << low << endl;

        bool testB = checkWhiteList(strB, high,true);
        while (testB != true)
        {
            strB = tolower(s[high]);
            testB = checkWhiteList(strB, high,true);
        }

        // cout << "Checking high: --" << testB << "---" << strB << "---" << high << endl;

        if (testA && testB)
        {
            cout << "Checking characters: --" << strA << "---" << strB << "---" << low << "---" << high << endl;
            palindromeFlag = checkPalindromeIfTrue(strA, strB);
            low++;
            high--;
        }
    }
    // return palindromeFlag;
    string dd = palindromeFlag ? " True" : " False";
     cout << "Palidrome is:" << dd<< endl;
}

/*
c1 O$d@eeD o1c
N2 i&nJA?a& jnI2n
A1b22Ba
codingninjassajNiNgNidoc
5?36@6?35
aaBBa@
*/

int main(){
     string checkStr = "c1 O$d @eeD o1c"; //"aaBBa@"; //"c1 O$d@eeD o1c";  //"5?36@6?35"; //"codingninjassajNiNgNidoc"; //"A1b22Ba"; //"N2 i&nJA?a& jnI2n";
                           cout
                       << "Main string: " << checkStr << endl;
     checkPalindrome(checkStr);
        // char s = 50;
        // cout<<"Char: "<<s<<endl;
     return 0;
}