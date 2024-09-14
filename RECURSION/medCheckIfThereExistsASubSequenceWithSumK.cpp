// CODING NINJAS PROBLEM NAME:
// Subset Sum

#include <bits/stdc++.h>

using namespace std;

bool resolve(int limit, int sum, int i, vector<int>& a)
{
    if(limit < sum)
    {
        return false;
    }
    if(i == a.size())
    {
        if(limit == sum)
        {
            return true;
        }
        return false;
    }
    if (resolve(limit, sum, i + 1, a) == true)
    {
        return true;
    }
    sum += a[i];
    if (resolve(limit, sum, i + 1, a) == true)
    {
        return true;
    }
    return false;
}

int main()
{
    // vector<int> a = {1, 2, 3};
    // int limit = 5;

    vector<int> a = {1,0};
    int limit = 1;

    bool res = resolve(limit, 0, 0, a);

    cout<<"The final response is: "<<res<<endl;
    return 0;
}