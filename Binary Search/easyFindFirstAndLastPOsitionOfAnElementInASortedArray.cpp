#include <bits/stdc++.h>

using namespace std;

int left(vector<int> &nums, int target)
{
    int low = 0, high = nums.size()-1;
    int ans = -1;
    while (low <= high)
    {
        int mid = low + ((high - low) / 2);

        if (nums[mid] >= target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int right(vector<int> &nums, int target)
{

    int low = 0, high = nums.size()-1;
    int ans = -1;
    while (low <= high)
    {
        int mid = low + ((high - low) / 2);

        if (nums[mid] > target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans-1;
}

vector<int> searchRange(vector<int> &nums, int target)
{
    vector<int> ans = {-1, -1};

    int temp = left(nums, target);
    ans[0]=temp;
    ans[1] = right(nums,target);
    for( int i=0; i<=1; i++)
    {
        cout<<"Value:  "<<ans[i]<<endl;
    }
}

int main()
{
    vector<int> test = {5,7,7,8,8,10};
    searchRange(test,8);
}