#include <bits/stdc++.h>

using namespace std;

int main()
{
    
    char mark ='*';
    string result ="*";
    
    for (int row = 1; row <= 5; row++)
    {
        for (int col = 1; col <= 5 - row; col++)
        {
            cout << " ";
        }
        
        if(row != 1)
        {
            result  = mark+ result + mark;
        }
        cout<<result<<endl;

    }

    return 0;
}