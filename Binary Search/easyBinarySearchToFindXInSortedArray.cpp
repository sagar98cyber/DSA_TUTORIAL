#include <bits/stdc++.h>

using namespace std;

int BinarySearch(vector<int> &nums, int target, int low, int high)
{

    while (low <= high)
    {
        int mid = low + ((high - low) / 2);

        if (target == nums[mid])
        {
            return mid;
        }
        else if (target < nums[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return -1;
}

int search(vector<int> &nums, int target)
{
    int max = nums.size();
    // cout<<"Max Length: "<<max<<endl;

    if (max < 1)
    {
        return -1;
    }
    if (max == 1)
    {
        if (nums[0] == target)
        {
            return 0;
        }
        else
        {
            return -1;
        }
    }

    return BinarySearch(nums, target, 0, max);
}