/*Recursion*/
// TC: O(2^(m+n))
// SC: O(M+N)
int help(string s1, string s2, int i1, int i2)
{
    if (i1 < 0 || i2 < 0)
        return 0;

    if (s1[i1] == s2[i2])
        return 1 + help(s1, s2, i1 - 1, i2 - 1);

    return max(help(s1, s2, i1 - 1, i2), help(s1, s2, i1, i2 - 1));
}

/*Memoization*/
// TC: O(M*N)
// SC: O(M*N) + O(M+N)
int help(string s1, string s2, int i1, int i2, vector<vector<int>> &dp)
{
    if (i1 < 0 || i2 < 0)
        return 0;

    if (dp[i1][i2] != -1)
        return dp[i1][i2];

    if (s1[i1] == s2[i2])
        return dp[i1][i2] = 1 + help(s1, s2, i1 - 1, i2 - 1, dp);

    return dp[i1][i2] = max(help(s1, s2, i1 - 1, i2, dp), help(s1, s2, i1, i2 - 1, dp));
}

int longestCommonSubsequence(string text1, string text2)
{
    int n = text1.size(), m = text2.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return help(text1, text2, n - 1, m - 1, dp);
}

/*Tabulation*/
// TC: O(M*N)
// SC: O(M*N)
int longestCommonSubsequence(string t1, string t2)
{
    int n = t1.size(), m = t2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i <= m; i++)
        dp[0][i] = 0;
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (t1[i - 1] == t2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }
    return dp[n][m];
}

/*Soace optimized*/
// TC: O(M*N)
// SC: 2*O(M)
int longestCommonSubsequence(string t1, string t2)
{
    int n = t1.size(), m = t2.size();
    vector<int> prev(m + 1, 0), cur(m + 1, 0);

    for (int i = 0; i <= m; i++)
        prev[i] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (t1[i - 1] == t2[j - 1])
                cur[j] = 1 + prev[j - 1];
            else
                cur[j] = max(cur[j - 1], prev[j]);
        }
        prev = cur;
    }
    return prev[m];
}
}
;