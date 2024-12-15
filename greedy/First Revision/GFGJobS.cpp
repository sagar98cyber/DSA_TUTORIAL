#include <bits/stdc++.h>

using namespace std;

struct Job
{
    int id;       // Job Id
    int deadline; // Deadline of job
    int profit;   // Profit if job is over before or on deadline
};

// bool compA(Job a, Job b)
// {
//     if (a.deadline == b.deadline)
//     {
//         return a.profit > b.profit;
//     }
//     return a.deadline < b.deadline;
// }

bool compA(Job a, Job b)
{
    return a.profit > b.profit;
}

vector<int> JobScheduling(Job jobs[], int n)
{
    // your code here

    // int n = (sizeof(jobs) / sizeof(jobs[0]));
    Job t;
    vector<int> ans;
    int maxD = -1;

    sort(jobs, jobs + n, compA);

    for (int i = 0; i < n; i++)
    {
        maxD = max(maxD, jobs[i].deadline);
        // cout << jobs[i].deadline << " " << jobs[i].profit << " " << endl;
    }
    int val = 0, count = 0;
    vector<int> temp(maxD, 0);

    for (int i = 0; i < n; i++)
    {
        int d = jobs[i].deadline;
        if (temp[d - 1] != 0)
        {
            int j = d - 1;
            while ((j >= 0) && (temp[j] != 0))
            {
                j--;
            }
            if (j >= 0)
            {
                temp[j] = max(temp[j], jobs[i].profit);
            }
        }
        else
        {
            temp[d - 1] = jobs[i].profit;
        }
    }
    for (int i = 0; i < maxD; i++)
    {
        // cout << temp[i] << endl;
        if (temp[i] != 0)
        {
            val += temp[i];
            count++;
        }
    }
    ans.push_back(count);
    ans.push_back(val);
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