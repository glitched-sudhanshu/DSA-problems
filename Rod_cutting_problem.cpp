/*Recursion*/
// TC: O(Exponential)
//  SC: O(target)
//  for questions of infinite supply you cant tell accurate TC and SC
int help(vector<int> &price, int n, int tar)
{
    if (n == 0)
    {
        if (tar != 0)
            return -1e9;
        return 0;
    }

//the above base case will also include this, but this is for only for understanding and terminating the call stack as soon as we hit the target
    if (tar == 0)
    {
        return 0;
    }

    int notCut = help(price, n - 1, tar);
    int cut = -1e9;
    if (n <= tar)
        cut = price[n - 1] + help(price, n, tar - n);

    return max(notCut, cut);
}

/*Memoization*/
// TC: O(N*N)
// SC: O(N*N) + O(N)
int help(vector<int> &price, int n, int tar, vector<vector<int>> &dp)
{
    if (n == 0)
    {
        if (tar != 0)
            return -1e9;
        return 0;
    }

    if (dp[n][tar] != -1)
        return dp[n][tar];

    int notCut = help(price, n - 1, tar, dp);
    int cut = -1e9;
    if (n <= tar)
        cut = price[n - 1] + help(price, n, tar - n, dp);

    return dp[n][tar] = max(notCut, cut);
}

int cutRod(vector<int> &price, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return help(price, n, n, dp);
}

/*Tabulation*/
// TC: O(N*N)
// SC: O(N*N)
int cutRod(vector<int> &price, int n)
{
    // Write your code here.
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        dp[0][i] = -1e9;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            int notCut = dp[i - 1][j];
            int cut = -1e9;
            if (i <= j)
                cut = price[i - 1] + dp[i][j - i];
            dp[i][j] = max(cut, notCut);
        }
    }
    return dp[n][n];
    return help(price, n, n, dp);
}

/*Space optimized*/
// TC: O(N*N)
// SC: 2*O(N)
int cutRod(vector<int> &price, int n)
{
    // Write your code here.
    vector<int> prev(n + 1, 0);
    vector<int> cur(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        prev[i] = -1e9;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            int notCut = prev[j];
            int cut = -1e9;
            if (i <= j)
                cut = price[i - 1] + cur[j - i];
            cur[j] = max(cut, notCut);
        }
        prev = cur;
    }
    return prev[n];
}

/*Space optimized - 1D array*/
// TC: O(N*N)
// SC: O(N)
int cutRod(vector<int> &price, int n)
{
    // Write your code here.
    vector<int> prev(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        prev[i] = -1e9;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            int notCut = prev[j];
            int cut = -1e9;
            if (i <= j)
                cut = price[i - 1] + prev[j - i];
            prev[j] = max(cut, notCut);
        }
    }
    return prev[n];
}

// https://www.codingninjas.com/codestudio/problems/rod-cutting-problem_800284