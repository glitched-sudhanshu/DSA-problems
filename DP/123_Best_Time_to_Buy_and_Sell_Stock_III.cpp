/*Recursion*/
// TC: O(expo)
// SC: O(N)
int help(vector<int> &prices, int n, bool buy, int limit)
{
    if (n == prices.size() || limit == 0)
        return 0;
    if (dp[n][buy][limit] != -1)
        return dp[n][buy][limit];

    int profit = 0;
    if (buy)
    {
        profit = max(-prices[n] + help(prices, n + 1, 0, limit), 0 + help(prices, n + 1, 1, limit));
    }
    else
    {
        profit = max(prices[n] + help(prices, n + 1, 1, limit - 1), 0 + help(prices, n + 1, 0, limit));
    }
    return profit;
}

int maxProfit(vector<int> &prices)
{
    return help(prices, 0, 1, 2);
}

/*Memoization*/
// TC: O(N*2*3)
// SC: O(N*2*3) + O(N)
int help(vector<int> &prices, int n, bool buy, vector<vector<vector<int>>> &dp, int limit)
{
    if (n == prices.size())
        return 0;
    if (limit == 0)
        return 0;
    if (dp[n][buy][limit] != -1)
        return dp[n][buy][limit];

    int profit = 0;
    if (buy)
    {
        profit = max(-prices[n] + help(prices, n + 1, 0, dp, limit), 0 + help(prices, n + 1, 1, dp, limit));
    }
    else
    {
        profit = max(prices[n] + help(prices, n + 1, 1, dp, limit - 1), 0 + help(prices, n + 1, 0, dp, limit));
    }
    return dp[n][buy][limit] = profit;
}

/*Tabulation*/
// TC: O(N*2*3)
// SC: O(N*2*3)
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
            dp[i][j][0] = 0;
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
            dp[n][i][j] = 0;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 1; k < 3; k++)
            {
                if (j == 0)
                {
                    dp[i][j][k] = max(-prices[i] + dp[i + 1][1][k], 0 + dp[i + 1][0][k]);
                }
                else
                    dp[i][j][k] = max(prices[i] + dp[i + 1][0][k - 1], 0 + dp[i + 1][1][k]);
            }
        }
    }
    return dp[0][0][2];
}

/*Space optimization*/
// TC: O(N*2*3)
// SC: 2*O(2*3)
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> ahead(2, vector<int>(3, 0));
    vector<vector<int>> cur(2, vector<int>(3, 0));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 1; k < 3; k++)
            {
                if (j == 0)
                {
                    cur[j][k] = max(-prices[i] + ahead[1][k], 0 + ahead[0][k]);
                }
                else
                    cur[j][k] = max(prices[i] + ahead[0][k - 1], 0 + ahead[1][k]);
            }
        }
        ahead = cur;
    }
    return ahead[0][2];
}