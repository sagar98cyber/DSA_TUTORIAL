#include<bits/stdc++.h>

using namespace std;

void printDS(vector<int>& a)
{   
    cout<<"New Ans: "<<endl;
    for(auto i:a)
    {
        cout<<i<<endl;
    }
}

void solve(int limit, vector<int>& a, vector<int> temp, int sum, int i)
{
    if(i==a.size())
    {
        if(sum == limit)
        {
            printDS(temp);
        }
        return;
    }

    solve(limit, a, temp, sum, i+1);
    temp.push_back(a[i]);
    sum += a[i];
    solve(limit, a, temp, sum, i+1);
}

int main()
{
    vector<int> a = {1,2,3,1,1}, d;
    int sum = 3;

    solve(sum, a, d, 0, 0);
}