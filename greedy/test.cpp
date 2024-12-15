#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> a = {4, 3, 7, 1, 2};
    // a = {1, 2, 3, 4};
    a = {7, 1, 6, 9, 2, 10, 7, 7, 10, 9};
    sort(a.begin(), a.end());
    int n = a.size();
    long long waitTime = 0, totalTime = 0;
    for (int i = 0; i < n; i++)
    {
        waitTime += totalTime;
        totalTime += a[i];
    }

    waitTime = (waitTime / n);

    cout << waitTime << endl;
    return 0;
}