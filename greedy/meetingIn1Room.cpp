#include <bits/stdc++.h>

using namespace std;

struct Time
{
    int start;
    int end, pos;
};

// bool comp(Time a, Time b)
// {
//     int t1 = a.end - a.start, t2 = b.end - b.start;
//     return t1 < t2;
// }

bool comp(Time a, Time b)
{
    // return (a.end < b.end);
    if (a.end < b.end)
    {
        return true;
    }
    else if (a.end > b.end)
    {
        return false;
    }
    if (a.pos < b.pos)
    {
        return true;
    }
    return false;
}

int maxMeetings(vector<int> &start, vector<int> &end)
{
    int n = start.size(), p1 = 1, prev = 0, count = 1;
    Time p[n];
    Time temp;
    for (int i = 0; i < n; i++)
    {
        temp = Time({start[i], end[i], i + 1});
        p[i] = temp;
    }

    sort(p, p + n, comp);

    for (int i = 0; i < n; i++)
    {
        cout << p[i].start << " " << p[i].end << endl;
    }
    // for (; p1 < n; p1++)
    // {
    //     auto &cur = p[p1];
    //     auto &previous = p[prev];
    //     int curStart = cur.start, prevEnd = previous.end;
    //     cout << "CurStart: " << curStart << "  Previous End: " << prevEnd << endl;
    //     if (curStart > previous.end)
    //     {
    //         cout << "INSIDE IF  -  CurStart: " << curStart << "  Previous End: " << prevEnd << endl;
    //         count++;
    //         prev = p1;
    //     }
    // }
    // cout << "Count: " << count << endl;
    return count;
}

int main()
{
    vector<int> start = {1, 3, 0, 5, 8, 5}, end = {2, 4, 6, 7, 9, 9};
    // start = {10, 12, 20};
    // end = {20, 25, 30};
    maxMeetings(start, end);
}