#include <bits/stdc++.h>

using namespace std;

void printDS(vector<int> &a)
{
    cout << "New Ans: " << endl;
    for (auto i : a)
    {
        cout << i << endl;
    }
}

void solve(int limit, vector<int> &a, int sum, int i, int &count)
{
    if(sum>limit)
    {
        return;
    }
    if (i == a.size())
    {
        if (sum == limit)
        {
            // printDS(temp);
            count++;
        }
        return;
    }

    solve(limit, a, sum, i + 1, count);
    sum += a[i];
    solve(limit, a, sum, i + 1, count);
}

int main()
{
    // vector<int> a = {1, 2, 1, 1, 1}, d;
    vector<int> a = {1, 2, 3, 1, 1, 1}, d;
    // vector<int> a = {1, 0}, d;
    int sum = 3, count = 0;

    solve(sum, a, 0, 0, count);

    cout << "The number of sub-sequences with the sum K: " << count << endl;
}