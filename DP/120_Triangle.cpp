/*recursion*/
// TC: O(2^(N*M))
// SC: O(N)
int help(vector<vector<int>> &t, int m, int n, int M)
{
    if (m == M)
        return t[m][n];

    int btm = t[m][n] + help(t, m + 1, n, M);
    int btmlft = t[m][n] + help(t, m + 1, n + 1, M);

    return min(btm, btmlft);
}

int minimumTotal(vector<vector<int>> &t)
{
    int m = t.size();
    return help(t, 0, 0, m - 1);
}

/*memoization*/
// TC: O(N*M)
// SC: O(N) + O(N*M)
int help(vector<vector<int>> &t, int m, int n, int M, vector<vector<int>> &memo)
{
    if (m == M)
        return t[m][n];

    if (memo[m][n] != -1)
        return memo[m][n];

    int btm = t[m][n] + help(t, m + 1, n, M, memo);
    int btmlft = t[m][n] + help(t, m + 1, n + 1, M, memo);

    return memo[m][n] = min(btm, btmlft);
}

int minimumTotal(vector<vector<int>> &t)
{
    int m = t.size();
    int n = t[m - 1].size();
    vector<vector<int>> memo(m, vector<int>(m, -1));
    return help(t, 0, 0, m - 1, memo);
}

/*tabulation*/
// TC: O(N*M)
// SC: O(N*M)
int minimumTotal(vector<vector<int>> &t)
{
    int m = t.size();
    int n = t[m - 1].size();
    vector<vector<int>> memo(m, vector<int>(m, 0));

    for (int i = 0; i < m; i++)
    {
        memo[m - 1][i] = t[m - 1][i];
    }

    for (int i = m - 2; i >= 0; i--)
    {
        // row
        int n = t[i].size();
        for (int j = 0; j < n; j++)
        {
            memo[i][j] = t[i][j] + min(memo[i + 1][j], memo[i + 1][j + 1]);
        }
    }
    return memo[0][0];
}

/*space optimization - 1D dp*/
// TC: O(M*N)
// SC: O(M)
int minimumTotal(vector<vector<int>> &t)
{
    int m = t.size();
    int n = t[m - 1].size();
    vector<int> prev(m, 0);

    for (int i = 0; i < m; i++)
    {
        prev[i] = t[m - 1][i];
    }

    for (int i = m - 2; i >= 0; i--)
    {
        vector<int> temp(m, 0);
        int n = t[i].size();
        for (int j = 0; j < n; j++)
        {
            temp[j] = t[i][j] + min(prev[j], prev[j + 1]);
        }
        prev = temp;
    }
    return prev[0];
}
