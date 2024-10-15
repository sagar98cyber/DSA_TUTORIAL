#include <bits/stdc++.h>

using namespace std;




int main()
{
    int n = 16;
    if(n<=0)
    {
        cout << "It is not a POWER OF 2!" << endl;
        return 0;
    }
    if ((n & n - 1) == 0)
    {
        cout<<"It is a POWER OF 2!"<<endl;
        return 1;
    }
    cout << "It is not a POWER OF 2!" << endl;
    return 0;
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
//     // if (res.length() != 32)
//     // {
//     //     diff = 32 - res.length();
//     //     for (int i = 0; i < diff; i++)
//     //     {
//     //         res = res + '0';
//     //     }
//     // }
//     return res;
// }

// bool isPowerOfTwo(int n)
// {
//     string res = convertBinary(n);
//     cout<<res<<endl;
//     int len = res.length()-1, i=0;
//     while(i<len)
//     {
//         cout<<"Checking at: "<<i<<"   Checking the value: "<<res[i]<<endl;
//         if(res[i] == '1')
//         {
//             return false;
//         }
//         i++;
//     }
//     return true;
// }

// int main()
// {
//     bool res = isPowerOfTwo(-2147483648);
//     if (res)
//     {
//         cout << "It is a power of 2!";
//         return 1;
//     }
//     cout << "It is not a power of 2!";
//     return 1;
// }



