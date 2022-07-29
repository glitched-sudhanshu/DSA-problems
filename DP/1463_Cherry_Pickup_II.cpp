/*recursion*/
// TC: O(3^n * 3^n)
// SC: O(M)
int help(vector<vector<int>> &g, int m, int n1, int n2, int M, int N)
{
    if (n1 < 0 || n2 < 0 || n1 >= N || n2 > N)
        return -1e8;

    if (m == M)
    {
        if (n1 == n2)
            return g[m][n1];
        return g[m][n1] + g[m][n2];
    }

    int maxi = -1e8;
    for (int i = -1; i < 2; i++)
    {
        for (int j = -1; j < 2; j++)
        {
            if (n1 == n2)
                maxi = max(maxi, g[m][n1] + help(g, m + 1, n1 + i, n2 + j, M, N));
            else
                maxi = max(maxi, g[m][n1] + g[m][n2] + help(g, m + 1, n1 + i, n2 + j, M, N));
        }
    }
    return maxi;
}

int cherryPickup(vector<vector<int>> &g)
{
    int M = g.size();
    int N = g[0].size();
    return help(g, 0, 0, N - 1, M - 1, N - 1);
}

/*Memoization*/
// TC: O(M*N*N)*9
// SC: O(M*N*N) + O(M)

int help(vector<vector<int>> &g, int m, int n1, int n2, int M, int N, vector<vector<vector<int>>> &dp)
{
    if (n1 < 0 || n2 < 0 || n1 >= N || n2 > N)
        return -1e8;

    if (m == M)
    {
        if (n1 == n2)
            return g[m][n1];
        return g[m][n1] + g[m][n2];
    }

    if (dp[m][n1][n2] != -1)
        return dp[m][n1][n2];

    int maxi = -1e8;
    for (int i = -1; i < 2; i++)
    {
        for (int j = -1; j < 2; j++)
        {
            if (n1 == n2)
                maxi = max(maxi, g[m][n1] + help(g, m + 1, n1 + i, n2 + j, M, N, dp));
            else
                maxi = max(maxi, g[m][n1] + g[m][n2] + help(g, m + 1, n1 + i, n2 + j, M, N, dp));
        }
    }
    return dp[m][n1][n2] = maxi;
}

int cherryPickup(vector<vector<int>> &g)
{
    int M = g.size();
    int N = g[0].size();
    vector<vector<vector<int>>> dp(M, vector<vector<int>>(N, vector<int>(N, -1)));
    return help(g, 0, 0, N - 1, M - 1, N - 1, dp);
}

/*tabulation*/
// TC: O(M*N*N)*9
// SC: O(M*N*N)
int cherryPickup(vector<vector<int>> &g)
{
    int M = g.size();
    int N = g[0].size();
    vector<vector<vector<int>>> dp(M, vector<vector<int>>(N, vector<int>(N, 0)));
    for (int j = 0; j < N; j++)
    {
        for (int k = 0; k < N; k++)
        {
            if (j == k)
                dp[M - 1][j][k] = g[M - 1][k];
            else
                dp[M - 1][j][k] = g[M - 1][k] + g[M - 1][j];
        }
    }

    for (int i = M - 2; i >= 0; i--)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                int maxi = INT_MIN;
                for (int dj1 = -1; dj1 < 2; dj1++)
                {
                    for (int dj2 = -1; dj2 < 2; dj2++)
                    {
                        int value = 0;
                        if (j == k)
                            value = g[i][k];
                        else
                            value = g[i][k] + g[i][j];
                        if (j + dj1 >= 0 && j + dj1 < N && k + dj2 >= 0 && k + dj2 < N)
                            value += dp[i + 1][j + dj1][k + dj2];
                        else
                            value += -1e8;
                        maxi = max(maxi, value);
                    }
                }
                dp[i][j][k] = maxi;
            }
        }
    }
    return dp[0][0][N - 1];
}

/*space optimized- 2D*/
// TC: O(M*N*N)*9
// SC: O(M*N)

int cherryPickup(vector<vector<int>> &g)
{
    int M = g.size();
    int N = g[0].size();
    vector<vector<int>> prev(N, vector<int>(N, 0));
    for (int j = 0; j < N; j++)
    {
        for (int k = 0; k < N; k++)
        {
            if (j == k)
                prev[j][k] = g[M - 1][k];
            else
                prev[j][k] = g[M - 1][k] + g[M - 1][j];
        }
    }

    for (int i = M - 2; i >= 0; i--)
    {
        vector<vector<int>> temp(N, vector<int>(N, 0));
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < N; k++)
            {
                int maxi = INT_MIN;
                for (int dj1 = -1; dj1 < 2; dj1++)
                {
                    for (int dj2 = -1; dj2 < 2; dj2++)
                    {
                        int value = 0;
                        if (j == k)
                            value = g[i][k];
                        else
                            value = g[i][k] + g[i][j];
                        if (j + dj1 >= 0 && j + dj1 < N && k + dj2 >= 0 && k + dj2 < N)
                            value += prev[j + dj1][k + dj2];
                        else
                            value += -1e8;
                        maxi = max(maxi, value);
                    }
                }
                temp[j][k] = maxi;
            }
        }
        prev = temp;
    }
    return prev[0][N - 1];
}
