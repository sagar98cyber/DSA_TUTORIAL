#include <bits/stdc++.h>

using namespace std;

// int arr[] = {1, 2, 3, 9, 7, 8, 6, 10};
// int arr[] = {1,3,6,5,2,8,10};

// int main()
// {
//     int begin=0, end=0;
//     bool flag=false;
//     int index =1;
//     int len = sizeof(arr) / sizeof(arr[0]);

//     while(index<len){
//         // cout<<"Dude: "<<arr[index]<<"-----"<<index<<endl;

//         if (arr[index] < arr[index-1])
//         {

//             cout<<"NotSorted: "<<index-1<<endl;
//             if(flag==false){
//                 begin = index-1;
//                 flag = true;
//             }
//             else{
//                 end = index;
//             }
//         }
//         index++;
//     }

//     cout << "Dude: " << begin << "-----" << end << endl;

//     return 0;
// }




// vector<int> nums = {2, 6, 4, 8, 10, 9, 15};
vector<int> nums = {1, 3, 4, 6, 2, 8, 10, 9, 15};

int main()
{
    int begin = 0, end = 0;
    bool flag = false;
    int index = 1;
    int len = nums.size();
    int lowest = nums[len - 1];
    while (index < len)
    {
        // cout<<"Dude: "<<arr[index]<<"-----"<<index<<endl;
        if (nums[index] < lowest)
        {
            lowest = nums[index];
        }

        if (nums[index - 1] > nums[index])
        {
            if (flag != true)
            {
                begin = index - 1;
                flag = true;
            }
            else
            {
                end = index;
            }
        }
        index++;
    }
    if (nums[begin-1] > lowest)
    {
        // cout << "Cutting begin --- Lowest: " << lowest << "  ---- Begin:" << begin << "  ---" << " Nums of Begin: " << nums[begin] << endl;
        --begin;
    }

    cout << "Dude: " << begin << "-----" << end <<"------------" << (end-begin)+1 << endl;
}