/*recursion*/
// TC: O(3^N)
// SC: O(N)
int help(vector<vector<int>> &mt, int m, int n, int N)
{
    // boundary cond
    if (n < 0 || m < 0 || n >= N || m >= N)
        return 1e6;

    if (m == 0)
        return mt[0][n];

    int up = mt[m][n] + help(mt, m - 1, n, N);
    int upr = mt[m][n] + help(mt, m - 1, n + 1, N);
    int upl = mt[m][n] + help(mt, m - 1, n - 1, N);

    return dp[m][n] = min(up, min(upr, upl));
}

int minFallingPathSum(vector<vector<int>> &mt)
{
    int n = mt.size();
    int mini = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        mini = min(mini, help(mt, n - 1, i, n));
    }
    return mini;
}

/*memoization*/
// TC: O(N*M)
// SC: o(N) + O(N*M)
int help(vector<vector<int>> &mt, int m, int n, int N, vector<vector<int>> &dp)
{
    // boundary cond
    if (n < 0 || m < 0 || n >= N || m >= N)
        return 1e6;

    if (m == 0)
        return mt[0][n];

    if (dp[m][n] != 1e8)
        return dp[m][n];

    int up = mt[m][n] + help(mt, m - 1, n, N, dp);
    int upr = mt[m][n] + help(mt, m - 1, n + 1, N, dp);
    int upl = mt[m][n] + help(mt, m - 1, n - 1, N, dp);

    return dp[m][n] = min(up, min(upr, upl));
}

int minFallingPathSum(vector<vector<int>> &mt)
{
    int n = mt.size();
    vector<vector<int>> dp(n, vector<int>(n, 1e8));
    int mini = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        dp[n - 1][i] = min(dp[n - 1][i], help(mt, n - 1, i, n, dp));
    }
    for (int i = 0; i < n; i++)
        mini = min(dp[n - 1][i], mini);
    return mini;
}

/*tabulation*/
// TC: O(N*M)
// SC: O(N*M)
int minFallingPathSum(vector<vector<int>> &mt)
{
    int n = mt.size();
    vector<vector<int>> dp(n, vector<int>(n, 1e8));

    for (int i = 0; i < n; i++)
        dp[0][i] = mt[0][i];

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int dw = mt[i][j] + dp[i - 1][j];
            int dwl = 1e6;
            if (j > 0)
                dwl = mt[i][j] + dp[i - 1][j - 1];
            int dwr = 1e6;
            if (j < n - 1)
                dwr = mt[i][j] + dp[i - 1][j + 1];
            dp[i][j] = min(dw, min(dwl, dwr));
        }
    }

    int mini = INT_MAX;
    for (int i = 0; i < n; i++)
        mini = min(mini, dp[n - 1][i]);

    return mini;
}

/*space optimized- 1D dp*/
// TC- O(N*M)
// SC- O(N)
int minFallingPathSum(vector<vector<int>> &mt)
{
    int n = mt.size();
    vector<int> prev(n, 1e8);

    for (int i = 0; i < n; i++)
        prev[i] = mt[0][i];

    for (int i = 1; i < n; i++)
    {
        vector<int> temp(n, 1e8);
        for (int j = 0; j < n; j++)
        {
            int dw = mt[i][j] + prev[j];
            int dwl = 1e6;
            if (j > 0)
                dwl = mt[i][j] + prev[j - 1];
            int dwr = 1e6;
            if (j < n - 1)
                dwr = mt[i][j] + prev[j + 1];
            temp[j] = min(dw, min(dwl, dwr));
        }
        prev = temp;
    }

    int mini = INT_MAX;
    for (int i = 0; i < n; i++)
        mini = min(mini, prev[i]);

    return mini;
}