#include <bits/stdc++.h>

using namespace std;

int arr[] = {0, 1, 2, 1, 2, 1, 2};

int len = sizeof(arr) / sizeof(arr[0]);

int main(){
    int temp[] = {0,0,0};
    for (int i=0; i<len; i++){
        if(arr[i] == 0){
            temp[0]+=1;
        }
        if (arr[i] == 1)
        {
            temp[1] += 1;
        }
        if (arr[i] == 2)
        {
            temp[2] += 1;
        }
    }
    int j =0;
    while(temp[0] != 0){
        arr[j] = 0;
        temp[0]-=1;
        j++;
    }
    while (temp[1] != 0)
    {
        arr[j] = 0;
        j++;
        temp[1] -= 1;
    }
    while (temp[2] != 0)
    {
        arr[j] = 0;
        j++;
        temp[2] -= 1;
    }
}