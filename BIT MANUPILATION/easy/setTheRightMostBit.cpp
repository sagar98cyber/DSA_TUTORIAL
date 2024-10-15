// https : // www.geeksforgeeks.org/problems/set-the-rightmost-unset-bit4436/1

#include <bits/stdc++.h>

using namespace std;

int setBit(int n)
{
    // Write Your Code here
    return n | (n + 1);
}

int main()
{
    int n = 137;
    cout<<setBit(n);
    return 1;
}