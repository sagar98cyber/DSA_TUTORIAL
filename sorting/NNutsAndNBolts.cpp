////     N Nuts and N bolts. Every nut is distinct in size and every bolt is distinct in size. Every Nut has a corresponding BOLT. You cannot compare between the size of 2 nuts and 2 bolts. You can compare a nut and a bolt. Sort the nuts and bolts in increasing order of size (QUICK SORT) - Q

#include <bits/stdc++.h>

using namespace std;

// int nuts[] = {5, 6, 1, 2, 9, 3};
// int bolts[] = {2, 6, 5, 1, 3, 9};


int partition(int low, int high, vector<string> &arr, string pivot1)
{
    int i = low, j = high;
    int location =0;
    for(int x = low;x<=high;x++){
        if(arr[x] == pivot1){
            location = x;
            break;
        }
    }

    int pivot = stoi(pivot1);

    // find the smaller than the pivot from the j and higher than the pivot from i and swap
    while (i < j)
    {
        while (stoi(arr[i]) <= pivot && i < high )
        {
            i++;
        }

        while (stoi(arr[j]) > pivot && j > low)
        {
            j--;
        }

        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }

    // return Mid by swapping the mid element with the nuts[j] and nuts[low]
    swap(arr[location], arr[j]);
    // cout << "Before returning:  " << arr[j] << endl ;  //<< endl;
    return j;
}

void quickSort(int low, int high, vector<string> &nuts, vector<string> &bolts, int n)
{

    if (low < high)
    {

        // find Mid
        // cout << "Bolts[low]:  That is partitioning nuts" << endl; //<< bolts[low] << " Nuts[mid] " << nuts[mid] << endl;
        int pivot = partition(low, high, nuts, bolts[low]);
        // for (int i = 0; i < n; i++)
        // {
        //     cout << nuts[i] << "  ";
        // }
        // cout << "End Bolts[low]:  That is partitioning nuts" << endl << endl;
        // cout << "Bolts[low]:  " << bolts[low] << " Nuts[mid] " << nuts[mid] << endl << endl;
        // cout << "Nuts[mid]:  That is partitioning bolts" << endl;
        partition(low, high, bolts, nuts[pivot]);
        // for (int i = 0; i < n; i++)
        // {
        //     cout << bolts[i] << "  ";
        // }
        // cout << "End Bolts[low]:  That is partitioning nuts" << endl;
        // call quick sort for low -> mid-1 and mid+1 -> high
        quickSort(low, pivot - 1, nuts, bolts, n);
        quickSort(pivot + 1, high, nuts, bolts, n);
    }
}

int main(){
    // vector<string> nuts = {"12", "10", "4", "6", "3"};
    // vector<string> bolts = {"10", "4", "3", "6", "12"};
    vector<string> nuts = {"12", "10", "4", "6", "3"};
    vector<string> bolts = {"3", "6", "4", "10", "12"};

    // int len = sizeof(nuts) / sizeof(nuts[0]);
    int len = nuts.size();
    // cout<<len<<endl;
    // for (int i = 0; i < len; i++)
    // {
    //     cout << nuts[i] << "  ";
    // }
    
    quickSort(0,len-1, nuts, bolts, len);

    cout << endl
         << endl
         << "Nuts: " << endl
         << endl;
    for (int i=0;i<len;i++)
    {
        cout<<nuts[i]<<" " << bolts[i]<<endl;
    }
}