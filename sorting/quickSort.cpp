#include <bits/stdc++.h>

using namespace std;

//             QUICK SORT

int arr[] = {10, 5, 7, 8, 2};

int len = sizeof(arr) / sizeof(arr[0]);

int partition(int arr[], int low, int high){

    int pivot = arr[low];
    int i = low;
    int j = high;

    while(i<j){
        while(arr[i] <= pivot && i<high){
            i++;
        }

        while (arr[j] > pivot&&j>low)
        {
            j--;
        }

        if(i<j){
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[j],arr[low]);
    return j;

}

void quickSort(int arr[], int low, int high){

    if(low<high){
        int mid = partition(arr, low, high);
        quickSort(arr, low, mid - 1);
        quickSort(arr, mid + 1, high);
    }
}
