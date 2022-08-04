/*Recursion*/
// TC: O(Exponential)
//  SC: O(weight)
//  for questions of infinite supply you cant tell accurate TC and SC
int help(vector<int> w, vector<int> val, int n, int W)
{
    if (n == 0)
    {
        return (W / w[0]) * val[0];
    }

    int take = -1e9;
    if (w[n] <= W)
        take = val[n] + help(w, val, n, W - w[n]);
    int notTake = help(w, val, n - 1, W);

    return max(notTake, take);
}

/*Memoization*/
// TC: O(N*weight)
// SC: O(N*weight) + O(N)
int help(vector<int> w, vector<int> val, int n, int W, vector<vector<int>> &dp)
{
    if (n == 0)
    {
        return (W / w[0]) * val[0];
    }

    if (dp[n][W] != -1)
        return dp[n][W];

    int take = -1e9;
    if (w[n] <= W)
        take = val[n] + help(w, val, n, W - w[n], dp);
    int notTake = help(w, val, n - 1, W, dp);

    return dp[n][W] = max(notTake, take);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>> dp(n, vector<int>(w + 1, -1));
    return help(weight, profit, n - 1, w, dp);
}

/*Tabulation*/
// TC: O(N*weight)
// SC: O(N*weight)
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    vector<vector<int>> dp(n, vector<int>(w + 1, 0));
    for (int i = weight[0]; i <= w; i++)
    {
        dp[0][i] = (i / weight[0]) * profit[0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            int take = -1e9;
            if (weight[i] <= j)
                take = profit[i] + dp[i][j - weight[i]];
            int notTake = dp[i - 1][j];
            dp[i][j] = max(take, notTake);
        }
    }
    return dp[n - 1][w];
}

/*Space optimized*/
// TC: O(N*weight)
// SC: 2*O(weight)
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>> dp(n, vector<int>(w + 1, 0));
    vector<int> prev(w + 1, 0);
    vector<int> cur(w + 1, 0);
    for (int i = weight[0]; i <= w; i++)
    {
        prev[i] = (i / weight[0]) * profit[0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            int take = -1e9;
            if (weight[i] <= j)
                take = profit[i] + cur[j - weight[i]];
            int notTake = prev[j];
            cur[j] = max(take, notTake);
        }
        prev = cur;
    }
    return prev[w];
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>> dp(n, vector<int>(w + 1, 0));
    vector<int> prev(w + 1, 0);
    vector<int> cur(w + 1, 0);
    for (int i = weight[0]; i <= w; i++)
    {
        prev[i] = (i / weight[0]) * profit[0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            int take = -1e9;
            if (weight[i] <= j)
                take = profit[i] + cur[j - weight[i]];
            int notTake = prev[j];
            cur[j] = max(take, notTake);
        }
        prev = cur;
    }
    return prev[w];
}

// https://www.codingninjas.com/codestudio/problems/unbounded-knapsack_1215029