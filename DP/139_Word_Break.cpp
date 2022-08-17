/*Recursion*/
int help(string s, unordered_set<string> &wd, int n)
{
    if (n == s.size())
        return 1;

    string temp = "";
    for (int i = n; i < s.size(); i++)
    {
        temp += s[i];
        if (wd.find(temp) != wd.end())
        {
            if (help(s, wd, i + 1))
                return 1;
        }
    }
    return 0;
}

/*Tabulation*/
bool wordBreak(string s, vector<string> &wordDict)
{
    unordered_set<string> wd(wordDict.begin(), wordDict.end());
    int n = s.size();
    vector<int> dp(n + 1, 0);
    dp[n] = 1;
    for (int idx = n - 1; idx >= 0; idx--)
    {
        string temp = "";
        for (int i = idx; i < n; i++)
        {
            temp += s[i];
            if (wd.find(temp) != wd.end() && dp[i + 1] == 1)
            {
                dp[idx] = 1;
            }

            else
                dp[idx] |= 0;
        }
    }
    return dp[0];
}
