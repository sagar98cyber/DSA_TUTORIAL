#include <bits/stdc++.h>

using namespace std;

int arr[] = {1, 2, 3, 9, 7, 8, 6, 10};

int main(){
    int begin=0, end=0;
    bool flag=false;
    int index =1;
    int len = sizeof(arr) / sizeof(arr[0]);

    while(index<len){
        // cout<<"Dude: "<<arr[index]<<"-----"<<index<<endl;
        
        if (arr[index] < arr[index-1])
        {   

            cout<<"NotSorted: "<<index-1<<endl;
            if(flag==false){
                begin = index-1;
                flag = true;
            }
            else{
                end = index;
            }
        }
        index++;
    }

    cout << "Dude: " << begin << "-----" << end << endl;

    return 0;
}