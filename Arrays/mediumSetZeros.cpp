#include <bits/stdc++.h>
using namespace std;

////////////////////  BRUTE FORCE SOLUTION

// void setZeroes(vector<vector<int>>& matrix) {
       
//         // vector<pair<int,int>> toMakeZero;

//         int m = matrix.size(), n = matrix[0].size();

//         // cout<<"Printing: "<<m<<"  "<<n<<"   "<<matrix[1][1] <<endl;

//         for(int i =0;i<m;i++)
//         {
//             for(int j=0;j<n;j++)
//             {
//                 // cout << "This is: " << matrix[i][j] << endl;
//                 if(matrix[i][j] == 0)
//                 {
//                     // cout<<"This is Zero: "<<i<<"   "<<j<<endl;
//                     // toMakeZero.push_back(make_pair(i,j));
//                 }
//             }
//         }

//         int len = toMakeZero.size();

//         if (len >0){
//             for(int i=0; i<len; i++)
//             {
//                 // cout<<"Dude:  "<<toMakeZero[i].first<<"     "<<toMakeZero[i].second<<endl;
                
//                 int one = toMakeZero[i].first, two = toMakeZero[i].second;

//                 for(int i =0; i<m; i++){
//                     matrix[i][two] = 0;
//                 }
//                 for (int i = 0; i < n; i++)
//                 {
//                     matrix[one][i] = 0;
//                 }
//             }
//         }
//     }


////////////////////   OPTIMIZED SOLUTION

void printMatrix(vector<vector<int>> &matrix)
{
    int m = matrix.size(), n = matrix[0].size();

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] <<"  " ;
        }
        cout<<endl;
    }
    cout << endl
         << endl
         << "End of Printing" << endl
         << endl
         << endl;
}

// void setZeroes(vector<vector<int>> &matt)
// {
//     // printMatrix(matt);

//     int m = matt.size(), n = matt[0].size(), markCol0 = 1, markRow0=1;

//     // cout<<"Printing: "<<m<<"  "<<n<<"   "<<matt[1][1] <<endl;

//     ///////////   MARK ZEROS IN ROW0 AND COL0
//     for (int i = 0; i < m; i++)
//     {
//         if (matt[i][0] == 0)
//         {
//             markCol0 =0;
//         }
//     }

//     for(int i=0; i<n; i++){
//         if (matt[0][i] == 0)
//         {
//             markRow0 = 0;
//         }
//     }

//     ///////////   MARK ZEROS IN ROW0 AND COL0
//     for (int i = 0; i < m; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             if (matt[i][j] == 0)
//             {
//                     matt[0][j] = 0;
//                     matt[i][0] = 0;
//             }
//         }
//     }

//     // printMatrix(matt);

//     ///////   COLUMNS
//     for(int i =1;i<n;i++)
//     {
//         if(matt[0][i] == 0){
//             for(int j=0;j<m;j++){
//                 matt[j][i] = 0;
//             }
//         }
//     }

//     // printMatrix(matt);
    
//     ///////    ROWS
//     for( int i=1; i<m; i++)
//     {
//         if(matt[i][0]==0){
//             for(int j=1; j<n; j++)
//             {
//                 matt[i][j] = 0;
//             }
//         }
//     }

//     // printMatrix(matt);

//     if(markRow0 == 0)
//     {
//         for (int i = 0; i < n; i++)
//         {
//             matt[0][i] = 0;
//         }
//     }

//     // printMatrix(matt);

//     if (markCol0 == 0)
//     {
//         for (int i = 0; i < m; i++)
//         {
//             matt[i][0] = 0;
//         }
//     }

//     // printMatrix(matt);

//     if(markCol0 == 0 || markRow0 == 0)
//     {
//         matt[0][0] =0;
//     }

//     // printMatrix(matt);
// }

////////////////////  better solution of STRIVER

void setZeroes(vector<vector<int>> &matrix)
{

    int n = matrix.size();
    int m = matrix[0].size();
    // int row[n] = {0}; --> matrix[..][0]
    // int col[m] = {0}; --> matrix[0][..]

    int col0 = 1;
    // step 1: Traverse the matrix and
    // mark 1st row & col accordingly:
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                // mark i-th row:
                matrix[i][0] = 0;

                // mark j-th column:
                if (j != 0)
                    matrix[0][j] = 0;
                else
                    col0 = 0;
            }
        }
    }

    // Step 2: Mark with 0 from (1,1) to (n-1, m-1):
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (matrix[i][j] != 0)
            {
                // check for col & row:
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }

    // step 3: Finally mark the 1st col & then 1st row:
    if (matrix[0][0] == 0)
    {
        for (int j = 0; j < m; j++)
        {
            matrix[0][j] = 0;
        }
    }
    if (col0 == 0)
    {
        for (int i = 0; i < n; i++)
        {
            matrix[i][0] = 0;
        }
    }
    printMatrix(matrix);
}


int main()
{
    // vector<vector<int>> t = {{1, 1, 1}, { 1, 0, 1 }, { 1, 1, 1 }};

    vector<vector<int>> t = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};

    // vector<vector<int>> t = {
    //     {1, 1, 1, 1},
    //     {1, 1, 1, 1},
    //     {1, 1, 0, 1},
    //     {1, 1, 1, 1}};

    // vector<vector<int>> t = {{1, 2, 3, 4}, {5, 0, 7, 8}, {0, 10, 11, 12}, {13, 14, 15, 0}};

    setZeroes(t);
    return 0;
}