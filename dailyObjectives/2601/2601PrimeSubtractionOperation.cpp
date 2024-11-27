#include <bits/stdc++.h>

using namespace std;

/*
int BSOnASet(int target, vector<int> &nums)
{
    int n = nums.size();
    int low = 0, high = n - 1, mid = -1;

    while (low <= high)
    {
        mid = (high + low) / 2;

        if (nums[mid] <= target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return mid;
}

void getAllPrime(vector<int> &prime, int limit)
{
    vector<int> temp(limit + 1, 1);
    for (int i = 2; i <= limit; i++)
    {
        if (temp[i] == 1)
        {
            prime.push_back(i);
            for (int j = i + i; j <= limit; j += i)
            {
                temp[j] = -1;
            }
        }
    }
    // // cout << endl
    //      << endl;
}

int findTheGreatestOfAllElements(vector<int> &nums)
{
    int mx = -1;
    for (auto i : nums)
    {
        mx = max(mx, i);
    }
    return mx;
}

bool primeSubOperation(vector<int> &nums)
{
    vector<int> primes;
    int n = nums.size(), greatest; //= findTheGreatestOfAllElement(nums);
    greatest = nums[1];
    // // cout << "GReatest:  " << greatest << endl;
    getAllPrime(primes, greatest);
    for (auto i : primes)
    {
        cout << i << "  ";
    }
    int x = 0;
    cout << endl;
    for (auto i : primes)
    {
        cout << x << "  ";
        x++;
    }
    cout << endl;
    for (int i = 0; (i < n); i++)
    {
        int index = BSOnASet(nums[i], primes);
        cout << "nums of i:  " << i << " response index: " << index << "  Primes of index:  " << primes[index] << endl;
        if ((i == 0))
        {
            cout << "Nums of zero:  " << nums[0] << endl;
            nums[i] -= primes[index];
            cout << "Nums of zero:  " << nums[0] << "  Prime of index:  " << primes[index] << endl;
        }

        if ((i != 0) && ((nums[i] - primes[index]) > nums[i - 1]))
        {

            nums[i] -= primes[index];
            cout << "came inside second if!   i:  " << i << "   " << nums[i] << endl;
        }
        else
        {
            int j = index;
            while (j >= 0)
            {
                if ((nums[i] - primes[j]) < nums[i - 1])
                {
                    j++;
                    break;
                }
                j--;
            }
            nums[i] -= primes[j];
        }

        if ((i != 0) && (nums[i] <= nums[i - 1]))
        {
            cout << "Returning at index: " << i << "  " << nums[i] << "  Index-1: " << i - 1 << "  " << nums[i - 1] << endl;
            return false;
        }
    }

    return true;
}

*/

bool is_prime(const int &k)
{
    if (k == 1 or k == 2)
        return k - 1;
    for (int i = 2; i * i <= k; i++)
        if (k % i == 0)
            return false;
    return true;
}

int largest_prime(const int &k)
{
    int prime = 0;
    if (k <= 1)
        return prime;
    static set<int, greater<int>> st;
    st.insert(2);
    st.insert(3);
    st.insert(5);
    st.insert(7);
    st.insert(11);
    auto itr = st.upper_bound(k);
    if (itr != st.end())
        prime = *itr;
    cout << "upper_bound for " << k << " is: " << prime << endl;
    for (int i = k - 1; i > prime; i--)
        if (is_prime(i))
        {
            st.insert(i);
            prime = i;
            break;
        }
    return prime;
}

bool primeSubOperation(vector<int> &nums)
{
    int prev = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        cout << endl
             << nums[i] - prev << endl;
        int prime = largest_prime(nums[i] - prev);
        cout << nums[i] << "-" << prime << "=";
        nums[i] -= prime;
        cout << nums[i] << endl;
        if (nums[i] <= prev)
            return false;
        prev = nums[i];
    }
    return true;
}

int main()
{
    vector<int> nums;
    nums = {4, 9, 6, 10};
    // nums = {5, 8, 3};
    // nums = {2, 2};

    for (auto i : nums)
    {
        cout << i << "  ";
    }
    cout << endl
         << endl
         << endl;
    bool res = primeSubOperation(nums);
    cout << "Response:  " << res << endl;
    return 1;
}