
#include <bits/stdc++.h>

using namespace std;

int recur(int n, int val, int x)
{
    if(n == 0)
    {
        return val;
    }

    return recur(n-1,val*x,x);
}

int main()
{
    int n = 30, x = 2;
    int t = recur(n,1,x);
    cout<<"Value of t:  "<<t<<endl;
    bool a = (INT_MAX > t), b = (INT_MIN < (-1*t));
    cout
        << "The maximum value for an int is: "<<t<<"    " << INT_MAX << "   INT_MIN: " << INT_MIN << endl
        << a << "   " << b;
    return 0;
}