#include <bits/stdc++.h>

using namespace std;
int temp1 = 1, temp2=1;
///////  Nth Fibonacci Number 
void fiboSeries(int &n, int &fibo)
{
    if (n == 2)
    {   
        return;
    }
    cout << "In Recurssion: " << fibo << "---" << temp1 << "---" << temp2 << "---" << n << endl;
    fibo = temp1+temp2;
    temp1 = temp2;
    temp2=fibo;
    n--;
    fiboSeries(n, fibo);
}

int main()
{
    int n = 9, fibo = 1;
    if(n>2){
        fiboSeries(n, fibo);
    }
    else if(n==2 || n==1){
        fibo = 1;
    }
    else{
        fibo =0;
    }
    cout << "Dude: " << fibo << endl;
}




//////    PRINTING ENTIRE SERIES


// int fib(int n)
// {
//     if (n <= 1)
//         return n;
//     return fib(n - 1) + fib(n - 2);
// }
// int main()
// {
//     int n = 5, i;
//     for (i = 0; i < n; i++)
//         cout << fib(i) << " ";
//     return 0;
// }