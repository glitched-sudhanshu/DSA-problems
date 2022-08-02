// in this question it is given that if we include "x", then we cannot include "x-1, x+1"
// if you remember in the question house robber, if we include "ith" element, then we cannot inlcude "(i-1)th, (i+1)th" element
// similar intution can be here. Create a freq array where we will update these values to there correspoding indexes.

// help function can be used of house robber

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

int deleteAndEarn(vector<int> &nums)
{
    vector<int> nms(1e4 + 1, 0);

    for (int n : nums)
        nms[n]++;

    for (int i = 0; i < nms.size(); i++)
        nms[i] = nms[i] * i;

    vector<int> dp(1e4 + 1, -1);

    return help(nms, 1e4, dp);
}