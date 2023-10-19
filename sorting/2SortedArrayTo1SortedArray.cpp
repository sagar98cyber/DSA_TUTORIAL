#include <bits/stdc++.h>

using namespace std;

// Given 2 sorted arrays merge and create a new sorted vector - Q

int main(){
  vector<int> finalArr;

  int arr1[] = {5, 4, 3, 2};
  int len1 = sizeof(arr1) / sizeof(arr1[0]);

  int arr2[] = {15, 10, 8, 6, 1};
  int len2 = sizeof(arr2) / sizeof(arr2[0]);

  //    FOR ASCENDING
/*
    int ansIndex = 0, right = 0, left = 0;

    while (left < len1 && right < len2)
    {
      if (arr1[left]<arr2[right]){
        finalArr.push_back(arr1[left]);
        left++;
      }
      else{
        finalArr.push_back(arr2[right]);
        right++;
      }
    }

    while (left < len1){
      finalArr.push_back(arr1[left]);
      left++;
    }

    while (right < len2)
    {
      finalArr.push_back(arr2[right]);
      right++;
    }

  */

  // for DESCENDING
  /*
    int  right = len2-1, left = len1-1;

    while (left >= 0 && right >= 0)
    {
      if (arr1[left] < arr2[right])
      {
        finalArr.push_back(arr1[left]);
        left--;
      }
      else
      {
        finalArr.push_back(arr2[right]);
        right--;
      }
    }

    while (left >= 0)
    {
      finalArr.push_back(arr1[left]);
      left--;
    }

    while (right >= 0)
    {
      finalArr.push_back(arr2[right]);
      right--;
    }
  */

  for(const auto &s : finalArr){
    cout<<s<<",  ";
  }

  return 0;
}
