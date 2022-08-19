/*Recurison*/
// TC: (2^n)
// SC: O(N)
int help(vector<int> &nums, int n, int prev)
{
    if (n == nums.size())
        return 0;

    int take = 0;
    if (prev == -1 || nums[n] > nums[prev])
        take = 1 + help(nums, n + 1, n);
    int notTake = help(nums, n + 1, prev);
    return max(take, notTake);
}

/*Memoization*/
// TC: O(N*N)
// SC: O(N*N) + O(N)
int help(vector<int> &nums, int n, int prev, vector<vector<int>> &dp)
{
    if (n == nums.size())
        return 0;

    if (dp[n][prev + 1] != -1)
        return dp[n][prev + 1];

    int take = 0;
    if (prev == -1 || nums[n] > nums[prev])
        take = 1 + help(nums, n + 1, n, dp);
    int notTake = help(nums, n + 1, prev, dp);
    return dp[n][prev + 1] = max(take, notTake);
}

int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return help(nums, 0, -1, dp);
}

/*Tabulation*/
// TC: O(N*N)
// SC: O(N*N)
int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i - 1; j >= -1; j--)
        {
            int take = 0;
            if (j == -1 || nums[i] > nums[j])
                take = 1 + dp[i + 1][i + 1];
            int notTake = dp[i + 1][j + 1];
            dp[i][j + 1] = max(take, notTake);
        }
    }
    return dp[0][0];
}

/*Space optimized*/
// TC: O(N*N)
// SC: 2*O(N)
int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> prev(n + 1, 0), cur(n + 1, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i - 1; j >= -1; j--)
        {
            int take = 0;
            if (j == -1 || nums[i] > nums[j])
                take = 1 + prev[i + 1];
            int notTake = prev[j + 1];
            cur[j + 1] = max(take, notTake);
        }
        prev = cur;
    }
    return prev[0];
}

/*Space optimized*/
// TC: O(N*N)
// SC: O(N)
// dp[i] signifies the LIS that ends at i
int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 1);
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i - 1; j++)
        {
            if (nums[i] > nums[j])
                dp[i] = max(1 + dp[j], dp[i]);
        }
        maxi = max(dp[i], maxi);
    }
    return maxi;
}

/*Binary Search*/
// TC: O(NlogN)
// SC: O(N)
//in this method lis vector is neither the LIS nor a subsequence it would just help us to get the length of LIS.
int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> lis;
    lis.push_back(nums[0]);
    int len = 1;
    for (int i = 1; i < n; i++)
    {
        if (nums[i] > lis.back())
        {
            lis.push_back(nums[i]);
            len++;
        }
        else
        {
            int idx = lower_bound(lis.begin(), lis.end(), nums[i]) - lis.begin();
            lis[idx] = nums[i];
        }
    }
    return len;
}