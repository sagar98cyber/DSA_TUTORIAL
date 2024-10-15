#include <bits/stdc++.h>
#include <string>
using namespace std;

string oddEven(int n)
{
    // code here

    if ((n & 1) == 1)
    {
        return "odd";
    }
    return "even";
}

int main()
{
    cout<<oddEven(15)<<endl;
}











////////////////////////////////////////////////  EVERYTHING BELOW IS JUST A BRUTE FORCE SOLUTION

// string convertBinary(int n)
// {
//     string res;
//     while (n != 1)
//     {
//         if ((n % 2) == 1)
//         {
//             res = res + '1';
//         }
//         else
//         {
//             res = res + '0';
//         }
//         n = n / 2;
//     }
//     res += '1';
//     string s = res;
//     reverse(s.begin(), s.end());
//     cout << s << endl;
//     int diff = 0;
//     if (res.length() != 32)
//     {
//         diff = 32 - res.length();
//         for (int i = 0; i < diff; i++)
//         {
//             res = res + '0';
//         }
//     }
//     return res;
// }

// string oddEven(int n)
// {
//     // code here
//     string res = convertBinary(n);
//     if(res[0] == '0')
//     {
//         return "even";
//     }
//     return "odd";
// }


// int main()
// {
//     // string res = oddEven(44);
//     // string res = oddEven(15);
//     string res = oddEven(1);
//     cout<<res<<endl;
// }