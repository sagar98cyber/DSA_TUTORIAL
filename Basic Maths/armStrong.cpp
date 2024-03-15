#include <bits/stdc++.h>
using namespace std;
bool ArmstrongNumber(int n)
{
    int OGNo = n;
    int count = 0;
    int temp = n;
    while (temp != 0)
    {
        count++;
        temp = temp / 10;
    }
    int sumOfRaiseTo = 0;
    while (n != 0)
    {
        int digit = n % 10;
        sumOfRaiseTo += pow(digit, count);
        n /= 10;
    }
    return (sumOfRaiseTo == OGNo);
}
int main()
{
    int n1 = 153;
    if (ArmstrongNumber(n1))
    {
        cout << "Yes, it is an Armstrong Number\n";
    }
    else
    {
        cout << "No, it is not an Armstrong Number\n";
    }
    return 0;
}