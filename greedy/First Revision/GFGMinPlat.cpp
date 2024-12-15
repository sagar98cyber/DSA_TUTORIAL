#include <bits/stdc++.h>

using namespace std;

struct GFGMinPlat
{
    /* data */
    int arr, dep;
};

bool compA(GFGMinPlat a, GFGMinPlat b)
{
    return a.dep < b.dep;
}

int findPlatform(vector<int> &arr, vector<int> &dep)
{
    // Your code here

    int n = arr.size();

    GFGMinPlat t;
    vector<GFGMinPlat> temp(n, t);
    for (int i = 0; i < n; i++)
    {
        temp[i].arr = arr[i];
        temp[i].dep = dep[i];
    }

    sort(temp.begin(), temp.end(), compA);
    int maxDep = temp[0].dep;

    // for (int i = 0; i < n; i++)
    // {
    //     cout << temp[i].arr << " " << temp[i].dep << endl;
    // }

    int ans = 1;

    for (int i = 0; i < n; i++)
    {
        if ()
        {
            int count = 1;

            ans = max(ans, count);
        }
    }

    return ans;
}

int main()
{
    vector<int> arr, dep;
    arr = {950, 900, 940, 1500, 1100, 1800};
    dep = {1120, 910, 1200, 1900, 1130, 2000};
    // arr = {1000, 935, 1100};
    // dep = {1200, 1240, 1130};
    // arr = {900, 1235, 1100};
    // dep = {1000, 1240, 1200};
    // arr = {1114, 825, 357, 1415, 54};
    // dep = {1740, 1110, 2238, 1535, 2323};
    int a = findPlatform(arr, dep);
    cout << "Final: " << a << endl;
}
