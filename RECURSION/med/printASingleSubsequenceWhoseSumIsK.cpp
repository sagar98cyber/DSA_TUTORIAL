#include <bits/stdc++.h>

using namespace std;

bool found = false;

void getSum(int sum, int arr[], int n, vector<int> &a, vector<int> &ans, int cur, int flag)
{
    // cout << "Called at index: " << flag << endl;

    if (found == true)
    {
        // cout << "Returning as found is true! " << endl;
        return;
    }
    if (sum == cur)
    {
        ans = a;
        found = true;
        // cout << "Returning as found first! " << endl;
        return;
    }
    if (n == flag)
    {
        // cout << "Returning as n is flag " << endl;
        return;
    }
    for (int i = flag; i < n; i++)
    {
        if (found == false)
        {
            cur += arr[i];
            a.push_back(arr[i]);
            // cout << "Just added:  " << arr[i] << "  Sum:  " << cur << endl;
            if (cur <= sum)
            {
                getSum(sum, arr, n, a, ans, cur, i + 1);
            }
            a.pop_back();
            cur -= arr[i];
            // cout << "Just removed:  " << arr[i] << "  Sum:  " << cur << endl;
        }
    }
}

int perfectSum(int arr[], int n, int sum)
{
    // Your code goes here
    int a = 0;
    vector<int> val, ans;
    getSum(sum, arr, n, val, ans, 0, 0);
    for (auto i : ans)
    {
        cout << i << ", " << endl;
    }
    // cout << "Val of A: " << a << endl;
    return a;
}

int main()
{
    // int arr[] = {5, 2, 3, 10, 6, 8};
    int arr[] = {2, 5, 1, 4, 3};
    // int arr[] = {1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    return perfectSum(arr, n, 10);
}