/*Memoization*/
//TC: O(N*2)
//SC: O(N*2) + O(N)
int help(vector<int> &prices, int n, bool buy, vector<vector<int>> &dp)
{
    if (n >= prices.size())
        return 0;

    if (dp[n][buy] != -1)
        return dp[n][buy];

    int profit = 0;
    if (buy)
    {
        profit = max(-prices[n] + help(prices, n + 1, 0, dp), 0 + help(prices, n + 1, 1, dp));
    }
    else
    {
        profit = max(prices[n] + help(prices, n + 2, 1, dp), 0 + help(prices, n + 1, 0, dp));
    }
    return dp[n][buy] = profit;
}

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return help(prices, 0, 1, dp);
}

/*Tabulation*/
//TC: O(N*2)
//SC: O(N*2)
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 2, vector<int>(2, 0));
    dp[n][0] = dp[n][1] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j <= 1; j++)
        {
            int profit = 0;
            if (j)
                profit = max(-prices[i] + dp[i + 1][0], dp[i + 1][1]);
            else
                profit = max(prices[i] + dp[i + 2][1], dp[i + 1][0]);

            dp[i][j] = profit;
        }
    }
    return dp[0][1];
}

/*Memoization*/
//TC: O(N)
//SC: O(1) ~ 3*O(2)
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<int> first(2, 0), second(2, 0), cur(2, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        cur[1] = max(-prices[i] + second[0], second[1]);
        cur[0] = max(prices[i] + first[1], second[0]);
        first = second;
        second = cur;
    }
    return second[1];
}