#include <bits/stdc++.h>

using namespace std;

void getSum(int sum, int arr[], int n, vector<vector<int>> &a, vector<int> &val, int cur, int flag)
{
    if (sum == cur)
    {
        a.push_back(val);
        // return;
    }
    if (n == flag)
    {
        return;
    }
    for (int i = flag; i < n; i++)
    {
        cur += arr[i];
        val.push_back(arr[i]);
        getSum(sum, arr, n, a, val, cur, i + 1);
        val.pop_back();
        cur -= arr[i];
    }
}

int perfectSum(int arr[], int n, int sum)
{
    // Your code goes here
    vector<vector<int>> a;
    vector<int> val;
    getSum(sum, arr, n, a, val, 0, 0);
    for (auto i : a)
    {
        for (auto j : i)
        {
            cout << j << ", ";
        }
        cout << endl;
    }
    return a.size();
}

int main()
{
    // int arr[] = {2, 5, 1, 4, 3};
    // int arr[] = {5, 2, 3, 10, 6, 8};
    // int arr[] = {1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    return perfectSum(arr, n, 10);
}