/*Memoization*/
// TC: O(N*M)
// SC: O(N*M) + O(N+M)
int help(string &s, string &t, int i, int j, vector<vector<int>> &dp)
{
    if (j < 0)
        return 1;
    if (i < 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int take = 0;
    if (s[i] == t[j])
        take = help(s, t, i - 1, j - 1, dp);
    // int notTake = help(s, t, i-1, j);
    int notTake = help(s, t, i - 1, j, dp);
    return dp[i][j] = notTake + take;
}

int numDistinct(string s, string t)
{
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return help(s, t, n - 1, m - 1, dp);
}

/*Tabulation*/
// TC: O(N*M)
// SC: O(N*M)
int numDistinct(string s, string t)
{
    int n = s.size();
    int m = t.size();

    int mod = 1e9 + 7;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
                dp[i][j] = (dp[i - 1][j - 1]) % mod;
            dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
        }
    }
    return dp[n][m];
}

/*1 1D array space optimization*/
// TC: O(N*M)
// SC: O(M)
int subsequenceCounting(string &s1, string &s2, int n, int m)
{
    // Write your code here.

    vector<int> prev(m + 1, 0);

    prev[0] = 1;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = m; j >= 1; j--)
        { // Reverse direction

            if (s1[i - 1] == s2[j - 1])
                prev[j] = (prev[j - 1] + prev[j]) % prime;
            else
                prev[j] = prev[j]; // can omit this statemwnt
        }
    }

    return prev[m];
}