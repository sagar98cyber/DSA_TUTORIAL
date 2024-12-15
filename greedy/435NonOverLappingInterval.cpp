#include <bits/stdc++.h>

using namespace std;

// struct Inter
// {
//     int s;
//     int e;
// };

bool compA(vector<int> &a, vector<int> &b)
{
    return a[1] < b[1];
}

int eraseOverlapInterval(vector<vector<int>> &intervals)
{
    int count = 1, n = intervals.size();

    sort(intervals.begin(), intervals.end(), compA);

    // for (int i = 0; i < n; i++)
    // {
    //     cout << i << " " << intervals[i][0] << " " << intervals[i][1] << endl;
    // }
    int lastEndTime = intervals[0][1];
    for (int i = 1; i < n; i++)
    {
        int s = intervals[i][0], e = intervals[i][1];
        if (s >= lastEndTime)
        {
            // cout << "Incrementing for : " << i << endl;
            count++;
            lastEndTime = e;
        }
    }
    // cout << n << " " << count << endl;
    return (n - count);
}

int main()
{
    vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    // intervals = {{1, 100}, {11, 22}, {1, 11}, {2, 12}};
    // intervals = {{1, 2}, {2, 3}};
    // intervals = {{1, 2}, {1, 2}, {1, 2}};
    int ans = eraseOverlapInterval(intervals);
    cout << "Final: " << ans << endl;
    return 0;
}