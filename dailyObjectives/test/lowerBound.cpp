// C++ program to illustrate the use of std::lower_bound
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {10, 20, 30, 40, 50};

    // Finding lower bound for value 35 in vector v
    auto lb = lower_bound(v.begin(), v.end(), 35);
    cout << *lb << "  ";

    return 0;
}
