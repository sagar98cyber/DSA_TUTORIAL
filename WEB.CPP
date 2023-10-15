#include <bits/stdc++.h>

using namespace std;

// void myFunction(int myNumbers[2])
// {
//   for (int i = 0; i < 5; i++)
//   {
//     cout << myNumbers[i] << "\n";
//   }
// }

// int main()
// {
//   int myNumbers[5] = {10, 20, 30, 40, 50};
//   myFunction(myNumbers);
//   return 0;
// }

// int partitionArray(int input[], int start, int end)
// {
//   // Write your code here

//   int pivot = input[start];
//   int pivotLoc = start;

//   if (start >= end)
//   {
//     return 0;
//   }

//   // cout << "Start:" << start << "  "
//       //  << "End: " << end << "  "
//       //  << " Pivot: " << pivot << "  "
//       //  << "Input of Pivot" << input[pivot] << endl;

//   // for(int i=start+1;i<=end;i++){
//   // 	// if(pivot<=input[i]){
//   // 	// 	int temp = input[i];
//   // 	// 	input[i]=pivot;
//   // 	// 	input[pivotLoc-1] = temp;
//   // 	// 	pivotLoc = i;
//   // 	// }
//   // 	// else{
//   // 	// 	int temp = input[i];
//   // 	// 	input[i]=pivot;
//   // 	// 	input[pivotLoc+1] = temp;
//   // 	// 	pivotLoc = i;
//   // 	// }
//   // 	cout<<"In the Loop: "<<" "<<"Element: "<<input[i]<<" "<<endl;
//   // }
//   cout << "Before left Loop:" << "Start: " << start<<" " <<"End: " <<pivotLoc-1<< " " << endl;
//   partitionArray(input, start, pivotLoc - 1);
//   cout << "After left Loop:"
//        << "Start: " << start << " "
//        << "End: " << pivotLoc + 1 << " " << endl<<endl;
//   partitionArray(input, pivotLoc + 1, end);
// }

// void quickSort(int input[], int start, int end)
// {
//   /*
//     Don't write main().
//     Don't read input, it is passed as function argument.
//     Change in the given array itself.
//     Taking input and printing output is handled automatically.
//   */
//   partitionArray(input, start, end);
// }

// int main(){
//   int arr[6] = {
//     3,4,4,5,6,8
//   };
//   quickSort(arr,0,6);
//   return 0;
// }
