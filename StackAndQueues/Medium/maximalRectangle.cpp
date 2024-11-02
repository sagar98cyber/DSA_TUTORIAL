#include <bits/stdc++.h>

using namespace std;

int maximalRectangle(vector<vector<char>> &q)
{
    int n = q.size(), m = q[0].size();
    int ans = INT_MIN;

    vector<int> t(m, 0);

    for (int i = 0; i < n; i++)
    {
        stack<int> st;
        for (int j = 0; j < m; j++)
        {
            //ASSIGNING the current value
            if (t[j] == 0)
            {
                t[j] = q[i][j] - '0';
            }
            else if (q[i][j] - '0' == 0)
            {
                t[j] = 0;
            }
            else
            {
                t[j] += (q[i][j] - '0');
            }
            
            //STARTS FROM HERE
            int currEle = t[j], pSE = -1, nSE = j, element;

            while ((!st.empty()) && (t[st.top()] > currEle))
            {

                element = t[st.top()];
                st.pop();
                if (!st.empty())
                {
                    pSE = st.top();
                }
                else
                {
                    pSE = -1;
                }
                nSE = j;

                int area = element * (nSE - pSE - 1);

                ans = max(ans, area);
            }

            st.push(j);
        }

        int nSE = m;
        while (!st.empty())
        {

            int element = t[st.top()];
            int pSE = -1;
            st.pop();
            if (!st.empty())
            {
                pSE = st.top();
            }

            int area = element * (nSE - pSE - 1);

            ans = max(ans, area);
        }
    }
    cout << endl
         << endl
         << "ANSWER:  " << ans << endl;
    return ans;
}

int main()
{
    vector<vector<char>> q;
    // q = {
    // {'1', '0', '1', '0', '0'},
    // {'1', '0', '1', '1', '1'},
    // {'1', '1', '1', '1', '1'},
    // {'1', '0', '0', '1', '0'}};
    // q = {{'0', '1'}};

    // q = {
    //     {'0', '0', '1'},
    //     {'1', '1', '1'}};

    q = {
        {'1', '1', '0', '1'},
        {'1', '1', '0', '1'},
        {'1', '1', '1', '1'}};

    maximalRectangle(q);
    return 1;
}