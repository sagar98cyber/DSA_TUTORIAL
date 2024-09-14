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

bool solve(int limit, vector<int> &a, vector<int> temp, int sum, int i)
{
    if (i == a.size())
    {
        if (sum == limit)
        {
            printDS(temp);
            return true;
        }
        return false;
    }

    if(solve(limit, a, temp, sum, i + 1) == true){return true;}
    temp.push_back(a[i]);
    sum += a[i];
    if(solve(limit, a, temp, sum, i + 1) == true){return true;}
    return false;
}

int main()
{
    vector<int> a = {1, 2, 1}, d;
    int sum = 3;

    solve(sum, a, d, 0, 0);
}