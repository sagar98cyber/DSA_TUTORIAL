#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int minEatingSpeed(vector<int> &piles, int h)
{

    int low = 1, high = *max_element(piles.begin(), piles.end());
    int ans = INT_MAX;

    while (low <= high)
    {
        int mid = low + ((high - low) / 2);

        int64_t totalHours = 0;

        for (int pile : piles)
        {
            cout << "Pile % mid:  " << (pile % mid) << endl;
            if ((pile % mid) == 0)
            {
                totalHours += (pile / mid);
            }
            else
            {
                totalHours += ((pile / mid) + 1);
            }
            cout << "Total Hours:  " << totalHours << endl;
        }

        if (mid < ans && totalHours <= h)
        {
            ans = mid;
        }

        // IF TOTAL HOURS is greater than the target hour that means we need to decrease the MID hence lower the MID

        cout << "Low: " << low << "  High: " << high << endl;
        cout << "Hours: " << h << "  Total Hours: " << totalHours << endl;
        if (h < totalHours)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
        cout << "Low: " << low << "  High: " << high << endl;
    }

    return ans;
}