#include <bits/stdc++.h>

using namespace std;

int bSearch(vector<int> &a, int t)
{
    int low = 0, high = a.size() - 1;
    int mid = (low + high) / 2;

    while (low <= high)
    {
        mid = (low + high) / 2;
        cout<<"Low: "<<low<<"  High: "<<high<<"  Mid: "<<mid<<endl;
        if(a[mid] == t)
        {
            return mid;
        }
        if (a[mid] <= t)
        {
            low = mid+1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return mid+1;
}

int search_position(vector<int> &a, int t)
{

    return bSearch(a, t);
}

int main()
{
    vector<int> a = { 1, 3, 5, 6 };
    int target = 2;
    // int target = 5;

    cout << bSearch(a, target);
}