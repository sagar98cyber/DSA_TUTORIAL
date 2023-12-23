#include <bits/stdc++.h>

using namespace std;

// int arr[] = {3,4,5,2,6,2,3,8};       ///
int arr[] = {48, 96, 46, 75, 71, 5, 58, 57};
int n = 8;

map<int,int> m;

int main(){
    int i =0;
    while(i<n){
        // cout<<"Dude: "<<arr[i]<<endl;
        int test = arr[i];
        if (m.find(test) != m.end())
        {
            m[test] +=1;
        }
        else{
            m.insert({test,1});
        }
        i++;
    }

    auto itr = m.begin();
    itr++;
    cout << itr->first << '\t' << itr->second << '\n';

    itr = m.end();
    itr--;itr--;
    cout << itr->first << '\t' << itr->second << '\n';

    

}