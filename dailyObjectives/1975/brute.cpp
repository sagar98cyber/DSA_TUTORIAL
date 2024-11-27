#include <bits/stdc++.h>

using namespace std;

bool checkAllPositive(vector<vector<int>> &m, int i, int j)
{
    int n = m.size(), m1 = m.size();
    // top
    if ((i - 1) >= 0)
    {
        // nW
        if (j - 1 >= 0)
        {
            if (m[i - 1][j - 1] <= 0)
            {
                return false;
            }
        }
        // nE
        if (j + 1 < m1)
        {
            if (m[i - 1][j + 1] <= 0)
            {
                return false;
            }
        }
        // n
        if (m[i - 1][j] <= 0)
        {
            return false;
        }
    }
    // bottom
    if (i + 1 < m1)
    {
        // sW
        if (j - 1 >= 0)
        {
            if (m[i + 1][j - 1] <= 0)
            {
                return false;
            }
        }
        // sE
        if (j + 1 < m1)
        {
            if (m[i + 1][j - 1] <= 0)
            {
                return false;
            }
        }
        // s
        if (m[i + 1][j] <= 0)
        {
            return false;
        }
    }
    return true;
}

int returnNum(vector<vector<int>> &m, int i, int j)
{
    int n = m.size(), m1 = m[0].size();
    int a = m[i, j];
    if ((i < 0) || (i == n) || (j < 0) || (j == m1) || (a > 0))
    {
        return INT_MIN;
    }
    return a;
}

long long ansRet(vector<vector<int>> &m)
{
    long long ans = 0;
    for (auto &i : m)
    {
        for (auto &j : i)
        {
            ans += j;
        }
    }
    return ans;
}

long long maxMatrixSum(vector<vector<int>> &m)
{
    int n = m.size(), m1 = m.size();
    int i = 0, j = 0;
    while ((i < n) && (j <= m1))
    {
        if ((j == m) && (i == n - 1))
        {
            break;
        }
        if ((j == m) && (i < n - 1))
        {
            j = 0;
            i++;
            continue;
        }
        if (m[i][j] >= 0)
        {
            j++;
            continue;
        }
        if (checkAllPositive(m, i, j))
        {
            j++;
            continue;
        }
        int nE = returnNum(m, i - 1, j + 1),
            nW = returnNum(m, i - 1, j - 1),
            sE = returnNum(m, i + 1, j + 1),
            sW = returnNum(m, i + 1, j - 1),
            e = returnNum(m, i, j + 1),
            w = returnNum(m, i, j - 1),
            s = returnNum(m, i + 1, j),
            n = returnNum(m, i - 1, j);
        int nI = i - 1, nJ = j + 1;
        if ((sE != INT_MIN) && (sE > m[nI][nJ]))
        {
            nI = i + 1;
            nJ = j + 1;
        }
        if ((nW != INT_MIN) && (nW > m[nI][nJ]))
        {
            nI = i - 1;
            nJ = j - 1;
        }
        if ((sW != INT_MIN) && (sW > m[nI][nJ]))
        {
            nI = i + 1;
            nJ = j - 1;
        }
        if ((n != INT_MIN) && (n > m[nI][nJ]))
        {
            nI = i - 1;
            nJ = j;
        }
        if ((s != INT_MIN) && (s > m[nI][nJ]))
        {
            nI = i + 1;
            nJ = j;
        }
        if ((e != INT_MIN) && (e > m[nI][nJ]))
        {
            nI = i;
            nJ = j + 1;
        }
        if ((w != INT_MIN) && (w > m[nI][nJ]))
        {
            nI = i;
            nJ = j - 1;
        }
        if ((nE != INT_MIN) && (nI == i - 1) && (nJ == j + 1))
        {
            m[i - 1][j + 1] = abs(m[i - 1][j + 1]);
            m[i][j] = abs(m[i][j]);
            i -= 1;
            j -= 1;
            continue;
        }
        m[nI][nJ] = abs(m[nI][nJ]);
        m[i][j] = abs(m[i][j]);
    }
    return ansRet(m);
}