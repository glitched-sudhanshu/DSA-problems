/*Recursion*/
// TC: O(2^n)
// SC: O(N)
bool help(vector<int> &arr, int n, int s)
{
    if (s == 0)
        return true;
    if (n == 0)
        return (arr[n] == s);

    bool notTake = help(arr, n - 1, s);
    bool take = false;
    if (arr[n] <= s)
        take = help(arr, n - 1, s - arr[n]);
    return take | notTake;
}

bool canPartition(vector<int> &arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    int k = sum / 2;

    vector<vector<int>> dp(n, vector<int>(k + 1, -1));

    if (sum % 2 != 0)
        return false;
    else
    {
        if (help(arr, n - 1, k))
            return true;
    }
    return false;
}

/*Memoization*/
// TC : O(N*K)
// SC: O(N*K) + O(N)
bool help(vector<int> &arr, int n, int s, vector<vector<int>> &dp)
{
    if (s == 0)
        return true;
    if (n == 0)
        return (arr[n] == s);

    if (dp[n][s] != -1)
        return dp[n][s];

    bool notTake = help(arr, n - 1, s, dp);
    bool take = false;
    if (arr[n] <= s)
        take = help(arr, n - 1, s - arr[n], dp);
    return dp[n][s] = take | notTake;
}

bool canPartition(vector<int> &arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    int k = sum / 2;

    vector<vector<int>> dp(n, vector<int>(k + 1, -1));

    if (sum % 2 != 0)
        return false;
    else
    {
        if (help(arr, n - 1, k, dp))
            return true;
    }
    return false;
}

/*Space optimize - 1D*/
// TC : O(N*K)
// SC: O(K)
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<bool> prev(k + 1, 0);
    vector<bool> cur(k + 1, 0);

    prev[0] = cur[0] = true;
    prev[arr[0]] = true;

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            bool notTake = prev[j];
            bool take = false;
            if (arr[i] <= j)
                take = prev[j - arr[i]];
            cur[j] = take | notTake;
        }
        prev = cur;
    }
    return prev[k];
}

bool canPartition(vector<int> &arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    int k = sum / 2;

    if (sum % 2 != 0)
        return false;
    else
    {
        if (subsetSumToK(n, k, arr))
            return true;
    }
    return false;
}

// https://www.codingninjas.com/codestudio/problems/partition-equal-subset-sum_892980?