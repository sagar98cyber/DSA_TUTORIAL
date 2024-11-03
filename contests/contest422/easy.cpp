#include <bits/stdc++.h>

using namespace std;

bool isBalanced(string num)
{
    int len = num.length(), odd = 0, even = 0, e = (len % 2);
    // cout << len << "   " << e << endl;
    if ((len % 2) != 0)
    {
        num += '0';
        cout << num << endl;
        len = num.length();
    }

    int i = 1;
    for (; i < len; i += 2)
    {
        odd += num[i - 1];
        // cout << "Odd:  " << num[i - 1] << "   Even: " << num[i] << endl;
        even += num[i];
    }

    // bool t = odd == even;
    // cout << "Value is: " << t << endl;
    return odd == even;
}

int main()
{
    isBalanced("24123");
    return 1;
}