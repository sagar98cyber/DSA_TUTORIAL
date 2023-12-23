#include <bits/stdc++.h>
using namespace std;

void spiralPrinting(vector<vector<int>>& matt)
{   
    int n = matt.size(), m = matt[0].size();
    int left = 0,right = m-1, top =0, bottom = n-1;
    
    while (top <= bottom && left <= right)
    {
        for(int i=left; i<=right;i++)
        {
            cout<<matt[top][i]<<"  "<<endl;
        }
        top++;

        for (int i = top; i <= bottom; i++)
        {
            cout << matt[i][right] << "  " << endl;
        }
        right--;

        if(top <= bottom){
            for (int i = right; i >= left; i--)
            {
                cout << matt[bottom][i] << "  " << endl;
            }
            bottom--;
        }

        if(left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                cout << matt[i][left] << "  " << endl;
            }
            left++;
        }
    }
}

int main(){
    vector<vector<int>> test = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    spiralPrinting(test);
}