#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {3, -2, 1, 4};
    int sum = 6;
    for (auto &i : nums)
    {
        sum += (i * -1);
        cout << sum << endl;
    }
    sum = 0;
    cout << endl
         << endl;
    for (auto &i : nums)
    {
        sum += (i);
        cout << sum << endl;
    }
    // cout << sum << endl;
    return 0;
}

// 0 0 0
// 0 0 1
// 1 1 0

// 0 1
// 1 0

// 0 1
// 1 1

// key -> value
// 000 -> 1
// 001 -> 2
