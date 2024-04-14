#include <bits/stdc++.h>

using namespace std;

long long MOD = 1000000007;

long long power(long long N, long long R)
{
    if (R == 0)
        return 1;

    if (R == 1)
        return (N % MOD);

    long long ans = 1;
    long long know = power(N, R / 2) % MOD;

    if (R % 2)
        ans = (ans * N) % MOD;

    return (ans * ((know * know) % MOD)) % MOD;
}

int countGoodNumbers(long long n)
{
    long long ans = power(20, n / 2);
    if (n % 2)
        ans = (ans * 5) % MOD;

    return ans;
}

int main()
{
    int n = 4;
    cout<<countGoodNumbers(n);
}