#include <bits/stdc++.h>

using namespace std;

struct Job
{
    int id;       // Job Id
    int deadline; // Deadline of job
    int profit;   // Profit if job is over before or on deadline
};

bool comp(Job a, Job b)
{
    return (a.profit > b.profit);
}

vector<int> JobScheduling(Job jobs[], int n)
{
    vector<int> ans = {0, 0};

    // for (int i = 0; i < n; i++)
    // {
    //     cout << jobs[i].id << " " << jobs[i].deadline << " " << jobs[i].profit << " " << endl;
    // }
    // cout << endl
    //      << endl;
    int maxD = -1;
    for (int i = 0; i < n; i++)
    {
        maxD = max(maxD, jobs[i].deadline);
    }
    sort(jobs, jobs + n, comp);
    vector<int> day(maxD, -1);
    int profit = 0, count = 0;
    for (int i = 0; i < n; i++)
    {

        int st = jobs[i].deadline;
        for (int i = st; i >= 0; i--)
        {
            if (day[i] == -1)
            {
                day[i] = jobs[i].id;
                count++;
                profit += jobs[i].profit;
                break;
            }
        }
    }
    ans[0] = count;
    ans[1] = profit;
    return ans;
}

int main()
{
    vector<vector<int>> t = {{1, 4, 20}, {2, 1, 1}, {3, 1, 40}, {4, 1, 30}};
    t = {{1, 2, 100}, {2, 1, 19}, {3, 2, 27}, {4, 1, 25}, {5, 1, 15}};
    t = {{1, 3, 50}, {2, 1, 10}, {3, 2, 20}, {4, 2, 30}};
    int n = t.size();
    Job p[n];
    for (int i = 0; i < n; i++)
    {
        p[i].id = t[i][0];
        p[i].deadline = t[i][1];
        p[i].profit = t[i][2];
    }

    vector<int> ans = JobScheduling(p, n);
    cout << endl
         << endl
         << endl;
    for (auto &i : ans)
    {
        cout << i << endl;
    }
}