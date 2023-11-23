#include <bits/stdc++.h>
using namespace std;

void pritnArray(vector<vector<int>> &arr)
{
    for(int i=0; i<arr.size(); i++)
    {   cout<<"{";
        for( int j=0; j<arr[0].size(); j++)
        {
            cout<<arr[i][j]<<" ";
        }
        // cout<<endl;
        cout<<"}";
    }
}




///////////////////////////   ALMOST RIGHT IN OPTIMAL BUT TIME COMPLEXITY INCREASES BECAUSE OF THE ERASE FUNCTION

// void mergeOverlappingIntervals(vector<vector<int>> &arr)
// {
//     // Write your code here.
//     int n = arr.size(), m = arr[0].size(), i = 1;
//     int low=0, high=1;

//     int l1 = arr[0][0], r1 = arr[0][1], l2, r2;

//     while(high<n)
//     {
//         l2 = arr[high][0];
//         r2 = arr[high][1]; 
//         if (l2 <= r1)
//         {
//             arr[low][1] = max(r1,r2);
//             arr.erase(arr.begin() + high);

//             n = arr.size();
//             // cout<<low<<"    "<<high<<"  "<<l2<<"  asad  "<<r2<<endl;
//         }
//         else
//         {
//             // cout << l1 << "  " << r1 << "   " << l2 << "   " << r2 << endl;
//             low=high;
//             high++;            
//         }
//         l1 = arr[low][0];
//         r1 = arr[low][1];

//     }

//     // int temp = arr.size();
//     // cout<< endl<< endl << temp<<endl;
//     // pritnArray(arr);
// }


vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr)
{

    int n=arr.size();

    sort(arr.begin(),arr.end());
    vector<vector<int>> ans;

    for (int i = 0; i < n; i++)
    {
        if(ans.empty() || arr[i][0]>ans.back()[1])
        {
            ans.push_back(arr[i]);
        }
        else
        {
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }

    pritnArray(ans);
}


int main()
{
    vector<vector<int>> arr = {{1, 2}, {1, 3}, {1, 6}, {3, 4}, {4, 4}, {4, 5}, {5, 5}, {6, 6}, {6, 6}};
    pritnArray(arr);
    cout << endl;
    mergeOverlappingIntervals(arr);
}