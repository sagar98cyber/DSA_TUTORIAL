#include <bits/stdc++.h>

using namespace std;

void bitManipulation(int num, int i)
{
    // your code here
    
    int getBit, setBit, clearBit, temp = num;
    if ((num & (1 << (i - 1))) == 0)
    {
        getBit = 0;
    }
    else
    {
        getBit = 1;
    }

    setBit = (num | (1 << (i - 1)));
    clearBit = setBit ^ (1 << (i - 1));
    cout << getBit << " " << setBit << " " << clearBit;
}

int main()
{
    // int n = 70, k = 3;
    int n = 8, k = 1;
    bitManipulation(n,k);
    return 1;
}