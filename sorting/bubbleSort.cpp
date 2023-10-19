#include <bits/stdc++.h>

using namespace std;

int arr[] = {10, 5, 7, 8, 2};

int len = sizeof(arr) / sizeof(arr[0]);

//         BUBBLE SORT
int main()
{
for (int i =0;i<len-1;i++){
  for(int j=0;j<(len-i-1);j++){
        if(arr[j]>arr[j+1]){
          swap(arr[j], arr[j + 1]);
        }
  }
}

for (const auto &var : arr)
    {
      cout <<"     Okay: "<< var;
    }
}
