/*Lis and counter*/
// TC: O(N^2)
// SC: 2*O(N)
int findNumberOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 1);
    vector<int> cntr(n, 1);
    int mlis = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i - 1; j++)
        {
            if (nums[i] > nums[j] && 1 + dp[j] > dp[i])
            {
                dp[i] = 1 + dp[j];
                // inherit
                cntr[i] = cntr[j];
            }

            else if (nums[i] > nums[j] && 1 + dp[j] == dp[i])
                // increase
                cntr[i] += cntr[j];
        }
        mlis = max(dp[i], mlis);
    }

    int nos = 0;
    for (int i = 0; i < n; i++)
    {
        if (dp[i] == mlis)
            nos += cntr[i];
    }
    return nos;
}
