#include <bits/stdc++.h>
using namespace std;

int minimumSumSubarray(vector<int> &nums, int l, int r)
{
    int low = 0, high = 0, n = nums.size();
    int sum = 0, ans = -1;
    while (high < l)
    {
        sum += nums[high];
        high++;
    }
    if (sum > 0)
    {
        ans = sum;
    }
    cout << "First ans: " << ans << " " << low << " " << high << endl;

    while (high < n)
    {
        sum += (nums[high]);
        sum += (nums[low]) * (-1);
        if (sum > 0)
        {
            ans = min(ans, sum);
        }
        cout << sum << " " << ans << " Low: " << low << " High: " << high << endl;
        low++;
        high++;
    }
    return ans;
}

int main()
{
    vector<int> t = {-2, 2, -3, 1};
    for (int i = 0; i < t.size(); i++)
    {
        cout << t[i] << ", ";
    }
    cout << endl;
    for (int i = 0; i < t.size(); i++)
    {
        cout << i << ", ";
    }
    cout << endl
         << endl;
    int l = 2, ans = minimumSumSubarray(t, l, l);
    cout << ans << endl;
    return 0;
}