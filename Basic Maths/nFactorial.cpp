#include <bits/stdc++.h>

using namespace std;

void factorial(int& n, int& finalRes){
    if (n <= 1)
    {
        return;
    }
    finalRes=n*finalRes;
    n--;
    factorial(n,finalRes);
}

int main(){
    int n =3,finalResult=1;
    factorial(n,finalResult);
    cout << "Dude: " << finalResult; 
}