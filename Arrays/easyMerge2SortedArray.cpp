#include <bits/stdc++.h>

using namespace std;

vector<int> sortedArray(vector<int> a, vector<int> b)
{
    // Write your code here
    int lenA = a.size(), lenB = b.size();

    int low = 0, high = 0, i;
    // int lowest = min(lenA, lenB);

    vector<int> finalRes;
    int lastEle = -2;
    while (low < lenA && high < lenB)
    {
        // cout<<"Element into consideration:  "<<a[low]<<"   "<<b[high]<<"    "<<lastEle<<endl;
        if (a[low] != lastEle && b[high] != lastEle)
        {
            if (a[low] == b[high])
            {
                // cout << "Pushing Equal : " << a[low] << endl;
                finalRes.push_back(a[low]);
                lastEle = a[low];
                low++;
                high++;
            }
            else if (a[low] < b[high])
            {
                // cout << "Pushing LEss: " << a[low] << endl;
                finalRes.push_back(a[low]);
                lastEle = a[low];
                low++;
                
            }
            else
            {
                // cout << "Pushing Else: " << a[low] << endl;
                finalRes.push_back(b[high]);
                lastEle = b[high];
                high++;
                
            }
        }
        else
        {
            if (a[low] == lastEle)
            {
                // cout << "Incrementing Low " << endl;
                low++;
            }
            else
            {
                // cout << "Incrementing High " << endl;
                high++;
            }
        }
    }

    for (i = low; i < lenA; i++)
    {
        finalRes.push_back(a[i]);
    }

    for (i = high; i < lenB; i++)
    {
        finalRes.push_back(b[i]);
    }

    // cout << "---- Final: \n";
    // for (i = 0; i < finalRes.size(); i++)
    // {
    //     cout << finalRes[i] << endl;
    // }
    // cout << "Final End ---- \n";

    return finalRes;
}


int main()
{
    vector<int> a = {1, 2, 3, 3};
    vector<int> b = {2, 2, 4};

    sortedArray(a,b);
}