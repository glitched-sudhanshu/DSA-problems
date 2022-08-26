/*Permutation*/
//TC: O((logN)!*logN)
//SC: O(1)
/*
Try out all possible permutations of the given number if any of the permutation if power of 2 return true
*/
void next_perm(string &s)
{
    int n = s.size(), idx = 0;
    for (idx = n - 2; idx >= 0; idx--)
    {
        if (s[idx] < s[idx + 1])
            break;
    }
    if (idx < 0)
    {
        reverse(s.begin(), s.end());
    }
    else
    {
        int l = 0, k = idx;
        for (l = n - 1; l > idx; l--)
        {
            if (s[l] > s[k])
                break;
        }
        swap(s[k], s[l]);
        reverse(s.begin() + k + 1, s.end());
        return;
    }
}

bool reorderedPowerOf2(int n)
{
    if ((n & (n - 1)) == 0)
        return true;
    string orinum = to_string(n);
    string num = orinum;
    while (true)
    {
        next_perm(num);
        if (num[0] == '0')
            continue;
        int test = stoi(num);
        if ((test & (test - 1)) == 0)
            return true;
        if (num == orinum)
            break;
    }

    return false;
}


/*Count digits*/
//TC: O((logN)^2)
//SC: O(logN)
/*
We can check whether two numbers have the same digits by comparing the count of their digits. For example, 338 and 833 have the same digits because they both have exactly two 3's and one 8.

Since N could only be a power of 2 with 9 digits or less (namely, 2^0, 2^1, 2^2,... 2^29) we can just check whether NN has the same digits as any of these possibilities.
*/
vector<int> countDigits(int n)
{
    vector<int> arr(10, 0);
    while (n > 0)
    {
        arr[n % 10]++;
        n /= 10;
    }
    return arr;
}

bool reorderedPowerOf2(int n)
{
    if ((n & (n - 1)) == 0)
        return true;
    vector<int> arr = countDigits(n);
    for (int i = 0; i < 31; i++)
    {
        int num = (1 << i);
        vector<int> v = countDigits(num);
        if (v == arr)
            return true;
    }
    return false;
}


/*Sort*/
//TC: O(logN*loglogN)
//SC: O(1)
/*
Sort the given input and sort every power of 2 and check for there equality.
logN*loglogN bcz sort takes NlogN and N here is logN.
*/
bool reorderedPowerOf2(int n)
{
    if ((n & (n - 1)) == 0)
        return true;
    string num = to_string(n);
    sort(num.begin(), num.end());
    for (int i = 0; i < 31; i++)
    {
        int pownum = (1 << i);
        string pnum = to_string(pownum);
        sort(pnum.begin(), pnum.end());
        if (pnum == num)
            return true;
    }
    return false;
}