#include <bits/stdc++.h>
// #include <string.h>
using namespace std;

void returnSizeOfMap(set<char> &mpp, int &count)
{
    count = mpp.size();
}

int countSubStrings(string str, int k)
{
    int count = 0, freq = 0;
    set<char> cS;

    int len = str.length();

    if (len < k)
    {
        return 0;
    }

    // Write your code here.
    int low = 0, high = 1;

    cS.insert(str[low]);
    cS.insert(str[high]);
    returnSizeOfMap(cS, count);
    while (low < high && high <= len)
    {
        cout << "Low: " << low << " High: " << high << "  Count: " << count << "  Frequency: " << freq << endl;
        cout << "String in consideration:  " << str.substr(low, high - low) << endl;
        returnSizeOfMap(cS, count);

        if (count < k)
        {
            cS.insert(str[high]);
            high++;
        }
        else if (count > k)
        {
            cS.erase(str[low]);
            low++;
            cS.insert(str[low]);
        }
        else if (count == k)
        {
            freq++;
            cout << "++++++ Incrementing Freq: by 1 for string: +++++++++ " << str.substr(low, high - low) << endl;
            cS.erase(str[low]);
            low++;
            cS.insert(str[low]);
            high++;
            cS.insert(str[high]);
        }
        returnSizeOfMap(cS, count);
        // cout << "---------------- Next string in consideration:  " << str.substr(low, high - low) << endl;
    }

    return freq;
}

int main()
{
    cout << "Final:  " << countSubStrings("aacfssa", 3);
    return 0;
}
