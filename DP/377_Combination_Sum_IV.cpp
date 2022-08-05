/*Recursion*/
// TC: O(N^T)
// SC: O(N)
int help(vector<int> &nums, int tar)
{
    if (tar == 0)
        return 1;
    if (tar < 0)
        return 0;

    if (dp[tar] != -1)
        return dp[tar];
    int ans = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        ans += help(nums, tar - nums[i]);
    }

    return ans;
}

/*Memoization*/
// TC: O(N*T)
// SC: O(N) + O(N*T)
int help(vector<int> &nums, int tar, vector<int> &dp)
{
    if (tar == 0)
        return 1;
    if (tar < 0)
        return 0;

    if (dp[tar] != -1)
        return dp[tar];
    int ans = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        ans += help(nums, tar - nums[i], dp);
    }

    return dp[tar] = ans;
}

int combinationSum4(vector<int> &nums, int target)
{
    vector<int> dp(target + 1, -1);
    return help(nums, target, dp);
}

/*Tabulation*/
// TC: O(N*T)
// SC: O(N*T)
int combinationSum4(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<unsigned long long> dp(target + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= target; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (nums[j] <= i)
                dp[i] += dp[i - nums[j]];
        }
    }

    return dp[target];
}