/*Memoization*/
// TC: O(N*2)
// SC: O(N*2) + O(N)
int help(vector<int> &prices, int n, bool buy, vector<vector<int>> &dp, int fee)
{
    if (n == prices.size())
        return 0;

    if (dp[n][buy] != -1)
        return dp[n][buy];

    int profit = 0;
    if (buy)
    {
        profit = max(-prices[n] + help(prices, n + 1, 0, dp, fee), 0 + help(prices, n + 1, 1, dp, fee));
    }
    else
    {
        profit = max(prices[n] - fee + help(prices, n + 1, 1, dp, fee), 0 + help(prices, n + 1, 0, dp, fee));
    }
    return dp[n][buy] = profit;
}

int maxProfit(vector<int> &prices, int fee)
{
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return help(prices, 0, 1, dp, fee);
}


/*
Same question as of best time to buy and sell stock - II, so other approaches will also be the same just subtract the transaction fees.
*/