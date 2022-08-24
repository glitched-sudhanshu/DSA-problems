/*Memoization*/
// TC: O(N^2)
// SC: O(N) + O(N)
int help(vector<int> &arr, int k, int n, vector<int> &dp)
{
    if (n == arr.size())
        return 0;

    if (dp[n] != -1)
        return dp[n];

    int maxi = -1e9;
    int maxans = -1e9;
    int s = arr.size();
    for (int i = n; i < min(n + k, s); i++)
    {
        int len = (i - n + 1);
        maxi = max(arr[i], maxi);
        int sum = (len * maxi) + help(arr, k, i + 1, dp);
        maxans = max(maxans, sum);
    }
    return dp[n] = maxans;
}

int maxSumAfterPartitioning(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> dp(n, -1);
    return help(arr, k, 0, dp);
}

/*Tabulation*/
// TC: O(N^2)
// SC: O(N)
int maxSumAfterPartitioning(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> dp(n + 1, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        int maxi = -1e9;
        int maxans = -1e9;
        int s = arr.size();
        for (int j = i; j < min(i + k, s); j++)
        {
            int len = (j - i + 1);
            maxi = max(arr[j], maxi);
            int sum = (len * maxi) + help(arr, k, j + 1, dp);
            maxans = max(maxans, sum);
        }
        dp[i] = maxans;
    }
    return dp[0];
}