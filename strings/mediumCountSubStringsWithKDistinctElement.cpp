#include <bits/stdc++.h>

using namespace std;

// the number of subarrays with at most K distinct elements
int countSubStrings(string s, int k)
{
    // Write your code here.
    int n;
    long long int ans = 0;
    
    n = s.size();
    vector<int> a(26, 0);
    vector<int> last(26, INT_MAX);

    //------- i is the iterator
    //------- disCnt is the count of distinct elements
    //------- left is the 'left' pointer used to remove elements and their counts
    //------- The following solution has a time complexity of O(n) rather than O(n^2) solution of GFG

    for (int i = 0, disCnt = 0, left = 0; i < n; i++)
    {
        int c = s[i] - 'a';
        cout<<"s[i]:  "<<s[i]<<"  c: "<<c<<endl;
        // Storing the last index of the current element.
        last[c] = i;

        // If the character is encountered for the first time then increase the distinctElementCounter

        if (a[c] == 0)
        {
            disCnt++;
        }

        // increase the frequency counter
        a[c]++;

        // removing the elements from behind to get the counter of distinctElements equal to k 
        while (disCnt > k)
        {
            int x = s[left++] - 'a';
            // ------ would have definitely missed this EDGE CASE
            if (a[x] == 1)
                {
                    disCnt--;
                    last[x] = INT_MAX;
                }
            
            a[x]--;
        }


        int r = i;

        for (int o = 0; o < 26; o++)
        {
            r = min(r, last[o]);
        }

            // cout << "1. The value of r:  " << r << "   i: " << i << "   Left:  " << left << "    ans: " << ans <<"    String in consideration:  "<< s.substr(left,i-left)<< endl;

        if (disCnt == k)
        {
            ans += (long long int)(r - left + 1);    
        }
            // cout << "-----------------------   The value of r:  " << r << "   i: " << i << "   Left:  " << left << "    ans: " << ans << endl;
    }
    // cout << ans ;
    return ans;
}

// Driver Program
int main()
{
    string s1 = "aacfssa";
    int k = 3;
    // string s1 = "aacaaaaaaaa";
    // int k = 1;
    cout << "Total substrings with exactly " << k
         << " distinct characters : "
         << countSubStrings(s1, k) << endl;

    // string s2 = "aabab";
    // int k = 2;
    // cout << "Total substrings with exactly " << k
    //      << " distinct characters : "
    //      << countSubStrings(s2, k) << endl;
}
