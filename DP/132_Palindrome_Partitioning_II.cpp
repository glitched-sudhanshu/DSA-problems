
/*Memoization*/
// TC: O(N^2)
// SC: O(N) + O(N)
bool isPallin(string &s)
{
    string str = s;
    reverse(str.begin(), str.end());
    return str == s;
}

int help(string &s, int n, vector<int> &dp)
{
    if (n == s.size())
        return 0;

    if (dp[n] != -1)
        return dp[n];

    string temp = "";
    int mini = 1e9;
    for (int i = n; i < s.size(); i++)
    {
        temp += s[i];
        if (isPallin(temp))
        {
            int cnt = 1 + help(s, i + 1, dp);
            mini = min(cnt, mini);
        }
    }
    return dp[n] = mini;
}

int minCut(string s)
{
    int n = s.size();
    vector<int> dp(n, -1);
    return help(s, 0, dp) - 1;
}

/*Tabulation*/
// TC: O(N^2)
// SC: O(N)
bool isPallin(string &s)
{
    string str = s;
    reverse(str.begin(), str.end());
    return str == s;
}

int minCut(string s)
{
    int n = s.size();
    vector<int> dp(n + 1, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        string temp = "";
        int mini = 1e9;
        for (int k = i; k < s.size(); k++)
        {
            temp += s[k];
            if (isPallin(temp))
            {
                int cnt = 1 + dp[k + 1];
                mini = min(cnt, mini);
            }
        }
        dp[i] = mini;
    }
    return dp[0] - 1;
}
