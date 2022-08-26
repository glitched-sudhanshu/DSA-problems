/*Memoization*/
//TC: O(N*TAR)
//SC: O(N*TAR) + O(N)
/*
Basically the helper function is to calculate the subset with given target.
In this ques we just have to solve a prev ques:
subset with given target
*/
bool help(vector<int> &nums, int tar, int n, vector<vector<int>> &dp)
{
    if (tar == 0)
        return true;
    if (n == 0)
    {
        return (nums[0] == tar);
    }
    if (dp[n][tar] != -1)
        return dp[n][tar];
    bool take = false;
    if (nums[n] <= tar)
    {
        take = help(nums, tar - nums[n], n - 1, dp);
    }
    bool notTake = help(nums, tar, n - 1, dp);
    return dp[n][tar] = (take | notTake);
}

bool canPartition(vector<int> &nums)
{
    int n = nums.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
    }
    if (sum & 1)
        return false;
    sum /= 2;
    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
    return help(nums, sum, n - 1, dp);
}
