/*Recursion*/
// TC: O(2^n)
// SC: O(N)
bool help(vector<int> &arr, int n, int t)
{
    if (t == 0)
        return true;
    if (n == 0)
        return (arr[0] == t);

    bool notTake = help(arr, n - 1, t);
    bool take = false;
    if (arr[n] <= t)
        take = help(arr, n - 1, t - arr[n]);

    return take | notTake;
}

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    return help(arr, n - 1, k, dp);
}

/*Memoization*/
// TC : O(N*K)
// SC: O(N*K) + O(N)
bool help(vector<int> &arr, int n, int t, vector<vector<int>> &dp)
{
    if (t == 0)
        return true;
    if (n == 0)
        return (arr[0] == t);

    if (dp[n][t] != -1)
        return dp[n][t];

    bool notTake = help(arr, n - 1, t, dp);
    bool take = false;
    if (arr[n] <= t)
        take = help(arr, n - 1, t - arr[n], dp);

    return dp[n][t] = take | notTake;
}

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return help(arr, n - 1, k, dp);
}

/*Tabulation*/
// TC : O(N*K)
// SC: O(N*K)
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<vector<bool>> dp(n, vector<bool>(k + 1, 0));
    for (int i = 0; i < n; i++)
        dp[i][0] = true;

    dp[0][arr[0]] = true;

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            bool notTake = dp[i - 1][j];
            bool take = false;
            if (arr[i] <= j)
                take = dp[i - 1][j - arr[i]];
            dp[i][j] = take | notTake;
        }
    }
    return dp[n - 1][k];
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

//https://www.codingninjas.com/codestudio/problems/subset-sum-equal-to-k_1550954?leftPanelTab=0