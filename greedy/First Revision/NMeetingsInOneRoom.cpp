#include <bits/stdc++.h>

using namespace std;

struct Slot
{
    int st, ed;
};

bool compA(Slot a, Slot b)
{
    return (a.ed < b.ed);
    // return ((a.ed - a.st) < (b.ed - b.st));
}

int maxMeetings(vector<int> &start, vector<int> &end)
{
    // Your code here
    int n = start.size();
    int ans = 0;
    Slot t;
    vector<Slot> temp(n, t);

    for (int i = 0; i < n; i++)
    {
        temp[i].st = start[i];
        temp[i].ed = end[i];
    }

    sort(temp.begin(), temp.end(), compA);

    // for (int i = 0; i < n; i++)
    // {
    //     cout << temp[i].st << " " << temp[i].ed << endl;
    // }

    int lastM = -1;
    for (int i = 0; i < n; i++)
    {
        int curSt = temp[i].st, curEnd = temp[i].ed;
        if (lastM < curSt)
        {
            ans++;
            lastM = curEnd;
        }
    }

    return ans;
}

int main()
{
    vector<int> start = {1, 3, 0, 5, 8, 5}, end = {2, 4, 6, 7, 9, 9};

    start = {10, 12, 20};
    end = {20, 25, 30};

    start = {1, 2};
    end = {100, 99};

    int ans = maxMeetings(start, end);
    cout << "Final ans: " << ans << endl;
    return 0;
}