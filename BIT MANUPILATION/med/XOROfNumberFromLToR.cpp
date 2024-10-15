#include <bits/stdc++.h>

using namespace std;

bruteXOR(int n)
{
    int ans = 0;
    if ((n % 4) == 1)
    {
        ans = 1;
    }
    else if ((n % 4) == 2)
    {
        ans = n + 1;
    }
    else if ((n % 4) == 3)
    {
        ans = 0;
    }
    else
    {
        ans = n;
    }

    cout << "Answer is: " << ans << endl;
    return ans;
}

int main()
{
   
    // bruteXOR(0,20);
    // bruteXOR(4, 8);
    // int a1 = bruteXOR(94-1), a2 = bruteXOR(97);
    // // int a1 = bruteXOR(3), a2 = bruteXOR(8);
    // int ans = a1 ^ a2;
    // cout << ans;

    // int a = 1 ^7 ^5 ^7 ^5 ^4 ^7 ^4;
    int a = 4^ 2^ 4^ 5^ 2^ 3^ 3^ 1;
    cout << a;
    return 1;
}