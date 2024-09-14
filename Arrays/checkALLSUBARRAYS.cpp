// CODING NINJAS PROBLEM NAME: 
// Subarrays with Sum ‘k'


#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> ans;

void printDS(vector<int> a)
{
    cout << "Printing DS: " << endl;
    for (auto i : a)
    {
        cout << i << endl;
    }
}

vector<vector<int>> subarraysWithSumK(vector<int> a, long long k)
{
    int low = 0, high = low, n = a.size();

    long long sum = a[high];

    while (low < n && high < n)
    {
        if (k == sum)
        {
            cout << "K and sum is equal: " << low << "  " << high << endl;
            vector<int> temp;
            int i = low;
            while (i <= high)
            {
                temp.push_back(a[i]);
                i++;
            }
            printDS(temp);
            ans.push_back(temp);
            low = low+1;
            high = low;
            sum = a[low];
            continue;
        }
        else if (sum < k)
        {
            ++high;
            sum += a[high];
            cout << "incrementing HIGH: " << high << "  " << sum << endl;
            continue;
        }
        else if (sum > k)
        {
            sum -= a[low];
            ++low;
            cout << "incrementing LOW: " << low << "  " << sum << endl;
            continue;
        }
    }
    return ans;
}

int main()
{
    // vector<int> a = {1, 2, 1, 1, 1}, d;
    // vector<int> a = {1, 2, 3, 1, 1, 1};
    vector<int> a = { 1, 2, 1, 3};

    long long d = 2;
    subarraysWithSumK(a, d);
    cout<<"Ans size: "<<ans.size()<<endl;
}