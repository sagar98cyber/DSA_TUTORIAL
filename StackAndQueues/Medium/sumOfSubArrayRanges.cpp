#include <bits/stdc++.h>

using namespace std;

long long subArrayRanges(vector<int> &nums)
{
    int n = nums.size();
    long long ans = 0;
    for (int i = 0; i < (n - 2); i++)
    {
        int low = nums[i], high = nums[i + 1];
        int j = i + 1;
        if (low > high)
        {
            swap(low, high);
        }
        while (j < n)
        {
            if (nums[j] > nums[high])
            {
                high = nums[j];
            }
            else if (nums[j] < nums[low])
            {
                low = nums[j];
            }
            ans += (high - low);
            j++;
        }
    }
    return ans;
}

int main()
{
    vector<int> sm = {20, 1, 0, 5, 4, 3, 2, 1, 0};
    int n = sm.size();
    // vector<int> la;

    // for (i = sm.size() - 1; i >= 0; i--)
    // {
    //     la.push_back(sm[i]);
    // }

    int largest = 0;
    int smallest = 0;
    for (int i = 0; i < n; i++)
    {
        smallest += (sm[i] * (i + 1));
        largest += ((sm[n - 1 - i]) * (i + 1));
        // cout << sm[n - 1 - i] << endl;
    }
    cout << largest << "   " << smallest << endl;
    return 1;
}