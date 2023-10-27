#include<bits/stdc++.h>
#include<string.h>
using namespace std;

string reverseString(string &s)
{
    string ans = "", word = "";
    int i = 0, len = s.size();
    // vector<string> tempString;    
    s+=" ";   
    while (i < len)
    {
        word = "";

        if (!isspace(s[i]) && i < len)
        {
            int start = i,end=i;
            while (!isspace(s[i])&&i<len)
            {
                // word = word + s[i];
                ++i;
                ++end;
            } 
            // cout << "Word:---" << word << "---" << ans << endl;
            ans = s.substr(start,(end-start)+1)+ans;
        }
        else
        {
            while (isspace(s[i]) && i < len)
            {
                ++i;
            }
            // if(i!=len-1){
            //     ans = " " + ans;
            // }
            // cout << "Else-Word:---" << word << "---" << ans << endl;
        }
    }
    return ans;
}

int main(){
    string test = "Welcome   to Coding Ninjas";
    string result = reverseString(test);
    cout<<"------result--"<<result;
}