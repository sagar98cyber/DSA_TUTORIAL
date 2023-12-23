#include <bits/stdc++.h>

using namespace std;


//////////////////////    WELL JUST DIDN'T WORK FOR SOME EDGE CASE

// void sorrtFunc(vector<long long> &great, vector<long long> &less)
// {
//     int ptG = 0, ptL = 0, n = great.size(), m = less.size();
//     while (ptG < n && ptL < m)
//     {
//         // cout<<"Considering:"<<endl;
//         if (less[ptL] < great[ptG])
//         {
//             ptL++;
//         }
//         else if (less[ptL] == great[ptG])
//         {
//             ptL++;
//             while (less[ptL] == less[ptL - 1])
//             {
//                 ptL++;
//             }
//         }
//         else
//         {
//             swap(less[ptL], great[ptG]);
//             int i = ptG;
//             while (i < n)
//             {
//                 if (great[ptG] < great[i])
//                 {
//                     swap(great[ptG], great[i]);
//                 }
//                 i++;
//             }
//             ptG++;
//         }
//     }
//     sort(great.begin(), great.end());
//     // sort(less.begin(), less.end());
// }

// void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b)
// {
//     // Write your code here.
//     if (a.size()>b.size())
//     {
//         sorrtFunc(a,b);
//     }
//     else
//     {
//         sorrtFunc(b, a);
//     }
// }




////////////////////   STRIVER's OPTMIAL SOLUTION

void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &less, vector<long long> &great)
{

    int n = less.size(), m = great.size();
    int i = n - 1, j = 0;
    while (i >= 0 && j < m)
    {
        if (less[i] > great[j])
        {
            swap(less[i], great[j]);
        }

        i--;
        j++;
    }

    sort(less.begin(), less.end());

    sort(great.begin(), great.end());
}

int main()
{
    vector <long long> arr1 = {1, 8, 8};
    vector<long long> arr2 = {2, 3, 4, 5};
    mergeTwoSortedArraysWithoutExtraSpace(arr1,arr2);
}