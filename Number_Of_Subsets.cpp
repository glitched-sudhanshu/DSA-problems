/*Recursion*/
// TC: O(2^n)
// SC: O(N)
int help(vector<int> &nm, int n, int t, vector<vector<int>> &dp)
{
    if (n == 0)
    {
        if (t == 0 && nm[0] == 0)
            return 2;
        else if (t == 0 || t == nm[0])
            return 1;
        return 0;
    }

    if (dp[n][t] != -1)
        return dp[n][t];

    int take = 0;
    int notTake = help(nm, n - 1, t, dp);
    if (nm[n] <= t)
        take = help(nm, n - 1, t - nm[n], dp);

    return dp[n][t] = take + notTake;
}

int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
    return help(num, n - 1, tar, dp);
}

/*Memoization*/
// TC: O(N*T)
// SC: O(N) + O(N*T)
int help(vector<int> &nm, int n, int t, vector<vector<int>> &dp)
{
    if (n == 0)
    {
        if (t == 0 && nm[0] == 0)
            return 2;
        else if (t == 0 || t == nm[0])
            return 1;
        return 0;
    }

    if (dp[n][t] != -1)
        return dp[n][t];

    int take = 0;
    int notTake = help(nm, n - 1, t, dp);
    if (nm[n] <= t)
        take = help(nm, n - 1, t - nm[n], dp);

    return dp[n][t] = take + notTake;
}

/*Tabulation*/
// TC: O(N*T)
// SC: O(N*T)
int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(tar + 1, 0));
    for (int i = 0; i < n; i++)
    {
        if (num[i] == 0)
            dp[i][0] = 2;
        else
            dp[i][0] = 1;
    }
    if (num[0] <= tar && num[0] != 0)
        dp[0][num[0]] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= tar; j++)
        {
            int pick = 0;
            if (num[i] <= j)
                pick = dp[i - 1][j - num[i]];
            int notPick = dp[i - 1][j];
            dp[i][j] = pick + notPick;
        }
    }
    return dp[n - 1][tar];
}

/*Space optimized - 1D*/
// TC: O(N*T)
// SC: O(T)
int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector<int> prev(tar + 1, 0);
    vector<int> cur(tar + 1, 0);
    if (num[0] == 0)
        prev[0] = cur[0] = 2;
    else
        prev[0] = cur[0] = 1;
    if (num[0] <= tar && num[0] != 0)
        prev[num[0]] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= tar; j++)
        {
            int pick = 0;
            if (num[i] <= j)
                pick = prev[j - num[i]];
            int notPick = prev[j];
            cur[j] = pick + notPick;
        }
        prev = cur;
    }
    return prev[tar];
}

/*
In this ques we can have 0s too
Eg, {0,0,1} and Target = 1
Normal code will give count = 1, but the correct answer is 4
{0,0,1}, {1}, {0,1}, {0,1}
so we cannot simply do, (s==0)return 1;
bcz it might be possible they are further 0s which will increase the count. That is why we go deeper till n==0
and check all the possible cases
*/

//https://www.codingninjas.com/codestudio/problems/number-of-subsets_3952532