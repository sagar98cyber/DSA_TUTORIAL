#include <bits/stdc++.h>

using namespace std;

void sieve1(vector<int> &prime, int n)
{

    // prime no. generation using sieve of eratothons

    prime[0] = false;
    prime[1] = false;
    for (int i = 2; i * i <= n; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                prime[j] = false;
            }
        }
    }
    // counting prime numbers
    // 		int primeCount = 0;
    // 		for (int i = 2; i < n; i++) {
    // 			if (prime[i]) {
    // 				primeCount++;
    // 			}
    // 		}
    // 		return primeCount;
}

vector<int> findPrimeFactors(int N)
{

    int n = N;
    vector<int> aa(n + 1, 1), ans;
    sieve1(aa, N);

    for (int i = 2; ((i <= N) && (n != 1)); i++)
    {
        if ((aa[i] == 1) && ((n % i) == 0))
        {
            while (((n % i) == 0) && (n != 1))
            {
                n = n / i;
                ans.push_back(i);
                // cout << "Dividing by: " << i << "    Value left is: " << n << endl;
            }
        }
    }
    // cout << endl
    //      << endl
    //      << endl
    //      << endl;
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     cout << ans[i] << "*";
    // }
    return ans;
}
int main()
{
    vector<int> a = findPrimeFactors(780);
    cout << "Ans:  " << endl;
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << "*";
    }
    return 1;
}