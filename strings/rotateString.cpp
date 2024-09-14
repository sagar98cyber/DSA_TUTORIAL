#include <bits/stdc++.h>
// #include <string.h>
using namespace std;


    bool solve(queue<int> queOne, queue<int> queTwo, int size)
    {
        while (size--)
        {
            // cout << "Front:  " << char(queTwo.front()) << "   Back:  " << char(queTwo.back()) << "   Length:  " << size << endl;
            int front = queTwo.front();
            queTwo.pop();
            queTwo.push(front);
            
            if (queOne == queTwo)
            {
                // cout<<endl<<endl;
                // while (!queTwo.empty())
                // {
                //     cout << char(queTwo.front()) << " ";
                //     queTwo.pop();
                // }
                return true;
            }
        }
        return false;
    }

    bool rotateString(string s, string goal)
    {
        queue<int> queOne;
        queue<int> queTwo;
        if (s.size() != goal.size())
        {
            return false;
        }
        for (int i = 0; i < s.size(); i++)
        {
            queOne.push(s[i]);
        }
        for (int i = 0; i < goal.size(); i++)
        {
            queTwo.push(goal[i]);
        }
        int size = goal.size();
        return solve(queOne, queTwo, size);
    }

    int main()
    {
        string s = "abcde", goal = "cdeab";

        // cout << "Answer:  " << rotateString(s, goal);
}