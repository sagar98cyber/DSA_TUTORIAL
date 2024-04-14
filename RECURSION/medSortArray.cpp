#include <bits/stdc++.h>

using namespace std;

void insert(vector<int>& v, int temp)
{
    if(v.size() == 0 || v.back() <= temp)
    {
        v.push_back(temp);
        return;
    }
    int val = v.back();
    v.pop_back();
    insert(v,temp);
    v.push_back(val);
}

void sortS(vector<int>& v)
{
    if(v.size() == 0)
    {
        return;
    }
    int d = v.back();
    v.pop_back();
    sortS(v);
    insert(v,d);
    return;
}

int main()
{
    vector<int> v = {15,4,31,2,11};
    sortS(v);
    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i]<<endl;
    }
    return 0;
}
