#include <bits/stdc++.h>

using namespace std;

//      SELECTION SORT

int arr[] = {10,6,2,5,7,1,6};
int arr[] = {9, 4, 7, 6, 3, 1, 5};
int main(){

int len = sizeof(arr) / sizeof(arr[0]);
  int minElem;
  for(int i=0;i<len-1;i++){
    // cout<<"Starting the main :Loop:"<<endl;
    minElem = i;
    for(int j = i;j<len;j++){
      if(arr[minElem]>arr[j]){
        minElem = j;
      }
      // cout << "Starting the inner :Loop:"<<arr[j] << endl;
    }
    cout << "Before Swapping:  " << arr[i]<< "----" << arr[minElem]<<endl;

    swap(arr[i], arr[minElem]);
    for (const auto &var : arr)
    {
      cout << "," << var << ",    ";
    }
    cout << endl;
  }
}
