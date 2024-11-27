#include <bits/stdc++.h>

using namespace std;

void printMatrix(vector<vector<char>> &b)
{
    int m = b.size(), n = b[0].size();
    for (auto &i : b)
    {
        for (auto &j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

vector<vector<char>> rotateTheBox(vector<vector<char>> &b)
{
    // --------- //  m - rows || n - columns
    int m = b.size(), n = b[0].size();
    vector<vector<char>> ans(n, (vector<char>(m, '.')));

    int col = m;

    for (auto &i : b)
    {
        col--;
        int count = 0, row = -1;
        for (auto &j : i)
        {
            row++;
            if (j == '.')
            {
            }
            else if (j == '#')
            {
                count++;
            }
            else
            {
                // Unload all the stones
                ans[row][col] = '*';
                int temp = row - 1;
                while (count != 0)
                {
                    ans[temp][col] = '#';
                    temp--;
                    count--;
                }
            }
        }
        if (count > 0)
        {
            int temp = n - 1;
            while (count != 0)
            {
                // cout << temp << " " << col << endl;
                ans[temp][col] = '#';
                temp--;
                count--;
            }
        }
    }
    printMatrix(ans);
    return ans;
}

int main()
{

    vector<vector<char>> temp = {
        {'#', '#', '*', '.', '*', '.'},
        {'#', '#', '#', '*', '.', '.'},
        {'#', '#', '#', '.', '#', '.'}};
    printMatrix(temp);
    cout << endl
         << endl;
    rotateTheBox(temp);
    // {
    //     { ".", "#", "#" },
    //     { ".", "#", "#" },
    //     { "#", "#", "*" },
    //     { "#", "*", "." },
    //     { "#", ".", "*" },
    //     { "#", ".", "." } };

    // {
    //     { "#", "*", "#", ".", "*", "." },
    //     { "#", "#", "#", "*", ".", "." },
    //     { "#", "#", "#", ".", "#", "." }
    // };
    // {
    //     { ".", "#", "#" },
    //     { ".", "#", "*" },
    //     { "#", "#", "." },
    //     { "#", "*", "#" },
    //     { "#", ".", "*" },
    //     { "#", ".", "." }
    // };
}