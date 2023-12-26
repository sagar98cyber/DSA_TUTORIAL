#include <bits/stdc++.h>

using namespace std;

vector<int> findMissingRepeatingNumbers(vector<int> a)
{
    // Write your code here
    long long n = a.size();

    long long x = 0;
    long long y = (n * (n + 1)) / 2;
    long long xSQ = 0, ySQ = (n * (n + 1) * (2 * n + 1)) / 6;

    for (int i = 0; i < n; i++)
    {
        x += a[i];
        xSQ = xSQ + ((long long)a[i] * (long long)a[i]);
    }

    long long x_y = x - y; // -2

    long long xSQ_ySQ = xSQ - ySQ; //   -6
    // cout<<"X_SQUARE:  "<<xSQ<<"Y_SQUARE:  "<<ySQ << " X_Y:  " << x_y<< "  xSQ - ySQ:  "<<xSQ_ySQ<<endl;
    long long xPLUSy = xSQ_ySQ / x_y;
    // cout<<"X-Y:  "<<x_y<<" X+Y:  "<<xPLUSy<<endl;
    int repeating = (x_y + xPLUSy) / 2;
    int missing = (xPLUSy - repeating);

    vector<int> temp = {repeating, missing};
    cout<<"Repeating:  "<<repeating<<endl<<"  Missing:  "<<missing<<endl;
    return temp;
    // return a;
}

 
int main()
{
    vector<int> nums = { 1, 2, 3, 2 };
    findMissingRepeatingNumbers(nums);
}