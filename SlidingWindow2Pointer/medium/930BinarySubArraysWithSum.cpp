#include <bits/stdc++.h>

using namespace std;

int numSubarraysWithSum(vector<int> &nums, int goal)
{
    int low = 0, high = 0, sum = nums[high], n = nums.size(), count = 0;

    while (high < n)
    {

        cout << "INdexes:  Low:  " << low << "  High:  " << high << "   Sum: " << sum << "   Goal:  " << goal << "   Count: " << count << endl;
        if (sum == goal)
        {
            cout << "Increasing count! " << endl;
            count++;
            if (nums[low] == 0)
            {
                low++;
                continue;
            }
        }
        else if (sum < goal)
        {
        }
        else
        {
            while ((low <= high) && (sum > goal))
            {
                sum -= nums[low];
                low++;
            }
            if (low > high)
            {
                high = low;
            }
            continue;
        }

        high++;
        if (high != n)
        {
            sum += nums[high];
        }
    }

    if (sum == 0 && low == 0 && high == n)
    {
        cout << "came inside the edge case" << endl;
        if (goal != 0)
            return 0;

        int ans = 0, temp = 0;
        for (int i = 1; i <= n; i++)
        {
            temp = n - (i - 1);
            ans += temp;
        }
        return ans;
    }

    while ((low < high) && (sum >= goal))
    {
        cout << "Inside While - Indexes:  Low:  " << low << "  High:  " << high << "   Sum: " << sum << "   Goal:  " << goal << "   Count: " << count << endl;
        sum -= nums[low];
        low++;
        if (sum == goal)
        {
            count++;
        }
    }

    return count;
}

int main()
{
    vector<int> nums;
    int goal;
    // nums = {1, 0, 1, 0, 1};
    // goal = 2;

    // nums = {1, 1, 1, 0, 0, 1, 0, 1, 1, 1, 0};
    // goal = 3;

    nums = {0,
            0,
            0,
            0,
            0};
    goal = 0;

    for (auto i : nums)
    {
        cout << i << "  ";
    }
    cout << endl;
    int t = 0;
    for (auto i : nums)
    {
        cout << t << "  ";
        t++;
    }
    cout << endl
         << endl;
    int ans = numSubarraysWithSum(nums, goal);
    cout << "Ans: " << ans << endl;
    return 1;
}