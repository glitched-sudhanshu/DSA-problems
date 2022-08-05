/*Recursion*/
// TC: O(N^N)
// SC: O(max length of combination)
int help(vector<int> &nums, int n)
{
    if (n >= nums.size() - 1)
    {
        return 0;
    }
    int ans = 1e9;
    for (int i = nums[n]; i >= 1; i--)
    {
        ans = min(ans, 1 + help(nums, n + i, dp));
    }
    return ans;
}

/*Memoization*/
// TC: O(N*N)
// SC: O(max length of combination)
int help(vector<int> &nums, int n, vector<int> &dp)
{
    if (n >= nums.size() - 1)
    {
        return 0;
    }
    if (dp[n] != -1)
        return dp[n];
    int ans = 1e9;
    for (int i = nums[n]; i >= 1; i--)
    {
        ans = min(ans, 1 + help(nums, n + i, dp));
    }
    return dp[n] = ans;
}

int jump(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, -1);
    return help(nums, 0, dp);
}

/*BFS/Greedy*/
// TC: O(N)
// SC: O(1)
int jump(vector<int> &nums)
{
    int jumps = 0;
    int curr_begin = 0, curr_end = 0, next_end = 0;

    while (curr_end < nums.size() - 1)
    {
        for (int i = curr_begin; i <= curr_end; i++)
        {
            next_end = max(next_end, i + nums[i]);
        }
        jumps++;
        curr_begin = curr_end + 1;
        curr_end = next_end;
    }
    return jumps;
}