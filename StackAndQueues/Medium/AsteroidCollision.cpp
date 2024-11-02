#include <bits/stdc++.h>

using namespace std;

vector<int> asteroidCollision(vector<int> &asteroids)
{
    vector<int> ans;
    stack<int> stk;
    int i = 0;
    int n = asteroids.size();
    while (i < n)
    {
        if (stk.empty() || asteroids[i] > 0 || stk.top() < 0)
            stk.push(asteroids[i++]);
        else if (stk.top() > abs(asteroids[i]))
            i++;
        else if (stk.top() == abs(asteroids[i]))
            stk.pop(), i++;
        else
            stk.pop();
    }
    while (!stk.empty())
    {
        ans.push_back(stk.top());
        stk.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
