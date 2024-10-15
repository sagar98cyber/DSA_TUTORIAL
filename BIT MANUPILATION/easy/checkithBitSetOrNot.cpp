#include <bits/stdc++.h>
#include <string>
using namespace std;

bool checkKthBit(int n, int k)
{
    
    if(n&(1<<k))
    {
        return true;
    }
    return false;
}

int main()
{
    // int n=4, k=0;
    int n=4, k=2;
    if(checkKthBit(n,k))
    {
        cout<<"It is Set!";
    }
    else{
        cout << "It is not Set!";
    }
    return 1;
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

// // Function to check if Kth bit is set or not.
// bool checkKthBit(int n, int k)
// {

//     string res = convertBinary(n);
//     if (res[k] == '1')
//     {
//         return true;
//     }
//     return false;
// }

// int main()
// {
//     bool res = checkKthBit(10, 3);
//     if (res)
//     {
//         cout << "True!  " << endl;
//     }
//     else
//     {
//         cout << "True!  " << endl;
//     }
//     return 1;
// }