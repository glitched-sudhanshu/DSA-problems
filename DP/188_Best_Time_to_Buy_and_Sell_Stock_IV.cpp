/**/
//TC: O(N*2*K)
//SC: O(N*2*K) + O(N)
int help(vector<int> &prices, int n, int trans, int &k, vector<vector<int>> &dp)
{
    if (n == prices.size())
        return 0;
    if (trans == 2 * k)
        return 0;

    if (dp[n][trans] != -1)
        return dp[n][trans];

    int profit = 0;
    if (trans % 2 == 0)
        profit = max(-prices[n] + help(prices, n + 1, trans + 1, k, dp), 0 + help(prices, n + 1, trans, k, dp));
    else
        profit = max(prices[n] + help(prices, n + 1, trans + 1, k, dp), 0 + help(prices, n + 1, trans, k, dp));

    return dp[n][trans] = profit;
}


/*Memoization*/
//TC: O(N*2*K)
//SC: O(N*2*K) + O(N)
int help(vector<int> &prices, int n, int trans, int &k, vector<vector<int>> &dp)
{
    if (n == prices.size())
        return 0;
    if (trans == 2 * k)
        return 0;

    if (dp[n][trans] != -1)
        return dp[n][trans];

    int profit = 0;
    if (trans % 2 == 0)
        profit = max(-prices[n] + help(prices, n + 1, trans + 1, k, dp), 0 + help(prices, n + 1, trans, k, dp));
    else
        profit = max(prices[n] + help(prices, n + 1, trans + 1, k, dp), 0 + help(prices, n + 1, trans, k, dp));

    return dp[n][trans] = profit;
}

/*Tabulation*/
//TC: O(N*2*K)
//SC: O(N*2*K)
int maxProfit(int k, vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, 0));

    for (int j = 0; j <= 2 * k; j++)
    {
        dp[n][j] = 0;
    }
    for (int i = 0; i <= n; i++)
    {
        dp[i][2 * k] = 0;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 2 * k - 1; j >= 0; j--)
        {
            if (j % 2 == 0)
                dp[i][j] = max(-prices[i] + dp[i + 1][j + 1], dp[i + 1][j]);
            else
                dp[i][j] = max(prices[i] + dp[i + 1][j + 1], dp[i + 1][j]);
        }
    }
    return dp[0][0];
}

/*Space optimized*/
//TC: O(N*2*K)
//SC: O(2*K)
int maxProfit(int k, vector<int> &prices)
{
    int n = prices.size();
    vector<int> ahead(2 * k + 1, 0);
    vector<int> cur(2 * k + 1, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 2 * k - 1; j >= 0; j--)
        {
            if (j % 2 == 0)
                cur[j] = max(-prices[i] + ahead[j + 1], ahead[j]);
            else
                cur[j] = max(prices[i] + ahead[j + 1], ahead[j]);
        }
        ahead = cur;
    }
    return ahead[0];
}