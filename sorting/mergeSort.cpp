#include <bits/stdc++.h>

using namespace std;

int arr[] = {10, 5, 7, 8, 2};

int len = sizeof(arr) / sizeof(arr[0]);

//        MERGE SORT

void merge(int arr[], int low, int mid, int high)
{

  vector<int> temp;

  int left = low;
  int right = mid + 1;

  // std::cout << "The Next Low 1:  " << low << "  and high:  " << mid << endl;
  // std::cout << "The Next Low 2:  " << mid + 1 << "  and high:  " << high << endl;

  while (left <= mid && right <= high)
  {
    if (arr[left] <= arr[right])
    {
      // cout << "Adding to the temp:" << arr[i] << endl;
      temp.push_back(arr[left]);
      left++;
    }
    else
    {
      // cout << "Adding to the temp:" << arr[j] << endl;
      temp.push_back(arr[right]);
      right++;
    }
  }

  while (left <= mid)
  {
    /* code */
    temp.push_back(arr[left]);
    left++;
  }

  while (right <= high)
  {
    /* code */
    temp.push_back(arr[right]);
    right++;
  }

  for (int i = low; i <= high; i++)
  {
    arr[i] = temp[i - low];
  }
}

void mergeSort(int arr[], int low, int high)
{

  int mid = (high + low) / 2;

  /////////////////  ONLY WAY TO CALCULATE THE MID

  //   int mid = (((high-low)/2)+low);

  if (low >= high)
  {
    return;
  }

  /*
  5
  LOW = 0, HIGH = 4
  MID = 2

  LOW = 0 , HIGH = 2         LOW = 3   HIGH = 4
  MID = 1                    MID = ((4-3)/2)+3
  */

  // cout<<"The Current Low:  "<<low<<"  and high:  "<<high<<endl;
  // cout << "The Next Low 1:  " << low << "  and high:  " << mid << endl;
  // cout << "The Next Low 2:  " << mid+1 << "  and high:  " << high << endl;

  mergeSort(arr, low, mid);
  mergeSort(arr, mid + 1, high);
  merge(arr, low, mid, high);
}

int main()
{
  // cout<<"-----"<<len;
  mergeSort(arr, 0, (len - 1));

  for (int i = 0; i < len; i++)
  {
    cout << arr[i] << ",    ";
  }

  return 0;
}
