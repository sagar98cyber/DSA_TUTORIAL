#include <bits/stdc++.h>

using namespace std;

int minCoinsNeeded(vector<int> coins, int sum)
{
    int target = 0;
    int count = 0;
    sort(coins.begin(), coins.end());
    int n = coins.size(), i = n - 1;
    while (i >= 0)
    {
        if ((sum - target) >= coins[i])
        {
            target += coins[i];
            count++;
        }
        else
        {
            i--;
        }
    }
    if (target != sum)
    {
        return -1;
    }
    return count;
}

int main()
{
    vector<int> coins = {4, 6, 2};
    int sum = 5;
    coins = {25,
             10,
             5};
    sum = 30;
    coins = {9, 6, 5, 1};
    sum = 19;
    coins = {5, 1};
    sum = 0;
    int ans = minCoinsNeeded(coins, sum);
    cout << "Final ans: " << ans << endl;
    return 0;
}