#include <bits/stdc++.h>

using namespace std;

struct Time
{
    int start;
    int end;
};

bool comp(Time a, Time b)
{
    return a.start < b.start;
}

int findPlatform(vector<int> &arr, vector<int> &dep)
{
    // Your code here

    int ans = 1;
    int n = arr.size(), p1 = 1, prev = 0;
    Time p[n];
    // Time temp;
    for (int i = 0; i < n; i++)
    {
        p[i].start = arr[i];
        p[i].end = dep[i];
    }

    sort(p, p + n, comp);

    for (int i = 0; i < n; i++)
    {
        cout << i << " " << p[i].start << " " << p[i].end << endl;
    }

    for (int i = 0; i < n - 1; i++)
    {
        if (p[i].end > p[i + 1].start)
        {
            // cout << "i: " << i << " j: " << i + 1 << endl;
            int count = 1;
            int j = i + 1;
            cout << count << " " << j << endl;
            while ((j < n) && (p[j].start <= p[i].end))
            {
                count++;
                j++;
                // cout << count << " " << j << endl;
            }
            i = j - 1;
            ans = max(ans, count);
        }
    }

    return ans;
}

int main()
{
    vector<int> arr, dep;
    arr = {900, 940, 950, 1100, 1500, 1800};
    dep = {910, 1200, 1120, 1130, 1900, 2000};
    arr = {1000, 935, 1100};
    dep = {1200, 1240, 1130};
    arr = {900, 1235, 1100};
    dep = {1000, 1240, 1200};
    int a = findPlatform(arr, dep);
    cout << "Final: " << a << endl;
}
