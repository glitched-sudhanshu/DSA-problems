// https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

/*Memoization*/
// TC: ~O(N^3)
// SC: O(N^2) + O(N)
int help(int arr[], int i, int j, vector<vector<int>> &dp)
{
    if (i >= j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int mini = 1e9;
    for (int k = i; k <= j - 1; k++)
    {
        int steps = arr[i - 1] * arr[k] * arr[j] + help(arr, i, k, dp) + help(arr, k + 1, j, dp);
        mini = min(mini, steps);
    }
    return dp[i][j] = mini;
}

int matrixMultiplication(int n, int arr[])
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return help(arr, 1, n - 1, dp);
}

/*Tabulation*/
// TC: ~O(N^3)
// SC: O(N^2)
int matrixMultiplication(int n, int arr[])
{
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = i + 1; j < n; j++)
        {
            int mini = 1e9;
            for (int k = i; k < j; k++)
            {
                int steps = arr[i - 1] * arr[k] * arr[j] + dp[i][k] + dp[k + 1][j];
                mini = min(mini, steps);
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][n - 1];
}