#include <bits/stdc++.h>
using namespace std;

/*
n=36
i = 2

1 2 3 4 6 9 12 18
*/
int findSumOfAllDivisorsOfNumber(int n)
{
    int sum = 0;
    for (int i = 1; i <= sqrt(n); i++)
        if (n % i == 0)
        {
            sum += i;
            if (i != n / i)
                sum += (n / i);
        }

    // cout<<"\n"<<endl;
    return sum;
}

int sumOfAllDivisors(int num)
{
    // Write your code here.

    int sumOfDivsor = 0;
    for (int j = 1; j <= num; j++)
    {
        int sum = findSumOfAllDivisorsOfNumber(j);
        sumOfDivsor = sumOfDivsor + sum;
    }
    return sumOfDivsor;
}

int main()
{
    cout << "LELELE : " << sumOfAllDivisors(5) << endl;
    return 0;
}