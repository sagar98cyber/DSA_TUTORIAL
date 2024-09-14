#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int compress(vector<char> &chars)
{
    if (chars.size() <= 1)
        return 1;
    int index = 0;
    int num = 1;
    for (int i = 1; i < chars.size(); i++)
    {
        if (chars[i] == chars[i - 1])
            num++;
        else if ((chars[i] != chars[i - 1]) || (i == chars.size() - 1))
        {
            if (num == 1)
            {
                chars[index] = chars[i - 1];
                index++;
            }
            else
            {
                chars[index] = chars[i - 1];
                index++;
                string s = to_string(num);
                for (char ch : s)
                {
                    chars[index] = ch;
                    index++;
                }
                num = 1;
            }
        }
        for (int a = 0; a < chars.size(); a++)
        {
            cout << chars[a];
        }
        cout << endl;
    }
    // Process the last set of characters
    chars[index++] = chars.back();
    if (num > 1)
    {
        string s = to_string(num);
        for (char ch : s)
        {
            chars[index++] = ch;
            
        }
        for (int a = 0; a < chars.size(); a++)
        {
            cout << chars[a];
        }
        cout << endl;
    }
    return index;
}

int main()
{
    vector<char> c{
        'a',
        'b',
        'b',
        'b',
        'b',
        'b',
        'b',
        'b',
        'b',
        'b',
    };
    compress(c);
    return 1;
}