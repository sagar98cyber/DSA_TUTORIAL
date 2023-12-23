#include <bits/stdc++.h>

using namespace std;

int maxProfit(vector<int> &prices)
{
    int min_el = INT_MAX;
    int max_el = 0;
    int profit = max_el - min_el;
    for (int i = 0; i < prices.size(); i++)
    {
        if (prices[i] < min_el)
        {
            min_el = prices[i];
            max_el = -1;
        }
        else
        {
            max_el = max(max_el, prices[i]);
        }
        profit = max(profit, max_el - min_el);
    }
    if (profit < 0)
        return 0;
    return profit;
}

int main()
{
    vector<int> test = { 7, 1, 5, 3, 6, 4 };

    cout<<"The Max Profit is:  "<<maxProfit(test);
}