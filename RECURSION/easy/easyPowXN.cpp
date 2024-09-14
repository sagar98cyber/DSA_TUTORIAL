
#include <bits/stdc++.h>

using namespace std;

double powR(double x, long long n, double ans)
{
    if (n <= 0)
    {
        return ans;
    }
    if (n % 2 && n!=2)
    {
        cout << "n is: " << n << " so -1" << endl;
        --n;
        ans = ans * x;
        cout << "So now n is: " << n << "  ans is: " << ans << endl;
    }
    else
    {
        cout << "Entering while n is: " << n << endl;
        x = x * x;
        n = n / 2;
        cout << "So now n is: " << n << "  ans is: " << ans << endl;
    }
    return powR(x, n, ans);
}

double myPow(double x, int n)
{
    
    long long nn = n;
    if (nn < 0)
        nn = -1 * nn;
    double res = powR(x, nn, 1);

    if (n < 0)
    {
        return 1 / res;
    }
    return res;
}

int main()
{
    // double x = 2.00000;
    // int n = 10;
    // int n = -2;
    // double x = 1.00000;
    // int n = -2147483648;
    double x = 2.100000;
    int n = 3;
    cout<<myPow(x,n)<<endl;
}