/*Recursion*/
// TC: >> O(2^N) || exponential
// SC: >> O(N) || O(amount)(if mini count of each denomination is 1)
int help(int amount, vector<int> &coins, int n)
{
    if (n == 0)
    {
        if (amount % coins[0] == 0)
            return 1;
        return 0;
    }

    int notTake = help(amount, coins, n - 1);
    int take = 0;
    if (coins[n] <= amount)
        take = help(amount - coins[n], coins, n);

    return take + notTake;
}

/*Memoization*/
// TC: O(N*amount)
// SC: O(N*amount) + O(N)
// for questions of infinite supplyl you cant tell accurate TC and SC
int help(int amount, vector<int> &coins, int n, vector<vector<int>> &dp)
{
    if (n == 0)
    {
        if (amount % coins[0] == 0)
            return 1;
        return 0;
    }

    if (dp[n][amount] != -1)
        return dp[n][amount];

    int notTake = help(amount, coins, n - 1, dp);
    int take = 0;
    if (coins[n] <= amount)
        take = help(amount - coins[n], coins, n, dp);

    return dp[n][amount] = take + notTake;
}

int change(int amount, vector<int> &coins)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    return help(amount, coins, n - 1, dp);
}

/*Tabulation*/
// TC: O(N*amount)
// SC: 2*O(N*amount)
int change(int amount, vector<int> &coins)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
    for (int i = 0; i <= amount; i++)
    {
        if (i % coins[0] == 0)
            dp[0][i] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= amount; j++)
        {
            int notTake = dp[i - 1][j];
            int take = 0;
            if (coins[i] <= j)
                take = dp[i][j - coins[i]];
            dp[i][j] = take + notTake;
        }
    }
    return dp[n - 1][amount];
}


/*Space optimzation*/
// TC: O(N*amount)
// SC: O(N*amount)
int change(int amount, vector<int> &coins)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
    vector<int> prev(amount + 1, 0);
    vector<int> cur(amount + 1, 0);
    for (int i = 0; i <= amount; i++)
    {
        if (i % coins[0] == 0)
            prev[i] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= amount; j++)
        {
            int notTake = prev[j];
            int take = 0;
            if (coins[i] <= j)
                take = cur[j - coins[i]];
            cur[j] = take + notTake;
        }
        prev = cur;
    }
    return prev[amount];
}