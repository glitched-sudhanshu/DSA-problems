/*tabulation*/
// TC: O(N*M)
// SC: O(N*M)
string printLCS(string t1, string t2)
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

    // main solution
    string ans;
    int i = n, j = m;
    while (i > 0 && j > 0)
    {
        if (t1[i - 1] == t2[j - 1])
        {
            ans += t1[i - 1];
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            ans += t1[i - 1];
            i--;
        }
        else
        {
            ans += t2[j - 1];
            j--;
        }
    }
    while (i > 0)
    {
        ans += t1[i - 1];
        i--;
    }
    while (j > 0)
    {
        ans += t2[j - 1];
        j--;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

// main ques
string shortestCommonSupersequence(string str1, string str2)
{
    return printLCS(str1, str2);
}

// for length of shortestCommonSupersequence (m + n - len(lcs));

// longest common subseq's function and dp table is used.