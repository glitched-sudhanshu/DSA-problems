void printLCS(string t1, string t2)
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

    //main solution
    string ans;
    int i=n, j=m;
    while(i>0 && j>0)
    {
        if(t1[i-1] == t2[j-1])
        {
            ans += t1[i];
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1])i--;
        else j--;
    }
    //since we are traversing it from the end the answer is generated in opposite direction. 
    reverse(str.begin(), str.end());
    cout << str;
}

/*
If the answer consists of multiple LCS, then make a recursive solution and call for both the directions, when 
dp[i-1][j] == dp[i][j-1] (instead of calling the max one). ELse if they are not equal call for the maximum one.
*/