#include <bits/stdc++.h>

using namespace std;

void alternateNumbers(vector<int> &a)
{
    // Write your code here.

    vector<int> toReturn;
    int po = 0, ne = 0;
    int n = a.size();

    while (ne < n)
    {
        while (a[po] < 0 && po < n)
        {
            ++po;
        }
        // cout<<"Positive: "<<po<<"  "<<a[po]<<endl;
        while (a[ne] >= 0 && ne < n)
        {
            ++ne;
        }
        // cout << "Negative: " << ne << "  " << a[ne] << endl;
        toReturn.push_back(a[po]);
        toReturn.push_back(a[ne]);
        ++po;
        ++ne;
    }
    // return toReturn;
    for(int i =0; i<n;i++){
        cout<<"Dude: "<<toReturn[i]<<endl;
    }
}

int main(){
   
    // vector<int> arr = {-1,3,5,0,-2,-5};
    // vector<int> arr = {1, 2, 3, -1, -2, -3};
    // vector<int> arr = {3, 1, -2, -5, 2, -4};
    vector<int> arr = {1,-1};

    alternateNumbers(arr);
}