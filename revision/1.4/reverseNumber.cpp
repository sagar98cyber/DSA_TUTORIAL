#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int reverse(int t)
{
    int retRev = 0;
    int tD = abs(t);
    while (tD != 0)
    {
        retRev = retRev * 10;
        int temp = tD % 10;
        tD = tD/10;
        retRev += temp;
    }
    if (t < 0)
    {
        retRev = 0 - retRev;
    }

    return retRev;
}



int main()
{
    int t = 120;
    cout<<"Reverse is:  "<<reverse(t);
}