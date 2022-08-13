/*Tabulation*/
// TC: O(expo) ~ O(3^n)
// SC:  O(N+M)
int help(string w1, string w2, int i, int j)
{

    if (i < 0)
        return j + 1;
    if (j < 0)
        return i + 1;

    if (w1[i] == w2[j])
        return help(w1, w2, i - 1, j - 1);
    int ins = 1 + help(w1, w2, i, j - 1);
    int del = 1 + help(w1, w2, i - 1, j);
    int rep = 1 + help(w1, w2, i - 1, j - 1);
    return min(ins, min(del, rep));
}

/*Tabulation*/
// TC: O(N*M)
// SC: O(N*M) + O(N+M)
int help(string &w1, string &w2, int i, int j, vector<vector<int>> &dp)
{

    if (i < 0)
        return j + 1;
    if (j < 0)
        return i + 1;

    if (dp[i][j] != -1)
        return dp[i][j];

    if (w1[i] == w2[j])
        return dp[i][j] = help(w1, w2, i - 1, j - 1, dp);
    int ins = 1 + help(w1, w2, i, j - 1, dp);
    int del = 1 + help(w1, w2, i - 1, j, dp);
    int rep = 1 + help(w1, w2, i - 1, j - 1, dp);
    return dp[i][j] = min(ins, min(del, rep));
}

int minDistance(string w1, string w2)
{
    int n = w1.size(), m = w2.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return help(w1, w2, n - 1, m - 1, dp);
}

/*Tabulation*/
// TC: O(N*M)
// SC: O(N*M)
int minDistance(string w1, string w2)
{
    int n = w1.size(), m = w2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = i;
    }
    for (int i = 0; i <= m; i++)
    {
        dp[0][i] = i;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (w1[i - 1] == w2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = min(dp[i][j - 1], min(dp[i - 1][j - 1], dp[i - 1][j])) + 1;
        }
    }
    return dp[n][m];
}

/*Space optimized*/
// TC: O(N*M)
// SC: 2*O(M)
int minDistance(string w1, string w2)
{
    int n = w1.size(), m = w2.size();
    vector<int> prev(m + 1, 0);
    vector<int> cur(m + 1, 0);
    cur[0] = 1;

    for (int i = 0; i <= m; i++)
    {
        prev[i] = i;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cur[0] = i;
            if (w1[i - 1] == w2[j - 1])
                cur[j] = prev[j - 1];
            else
                cur[j] = min(cur[j - 1], min(prev[j - 1], prev[j])) + 1;
        }
        prev = cur;
    }

    return prev[m];
}