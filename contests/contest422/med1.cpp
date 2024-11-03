#include <bits/stdc++.h>

using namespace std;

int minTimeToReach(vector<vector<int>> &mT)
{
    int n = mT.size(), m = mT[0].size();

    int i = 0, j = 0, count = 0;

    while (((i + 1) < n) && (j < m))
    {
        cout << "Starting at : " << i << ", " << j << endl;
        bool found = false;
        int k = j;

        while (!found && k >= 0)
        {
            // cout << "Neg While at : "; //<< i << ", " << k << "     " << i + 1 << ", " << k << "    Comparing: " << mT[i][k] << "---" << mT[i + 1][k] << endl;
            // cout << mT[i][k] << "   " << i << ", " << k << "     " << i + 1 << ", " << k << endl;
            if (mT[i][k] == mT[i + 1][k])
            {
                found = true;
                // int a = j, b = k;
                // if (a < k)
                // {
                //     swap(a, k);
                // }
                // count += (a - b) + 1;
                break;
            }
            k--;
        }
        if (found)
        {
            i++;
            j = k;
            break;
        }
        k = j;
        while (!found && k < m)
        {
            // cout << "Pos While at : "; //<< i << ", " << k << "     " << i + 1 << ", " << k << "    Comparing: " << mT[i][k] << "---" << mT[i + 1][k] << endl;
            // cout << mT[i][k] << "   " << i << ", " << k << "     " << i + 1 << ", " << k << endl;
            if (mT[i][k] == mT[i + 1][k])
            {
                found = true;
                int a = j, b = k;
                if (a < k)
                {
                    swap(a, k);
                }
                count += (a - b) + 1;
                break;
            }
            k++;
        }
        i++;
        j = k;
        cout << "Last j: " << j << ", " << k << endl;
    }
    // cout << "Final:  " << (m - 1) << ", " << j << ", " << count << endl;
    count += ((m - 1) - j);
    return count;
}

int main()
{
    vector<vector<int>> r;
    r = {
        {0, 4},
        {4, 4}};

    // r = {
    //     {0, 2, 5, 6, 7},
    //     {1, 4, 5, 5, 5},
    //     {2, 3, 5, 5, 5},
    //     {0, 4, 2, 2, 5},
    //     {1, 6, 2, 5, 4}};

    int ans = minTimeToReach(r);
    cout << "Answer: " << ans << endl;
    return ans;
}