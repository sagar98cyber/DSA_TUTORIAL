#include <bits/stdc++.h>
#include <cmath>
using namespace std;


int func(int mid, int n, int m)
{
    long long ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans = ans * mid;
        
        if (ans > m)
            return 2;
    }
    // cout << "Ans:  " << ans << endl;
    if (ans == m)
        return 1;
    return 0;
}

int NthRoot(int n, int m)
{
    // Use Binary search on the answer space:
    int low = 1, high = m;
    // cout << "N:  " << n << "  M:  " << m << endl;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int midN = func(mid, n, m);
        // cout << "N:  " << n << "  Mid:  " << mid << "   Val: " << midN << endl;
        if (midN == 1)
        {
            return mid;
        }
        else if (midN == 0)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main()
{
    int n = 9, m = 1953125;
    cout<<endl<<endl<<"Final Response:  "<<NthRoot(n,m)<<endl<<endl;
}