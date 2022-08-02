/*Recursion*/
// TC: O(N^2)
// SC: O(N)
int help(vector<int> &nums, int n)
{
    if (n == 0)
        return nums[0];
    if (n < 0)
        return 0;

    int inc = nums[n] + help(nums, n - 2);
    int exc = help(nums, n - 1);

    return max(inc, exc);
}

int rob(vector<int> &nums)
{
    int n = nums.size();
    return help(nums, n - 1);
}

/*Memoization*/
// TC: O(N)
// SC: O(N) + O(N)
int help(vector<int> &nums, int n, vector<int> &dp)
{
    if (n == 0)
        return nums[0];
    if (n < 0)
        return 0;

    if (dp[n] != -1)
        return dp[n];
    int inc = nums[n] + help(nums, n - 2, dp);
    int exc = help(nums, n - 1, dp);
    dp[n] = max(inc, exc);
    return dp[n];
}

int rob(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, -1);
    return help(nums, n - 1, dp);
}

/*Tabulation*/
// TC: O(N)
// SC: O(N)
int rob(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 0);
    dp[0] = nums[0];
    int neg = 0;
    for (int i = 1; i < n; i++)
    {
        int inc;
        if (i - 2 < 0)
            inc = nums[i] + neg;
        else
            inc = nums[i] + dp[i - 2];
        int exc = dp[i - 1];
        dp[i] = max(inc, exc);
    }
    return dp[n - 1];
}

/*Space optimization*/
// TC: O(N)
// SC: O(1)
int rob(vector<int> &nums)
{
    int n = nums.size();
    int prev = nums[0];
    int prev2 = 0;
    int neg = 0;
    for (int i = 1; i < n; i++)
    {
        int inc = nums[i];
        if (i > 1)
            inc += prev2;
        int exc = prev;
        prev2 = prev;
        prev = max(inc, exc);
    }
    return prev;
}