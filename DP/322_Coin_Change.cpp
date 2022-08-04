/*Recursion*/
// TC: >> O(2^N) || exponential
// SC: >> O(N) || O(amount)(if mini count of each denomination is 1)
int help(vector<int> &coins, int amount, int n)
{
    if (n == 0)
    {
        if (amount % coins[0] == 0)
            return amount / coins[0];
        return 1e9;
    }

    int notTake = help(coins, amount, n - 1);
    int take = 1e9;
    // whenever there is a case of multiple/infinite selections, dont change the index
    if (coins[n] <= amount)
        take = 1 + help(coins, amount - coins[n], n);

    return min(take, notTake);
}

/*Memoization*/
// TC: O(N*amount)
// SC: O(N*amount) + O(N)

int help(vector<int> &coins, int amount, int n, vector<vector<int>> &dp)
{
    if (n == 0)
    {
        if (amount % coins[0] == 0)
            return amount / coins[0];
        return 1e9;
    }

    if (dp[n][amount] != -1)
        return dp[n][amount];

    int notTake = help(coins, amount, n - 1, dp);
    int take = 1e9;
    // whenever there is a case of multiple/infinite selections, dont change the index
    if (coins[n] <= amount)
        take = 1 + help(coins, amount - coins[n], n, dp);

    return dp[n][amount] = min(take, notTake);
}
int coinChange(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    int ans = help(coins, amount, n - 1, dp);
    return ans == 1e9 ? -1 : ans;
}

/*Tabulation*/
// TC: O(N*amount)
// SC: 2*O(N*amount)
int coinChange(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    for (int i = 0; i <= amount; i++)
    {
        if (i % coins[0] == 0)
            dp[0][i] = i / coins[0];
        else
            dp[0][i] = 1e9;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= amount; j++)
        {
            int notTake = dp[i - 1][j];
            int take = 1e9;
            if (coins[i] <= j)
                take = 1 + dp[i][j - coins[i]];
            dp[i][j] = min(notTake, take);
        }
    }
    int ans = dp[n - 1][amount];
    return ans == 1e9 ? -1 : ans;
}

/*Space optimization*/
// TC: O(N*amount)
// SC: O(amount)
int coinChange(vector<int> &coins, int amount)
{
    int n = coins.size();
    vector<int> prev(amount + 1, 0);
    vector<int> cur(amount + 1, 0);
    for (int i = 0; i <= amount; i++)
    {
        if (i % coins[0] == 0)
            prev[i] = i / coins[0];
        else
            prev[i] = 1e9;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= amount; j++)
        {
            int notTake = prev[j];
            int take = 1e9;
            if (coins[i] <= j)
                take = 1 + cur[j - coins[i]];
            cur[j] = min(notTake, take);
        }
        prev = cur;
    }
    int ans = prev[amount];
    return ans == 1e9 ? -1 : ans;
}