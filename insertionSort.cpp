#include <bits/stdc++.h>

using namespace std;

//        INSERTION SORT

int main()
      {
      for (int i =0;i<len;i++){
          int j=i;
          while(j>0&&arr[j]<arr[j-1]){
            swap(arr[j], arr[j - 1]);
            j--;
          }

      }

      for (const auto &var : arr)
          {
            cout <<"     Okay: "<< var;
          }
      }
