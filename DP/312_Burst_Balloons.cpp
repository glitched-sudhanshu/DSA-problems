/*Memoization*/
// TC: ~O(N^3)
// SC: O(N^2) + O(N)
int help(vector<int> &nums, int i, int j, vector<vector<int>> &dp)
{
    if (i > j)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int maxi = -1e9;
    for (int k = i; k <= j; k++)
    {
        int coins = (nums[i - 1] * nums[k] * nums[j + 1]) + help(nums, i, k - 1, dp) + help(nums, k + 1, j, dp);
        maxi = max(coins, maxi);
    }
    return dp[i][j] = maxi;
}

int maxCoins(vector<int> &nums)
{
    int n = nums.size();
    nums.push_back(1);
    nums.insert(nums.begin(), 1);
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return help(nums, 1, n, dp);
}

/*Tabulation*/
// TC: ~O(N^3)
// SC: O(N^2)
int maxCoins(vector<int> &nums)
{
    int n = nums.size();
    nums.push_back(1);
    nums.insert(nums.begin(), 1);
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
    for (int i = n; i >= 1; i--)
    {
        for (int j = i; j <= n; j++)
        {
            int maxi = -1e9;
            for (int k = i; k <= j; k++)
            {
                int coins = (nums[i - 1] * nums[k] * nums[j + 1]) + dp[i][k - 1] + dp[k + 1][j];
                maxi = max(coins, maxi);
            }
            dp[i][j] = maxi;
        }
    }
    return dp[1][n];
}