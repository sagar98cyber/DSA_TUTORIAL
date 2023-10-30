// 100102. Minimum Equal Sum of Two Arrays After Replacing Zeros

// You are given two arrays nums1 and nums2 consisting of positive integers.

//     You have to replace all the 0's in both arrays with strictly positive integers such that the sum of elements of both arrays becomes equal.

//     Return the minimum equal sum you can obtain,
//     or -1 if it is impossible.

#include <bits/stdc++.h>

using namespace std;

long long minSum(vector<int> &nums1, vector<int> &nums2)
{

    int i = 0, len1 = nums1.size(), len2 = nums2.size();
    int sum1 = 0, sum2 = 0;
    int countZero1 = 0, countZero2 = 0;

    for (; i < len1; i++)
    {
        sum1 += nums1[i];
        if (nums1[i] == 0)
        {
            ++countZero1;
        }
    }

    for (i = 0; i < len1; i++)
    {
        sum2 += nums2[i];
        if (nums2[i] == 0)
        {
            ++countZero2;
        }
    }

    bool maxSum;

    if (sum1 > sum2)
    {
        maxSum = true;
    }
    else
    {
        maxSum = false;
    }

    if (maxSum)
    {
        for (i = 0; i < len1; i++)
        {
            // sum1 += nums1[i];
            if (nums1[i] == 0)
            {
                nums1[i] = 1 ;
                ++sum1;
                --countZero1;
            }
        }
    }

    else
    {
        for (i = 0; i < len2; i++)
        {
            // sum1 += nums1[i];
            if (nums2[i] == 0)
            {
                nums2[i] = 1;
                ++sum2;
                --countZero2;
            }
        }
    }

    int diff = maxSum ? (sum1 - sum2) : (sum2 - sum1);

    if (diff == 1 && countZero1 == 0 && countZero2 > 1)
    {
        return -1;
    }

    if (diff == 1 && countZero2 == 0 && countZero1 > 1)
    {
        return -1;
    }

    if (countZero1 == 0)
    {
        int temp = diff - (countZero2 - 1);
        i = 0;
        while (nums1[i] != 0 && i < len1)
        {
            ++i;
        }
        nums1[i] = temp;
        while (i < len1)
        {
            if (nums1[i] == 0)
            {
                nums1[i] = 1;
            }
        }
    }
    else
    {
        int temp = diff - (countZero1 - 1);
        // int temp = diff - (countZero2-1);
        i = 0;
        while (nums2[i] != 0 && i < len2)
        {
            ++i;
        }
        nums2[i] = temp;
        while (i < len1)
        {
            if (nums2[i] == 0)
            {
                nums2[i] = 1;
            }
        }
    }
    if (maxSum)
    {
        return sum1;
    }
    else
    {
        return sum2;
    }
}




int main(){

    vector<int> nums1 =  { 3, 2, 0, 1, 0 };vector<int> nums2 =  { 6, 5, 0 } ;

    int result = minSum(nums1, nums2);

    cout<<"Returned Value: "<<result<<endl;
}