#include <bits/stdc++.h>

using namespace std;

void getSum(int sum, int arr[], int n, int &a, int cur, int flag)
{
    if (sum == cur)
    {
        a++;
    }
    if (n == flag)
    {
        return;
    }
    for (int i = flag; i < n; i++)
    {
        cur += arr[i];
        getSum(sum, arr, n, a, cur, i + 1);
        cur -= arr[i];
    }
}

int perfectSum(int arr[], int n, int sum)
{
    // Your code goes here
    int a = 0;
    vector<int> val;
    getSum(sum, arr, n, a, 0, 0);
    cout << "Val of A: " << a << endl;
    return a;
}

int main()
{
    // int arr[] = {5, 2, 3, 10, 6, 8};
    // int arr[] = {2, 5, 1, 4, 3};
    int arr[] = {1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    return perfectSum(arr, n, 1);
}