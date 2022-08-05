/*Recursion*/
// TC: O(N^N)
// SC: O(N)
bool help(vector<int> &nums, int n, vector<int> &dp)
{
    if (n >= nums.size() - 1)
        return true;

    for (int i = 1; i <= nums[n]; i++)
    {
        if (help(nums, n + i, dp))
        {
            return true;
        }
    }
    return false;
}

/*Memoization*/
// TC: O(N*N)
// SC: O(N) + O(N)
bool help(vector<int> &nums, int n, vector<int> &dp)
{
    if (n >= nums.size() - 1)
        return true;

    if (dp[n] != -1)
        return dp[n];

    bool jump = false;
    for (int i = 1; i <= nums[n]; i++)
    {
        if (help(nums, n + i, dp))
        {
            return dp[n] = true;
        }
    }
    return dp[n] = false;
}

bool canJump(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, -1);
    return help(nums, 0, dp);
}

/*Tabulation*/
// TC: O(N*N)
// SC: O(N)
bool canJump(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 0);
    dp[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 1; j <= nums[i]; j++)
        {
            if ((i + j >= n - 1) || (dp[i + j]))
            {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[0];
}

/*Greedy*/
// TC: O(N)
// SC: O(1)
/* Here our approach is that if goal is at the ith index and if the maximum jump we can take from the i-1th index is greater than or equal to i, then it means we can reach to the goal from i-1th index. Then we will shift the goal to i-1th index and repeat this process. If at the end goal is at 0th index it means it is possible to reach there else not possible.
https://www.youtube.com/watch?v=Yan0cv2cLy8
*/
bool canJump(vector<int> &nums)
{
    int n = nums.size();
    int goal = n - 1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (i + nums[i] >= goal)
            goal = i;
    }
    return (goal == 0);
}