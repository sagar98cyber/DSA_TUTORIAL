#include <bits/stdc++.h>

using namespace std;

long long maximumSubarraySum(vector<int> &nums, int k)
{
    int n = nums.size();
    unordered_set<int> elements;
    long long current_sum = 0;
    long long max_sum = 0;
    int low = 0;

    for (int high = 0; high < n; high++)
    {
        if (elements.find(nums[high]) == elements.end())
        {
            cout << "Came inside if: " << low << "  " << high << endl;
            current_sum += nums[high];
            elements.insert(nums[high]);

            if (high - low + 1 == k)
            {
                cout << "Came to update MAX!" << endl;
                max_sum = max(max_sum, current_sum);
                current_sum -= nums[low];
                elements.erase(nums[low]);
                low++;
            }
        }
        else
        {
            cout << "Came inside else: " << low << "  " << high << endl;
            while (nums[low] != nums[high])
            {
                cout << "Inside while: " << low << "  " << high << endl;
                current_sum -= nums[low];
                elements.erase(nums[low]);
                low++;
            }
            low++;
        }
    }

    return max_sum;
}

int main()
{
    vector<int> nums = {1, 5, 4, 9, 3, 2, 9, 9, 6, 7, 8, 9};

    int i = 0;
    for (auto c : nums)
    {
        cout << c << ", ";
    }
    cout << endl;
    for (auto c : nums)
    {
        cout << i << "  ";
        i++;
    }
    cout << endl;
    maximumSubarraySum(nums, 5);
    return 1;
}