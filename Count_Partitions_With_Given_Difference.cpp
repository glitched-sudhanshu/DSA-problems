/*
s1 + s2 = tot
s1 - s2 = d
s1 - (tot - s1) = d
2s1 - tot = d
s1 = (tot-d)/2
so we simply have to count subsets with given sum
//corner case:
tot-d >= 0
tot-d should be even

to now the question is exactly same as number_of_subsets

//https://www.codingninjas.com/codestudio/problems/partitions-with-given-difference_3751628

*/

int mod = 1e9 + 7;

int findWays(vector<int> &num, int tar)
{
    // Write your code here.
    int n = num.size();
    vector<int> prev(tar + 1, 0);
    vector<int> cur(tar + 1, 0);
    if (num[0] == 0)
        prev[0] = cur[0] = 2;
    else
        prev[0] = cur[0] = 1;
    if (num[0] <= tar && num[0] != 0)
        prev[num[0]] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= tar; j++)
        {
            int pick = 0;
            if (num[i] <= j)
                pick = prev[j - num[i]];
            int notPick = prev[j];
            cur[j] = (pick + notPick) % mod;
        }
        prev = cur;
    }
    return prev[tar] % mod;
}

int countPartitions(int n, int d, vector<int> &arr)
{
    // Write your code here.
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    if ((sum + d) % 2 != 0)
        return 0;
    return findWays(arr, (sum + d) / 2);
}