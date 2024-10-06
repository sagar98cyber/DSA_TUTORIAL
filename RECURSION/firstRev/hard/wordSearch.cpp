#include <bits/stdc++.h>

using namespace std;

class Solution
{

    bool checkRecur(string &s, vector<vector<char>> &mat, int ind, int m, int n, int row, int col)
    {
        if (s.length() == ind)
        {
            return true;
        }
        if (row < 0 || col < 0 || row >= m || col >= n || mat[row][col] != s[ind] || mat[row][col] == '!')
        {
            return false;
        }
        // cout<<"Success at position:  "<<row<<","<<col<<","<<mat[row][col]<<endl;

        char c = mat[row][col];
        mat[row][col] = '!';

        // check top row--
        bool top = checkRecur(s, mat, ind + 1, m, n, row - 1, col);
        // check bottom row++
        bool bottom = checkRecur(s, mat, ind + 1, m, n, row + 1, col);
        // check left col++
        bool right = checkRecur(s, mat, ind + 1, m, n, row, col + 1);
        // check right col--
        bool left = checkRecur(s, mat, ind + 1, m, n, row, col - 1);

        mat[row][col] = c;

        return top || bottom || left || right;
    }

public:
    bool exist(vector<vector<char>> &mat, string s)
    {
        int m = mat.size(), n = mat[0].size();
        if (s.length() > (m * n))
        {
            return false;
        }
        // cout<<"M:  "<<m<<"   N:  "<<n<<endl;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (s[0] == mat[i][j])
                {
                    // cout<<"Found a first at position: "<<i<<"  "<<j<<endl;
                    if (checkRecur(s, mat, 0, m, n, i, j))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};