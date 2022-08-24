/*Memoization*/
//TC: ~O(2*(N^3))
//SC: O(2*(N^2)) + O(N)
long long mod = 1e9 + 7;
long long help(string &s, long long i, long long j, bool isTrue, vector<vector<vector<long long>>> &dp)
{
    if (i > j)
        return 0;
    if (i == j)
    {
        if (isTrue)
            return s[i] == 'T';
        return s[i] == 'F';
    }

    if (dp[i][j][isTrue] != -1)
        return dp[i][j][isTrue];

    long long ways = 0;
    for (long long k = i + 1; k < j; k += 2)
    {
        long long lt = help(s, i, k - 1, 1, dp);
        long long lf = help(s, i, k - 1, 0, dp);
        long long rt = help(s, k + 1, j, 1, dp);
        long long rf = help(s, k + 1, j, 0, dp);
        if (s[k] == '&')
        {
            if (isTrue)
            {
                ways = (ways + (lt * rt) % mod) % mod;
            }
            else
            {
                ways = (ways + (lf * rf) % mod + (lt * rf) % mod + (lf * rt) % mod) % mod;
            }
        }
        else if (s[k] == '|')
        {
            if (isTrue)
            {
                ways = (ways + (lt * rf) % mod + (lt * rt) % mod + (lf * rt) % mod) % mod;
            }
            else
            {
                ways = (ways + (lf * rf) % mod) % mod;
            }
        }
        else
        {
            if (isTrue)
            {
                ways = (ways + (lt * rf) % mod + (rt * lf) % mod) % mod;
            }
            else
            {
                ways = (ways + (lt * rt) % mod + (rf * lf) % mod) % mod;
            }
        }
    }
    return dp[i][j][isTrue] = ways;

    // return dp[i][j][isTrue] = ways;
}

long long evaluateExp(string &s)
{
    // Write your code here.
    long long n = s.size();
    vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(n, vector<long long>(2, -1)));
    return help(s, 0, n - 1, 1, dp);
}

/*Tabulation*/
//TC: ~O(2*(N^3))
//SC: O(2*(N^2))
long long mod = 1e9 + 7;
int evaluateExp(string &s)
{
    // Write your code here.
    long long n = s.size();
    vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>>(n + 1, vector<long long>(2, 0)));

    for (int i = 0; i < n + 1; i++)
    {
        if (s[i] == 'T')
        {
            dp[i][i][1] = 1;
        }
        else if (s[i] == 'F')
        {
            dp[i][i][0] = 1;
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int isTrue = 0; isTrue < 2; isTrue++)
            {
                int ways = 0;
                for (int k = i + 1; k < j; k += 2)
                {
                    long long lt = dp[i][k - 1][1];
                    long long lf = dp[i][k - 1][0];
                    long long rt = dp[k + 1][j][1];
                    long long rf = dp[k + 1][j][0];
                    if (s[k] == '&')
                    {
                        if (isTrue)
                        {
                            ways = (ways + (lt * rt) % mod) % mod;
                        }
                        else
                        {
                            ways = (ways + (lf * rf) % mod + (lt * rf) % mod + (lf * rt) % mod) % mod;
                        }
                    }
                    else if (s[k] == '|')
                    {
                        if (isTrue)
                        {
                            ways = (ways + (lt * rf) % mod + (lt * rt) % mod + (lf * rt) % mod) % mod;
                        }
                        else
                        {
                            ways = (ways + (lf * rf) % mod) % mod;
                        }
                    }
                    else
                    {
                        if (isTrue)
                        {
                            ways = (ways + (lt * rf) % mod + (rt * lf) % mod) % mod;
                        }
                        else
                        {
                            ways = (ways + (lt * rt) % mod + (rf * lf) % mod) % mod;
                        }
                    }
                }
                dp[i][j][isTrue] = ways;
            }
        }
    }
    return dp[0][n - 1][1];
}
// https://www.codingninjas.com/codestudio/problems/problem-name-boolean-evaluation_1214650