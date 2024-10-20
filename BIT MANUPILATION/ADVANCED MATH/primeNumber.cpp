#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n)
{
    int cnt = 0;

    for (int i = 1; i <= sqrt(n); i++) ////////////////// TC:- O(n)
    {
        if (n % i == 0)
        {
            cnt = cnt + 1;
            if (n / i != i)
            {
                cnt = cnt + 1;
            }
        }
    }

    if (cnt == 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/////////////////////////////////////// BRUTE FORCE SOLUTION
// vector<int> AllPrimeFactors(int n)
// {
//     vector<int> ans;
//     for (int i = 2; i <= n; i++)                                          ////////////////// TC:- O(n)
//     {
//         if ((n % i) == 0)
//         {
//             // cout << "Checking for: " << i << endl;
//             if (isPrime(i) == true)                                     ////////////////// TC:- O(sqrt(n))
//             {
//                 ans.push_back(i);
//             }
//         }
//     }
//     return ans;
// }
///////////////////// TC:- O(n* sqrt(n))
///////////////////// SC:- O(1)

/////////////////////////////////////// BETTER SOLUTION
// vector<int> AllPrimeFactors(int n)
// {
//     vector<int> ans;
//     for (int i = 2; i <= sqrt(n); i++) ////////////////// TC:- O(sqrt(n))
//     {
//         if ((n % i) == 0)
//         {
//             // cout << "Checking for: " << i << endl;
//             if (isPrime(i) == true) ////////////////// TC:- O(sqrt(n))
//             {
//                 ans.push_back(i);
//             }
//             if(n/i != i)
//             {
//                 if (isPrime(n/i) == true) ////////////////// TC:- O(sqrt(n))
//                 {
//                     ans.push_back(n/i);
//                 }
//             }
//         }
//     }
//     return ans;
// }
///////////////////// TC:- O(sqrt(n)* (2*sqrt(n)))
///////////////////// SC:- O(1)

/////////////////////////////////////// BETTER SOLUTION
vector<int> AllPrimeFactors(int n)
{
    vector<int> ans;
    for (int i = 2; i <= sqrt(n); i++) ////////////////// TC:- O(sqrt(n))
    {
        if ((n % i) == 0)
        {
            // cout << "Checking for: " << i << endl;
            if (isPrime(i) == true) ////////////////// TC:- O(sqrt(n))
            {
                ans.push_back(i);
                while ((n != 1) && ((n % i) == 0))
                {
                    n = n / i;
                }
            }
        }
    }
    return ans;
}
///////////////////// TC:- O(sqrt(n)* (2*sqrt(n)))
///////////////////// SC:- O(1)

int main()
{
    vector<int> a = AllPrimeFactors(100);
    // vector<int> a = AllPrimeFactors(35);
    // cout << "Final Answer:  " << endl;
    for (auto i : a)
    {
    cout << i << endl;
    }
    // bool a = isPrime(7);
    // cout << "ans: " << a << endl;
    return 1;
}