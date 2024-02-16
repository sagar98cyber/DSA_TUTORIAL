#include <bits/stdc++.h>
#include <cmath>
using namespace std;

int countDigits(int n)
{
    int nL=0;
    int i=0;
    while(n != 0)
    {
        i++;
        n=n/10;
    }
    return i;
}

int main()
{
    int cD = 190;
    cout<<"The digits of count in "<<cD << " are: "<<countDigits(cD)<<endl;
}