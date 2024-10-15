#include <bits/stdc++.h>

using namespace std;

vector<long long int> twoOddNum(long long int arr[], long long int n)
{
    // code here
    // vector<long long int> ans; 
    int val1 = arr[0], val2 = arr[0];
    int i = 1;
    for (; i < n; i++)
    {
        // cout << "1. Went on till:  " << arr[i] << endl;
        val1 = val1 ^ arr[i];
    }
    // cout<<"1. Ans Went on till:  "<<arr[i]<<endl;
    i = 1;
    for (; i < n - 1; i++)
    {
        // cout << "2. Went on till:  " << arr[i] << endl;
        val2 = val2 ^ arr[i];
    }
    // cout << "2. Ans Went on till:  " << arr[i] << endl;
    // cout<<val1<<"     "<<val2<<endl;
    if(val1 > val2)
    {
        swap(val1,val2);
    }
    val1 = val2-val1;
    vector<long long int> ans = {val2,val1};
    return ans;
}

int main()
{
    long long int arr[] = {4,2,4,5,2,3,3,1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<n<<endl;
    twoOddNum(arr,n);
    return 1;
}