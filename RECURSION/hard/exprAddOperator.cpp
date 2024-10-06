#include <bits/stdc++.h>
using namespace std;

int res(stack<char> &optr, stack<int> &oprd)
{
    cout << "Called the RES FUNCTION!" << endl;
    if (optr.empty())
    {
        int t = oprd.top();
        oprd.pop();
        return t;
    }

    int t1 = oprd.top();
    char c = optr.top();
    oprd.pop();
    optr.pop();

    if (c == '+')
    {
        return t1 + res(optr, oprd);
    }
    return res(optr, oprd) - t1;
}

void eval(string exp, vector<string> &ans, int target)
{
    cout << "Came here to evalute:  " << exp << endl;
    stack<int> oprd;
    stack<char> optr;
    int i = 0;
    bool flag = true;

    while (i < exp.length())
    {
        // if (flag)
        // {
        //     oprd.push(exp[i] - '0');
        // }
        // else
        // {
        //     if (exp[i] != '*')
        //     {
        //         optr.push(exp[i]);
        //     }
        //     else
        //     {
        //         int t1 = oprd.top();
        //         oprd.pop();
        //         int t2 = exp[i + 1];
        //         i++;
        //         flag = !flag;
        //         oprd.push(t1 * t2);
        //     }
        // }
        // i++;
        // flag = !flag;
        if (exp[i] >= 48 && exp[i] <= 57)
        {
            oprd.push(exp[i] - '0');
            i++;
            continue;
        }
        else if (exp[i] == '*')
        {
            int t1 = oprd.top();
            int t2 = exp[i + 1] - '0';
            oprd.pop();
            oprd.push(t1 * t2);
            i = i + 2;
            continue;
        }
        else
        {
            optr.push(exp[i]);
            i++;
            continue;
        }
    }

    int temp = res(optr, oprd);
    if (target == temp)
    {
        ans.push_back(exp);
    }
}

void create(string num, string exp, int i, vector<string> &ans, int target, vector<char> &opr)
{
    if (i == num.length())
    {
        // cout << "String created:" << exp << endl;
        eval(exp, ans, target);
        return;
    }

    for (int j = 0; j < opr.size(); j++)
    {
        create(num, exp + opr[j] + num[i], i + 1, ans, target, opr);
    }
}

vector<string> addOperators(string num, int target)
{
    vector<char> opr = {'*', '+', '-'};
    vector<string> ans;
    string temp(1, num[0]);
    cout << temp << endl;
    create(num, temp, 1, ans, target, opr);
    return ans;
}

int main()
{
    // string num = "123";
    // int target = 6;
    // string num = "232";
    // int target = 8;
    string num = "105";
    int target = 5;

    vector<string> ans = addOperators(num, target);
    for (auto i : ans)
    {
        cout << "Ans: " << i << endl;
    }
    return 0;
}