#include <bits/stdc++.h>

using namespace std;

// int arr[] = {10, 5, 7, 8, 2};
int arr[] = {1,2};
int invCount=0;


//        MERGE SORT

int merge(int arr[], int low, int mid, int high)
{

    vector<int> temp;

    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
            invCount++;
        }
    }
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
    return invCount;
}

int mergeSort(int arr[], int low, int high)
{

    /////////////////  ONLY WAY TO CALCULATE THE MID

    int mid = (((high-low)/2)+low);

    if (low >= high)
    {
        return 0;
    }

    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

int main()
{
    // int invCount = 0;
    int len = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, (len - 1));

    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << ",    ";
    }

    cout<<endl<<"Inversion count: "<<invCount<<endl;

    return invCount;
}