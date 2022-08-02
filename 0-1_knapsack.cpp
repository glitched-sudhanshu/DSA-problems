/*Recursion*/
// TC: O(2^N)
// SC: O(N)
int help(vector<int> w, vector<int> val, int n, int W)
{
    if (n == 0)
    {
        if (w[0] <= W)
            return val[0];
        return 0;
    }

    int take = INT_MIN;
    if (w[n] <= W)
        take = val[n] + help(w, val, n - 1, W - w[n]);
    int notTake = help(w, val, n - 1, W);

    return max(notTake, take);
}

/*Memoization*/
// TC: O(N*W)
// SC: O(N) + O(N)

int help(vector<int> w, vector<int> val, int n, int W, vector<vector<int>> &dp)
{
    if (n == 0)
    {
        if (w[0] <= W)
            return val[0];
        return 0;
    }

    if (dp[n][W] != -1)
        return dp[n][W];

    int take = INT_MIN;
    if (w[n] <= W)
        take = val[n] + help(w, val, n - 1, W - w[n], dp);
    int notTake = help(w, val, n - 1, W, dp);

    return dp[n][W] = max(notTake, take);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
    return help(weight, value, n - 1, maxWeight, dp);
}

/*Tabulation*/
// TC: O(N*W)
// SC: O(N*W)
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));
    for (int i = weight[0]; i <= maxWeight; i++)
    {
        dp[0][i] = value[0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= maxWeight; j++)
        {
            int take = -1e9;
            // j - weight[i] kyuki jo weigth tha usme se minus hoga na
            if (weight[i] <= j)
                take = value[i] + dp[i - 1][j - weight[i]];
            // j kyuki jo weight tha vahi rahega na
            int notTake = dp[i - 1][j];
            dp[i][j] = max(take, notTake);
        }
    }
    return dp[n - 1][maxWeight];
}

/*space optimization*/
// TC: O(N*W)
// SC: 2*O(W)
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<int> prev(maxWeight + 1, 0);
    for (int i = weight[0]; i <= maxWeight; i++)
    {
        prev[i] = value[0];
    }

    for (int i = 1; i < n; i++)
    {
        vector<int> cur(maxWeight + 1, 0);
        for (int j = 0; j <= maxWeight; j++)
        {
            int take = -1e9;
            if (weight[i] <= j)
                take = value[i] + prev[j - weight[i]];
            int notTake = prev[j];
            cur[j] = max(take, notTake);
        }
        prev = cur;
    }
    return prev[maxWeight];
}


/*space optimization*/
// TC: O(N*W)
// SC: O(W)
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
    vector<int> prev(maxWeight + 1, 0);
    for(int i=weight[0]; i<=maxWeight; i++)
    {
        prev[i] = value[0];
    }
    
    for(int i=1; i<n; i++)
    {
        for(int j=maxWeight; j>=0; j--)
        {
            int take = -1e9;
            if(weight[i]<=j) take = value[i] + prev[j-weight[i]];
            int notTake = prev[j];
            prev[j] = max(take, notTake);
        }
    }
    return prev[maxWeight];
}


//https://www.codingninjas.com/codestudio/problems/0-1-knapsack_920542