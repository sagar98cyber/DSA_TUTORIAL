#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n)
{
    bool ans = false;
    int c = 0;

    for (int i = 1; i <= sqrt(n); i++)
    {
        if ((n % i) == 0)
        {
            c += 1;
            int x = n / i;
            if (x != i)
            {
                c += 1;
            }
        }
    }

    if (c == 2)
    {
        cout << n << " is Prime!" << endl;
        return true;
    }
    // cout << n << " is not Prime!" << endl;
    return false;
}

int countPrimes(int n)
{
    vector<int> a(n + 1, 1);
    int ans = 0;

    // for (int i = 2; i <= n; i++)
    // {
    //     cout << "Initialize:  " << i << "  " << a[i] << endl;
    // }

    for (int i = 2; i <= n; i++)
    {
        bool res = isPrime(i);
        // cout << "Res:  " << i << "   " << res << endl;
        if ((a[i] == 1) && (res))
        {
            // a[i] = 0;
            int j = i * i;
            while (j <= n)
            {
                a[j] = 0;

                j += i;
            }
        }
    }

    for (int i = 2; i <= n; i++)
    {
        if (a[i] == 1)
        {
            // cout << "Final:  " << i << "  " << a[i] << endl;
            ans += 1;
        }
    }
    return ans;
}

int main()
{
    int a = countPrimes(10);
    cout << "Ans:  " << a << endl;
}