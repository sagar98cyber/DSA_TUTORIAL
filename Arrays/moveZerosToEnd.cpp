#include <bits/stdc++.h>

using namespace std;

vector<int> moveZeros(vector<int> a)
{
    // Write your code here.
    int i=0,count=0,len = a.size();
   
    cout << "DUDE:  " << a.size() << "-----" << len << endl;
    // a.erase(a.begin() + 2);

    for (i=0;i<len;i++)
    {   
        
        cout<<"DDD: ---- "<<i<<"---"<<a[i]<<endl;
        if(a[i]==0){
            count++;
            a.erase(a.begin() + i);
            len = a.size();
            --i;
        }
        // ++i;
    }

    for(int j=0;j<count;j++){
        a.pushback(0);
    }

    cout << "DUDE:  " << a.size() << "-----" << len << endl;

    return a;

}

int main(){
    vector<int> arr;
    // arr = { 4, 0, 3, 2, 5, 1 };
    // arr = { 74,0, 0, 13, 95, 36, 79  };
    arr = {7, 93, 0, 8, 15, 0, 0, 0, 0 ,0 ,26, 0, 0, 0, 43, 90 ,2 ,0, 0, 0, 58, 94, 77, 45, 59 ,19, 0, 0, 98 ,0, 0 ,0, 0, 0 ,88 ,0 ,0 ,0};
    // int len = 6;
    moveZeros(arr);
}