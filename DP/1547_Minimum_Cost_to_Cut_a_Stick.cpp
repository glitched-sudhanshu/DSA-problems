/*Memoization*/
// TC: ~O(N^3)
// SC: O(N^2)
int help(vector<int> &cuts, int i, int j, vector<vector<int>> &sp)
{
    if (i > j)
        return 0;

    if (sp[i][j] != -1)
        return sp[i][j];

    int mini = 1e9;
    for (int k = i; k <= j; k++)
    {
        int cost = (cuts[j + 1] - cuts[i - 1]) + help(cuts, i, k - 1, sp) + help(cuts, k + 1, j, sp);
        mini = min(cost, mini);
    }
    return sp[i][j] = mini;
}

int minCost(int n, vector<int> &cuts)
{

    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());
    int clen = cuts.size();
    sp(n + 1, vector<int>(n + 1, -1));
    return help(cuts, 1, clen - 2, sp);
}

/*Tabulation*/
// TC: ~O(N^3)
// SC: O(N^2)
int minCost(int n, vector<int> &cuts)
{
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());
    int clen = cuts.size();
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = i; j < clen - 1; j++)
        {
            int mini = 1e9;
            for (int k = i; k <= j; k++)
            {
                int cost = (cuts[j + 1] - cuts[i - 1]) + dp[i][k - 1] + dp[k + 1][j];
                mini = min(mini, cost);
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][clen - 2];
}