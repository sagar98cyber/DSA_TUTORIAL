#include <bits/stdc++.h>

using namespace std;

void print_divisors(int n)
{
    // Code here.
    vector<int> ans;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            cout << i << " ";
        }
        int x = n / i;
        if (x != i)
        {
            if (n % x == 0)
            {
                ans.push_back(x);
            }
            // cout << "Adding to the vector:  " << x << " " << endl;
        }
    }
    // cout << "Finally:  " << endl;
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        cout << ans[i] << " ";
    }
}

int main()
{
    // print_divisors(20);
    print_divisors(2);
    return 1;
}