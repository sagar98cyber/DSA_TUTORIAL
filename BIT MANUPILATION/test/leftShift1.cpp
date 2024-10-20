#include <bits/stdc++.h>

using namespace std;

int main()
{
    // cout << (3 << 0) << " " << (3 << 1) << " " << (3 << 2) << " " << (3 << 3) << endl
    //      << endl
    //      << endl
    //      << endl;

    cout << (1 ^ 2 ^ 3 ^ 4) << " " << (4 ^ 5 ^ 6 ^ 7 ^ 8) << endl;
    int mask = 1;
    while (not(10 & mask))
    {
        cout << mask << "   " << (10 & mask) << "   " << not(10 & mask) << endl;
        mask <<= 1;
        cout << mask << "   " << (10 & mask) << "   " << not(10 & mask) << endl
             << endl;
    }
    cout << "Ans:  " << mask << endl;

    // int ans = 1;
    // cout << ans << "   " << (10 & ans) << "   " << not(10 & ans) << endl;
    // ans <<= 1;
    // cout << ans << "   " << (10 & ans) << "   " << not(10 & ans) << endl;
    // ans <<= 1;
    // cout << ans << "   " << (10 & ans) << "   " << not(10 & ans) << endl;
    // ans <<= 1;
    // cout << ans << "   " << (10 & ans) << "   " << not(10 & ans) << endl;
    // ans <<= 1;
    // cout << ans << "   " << (10 & ans) << "   " << not(10 & ans) << endl;
    // ans <<= 1;
    // cout << ans << "   " << (10 & ans) << "   " << not(10 & ans) << endl;
    // ans <<= 1;
    // cout << ans << "   " << (10 & ans) << "   " << not(10 & ans) << endl;

    return 1;
}