/*Founding LIS*/
// TC: O(N^2)
// SC: O(N)
/*
Here we are just finding the LIS with just a slight change in the check condition:
nums[i] % nums[j] == 0 && 1 + dp[j] > dp[i]
*/
vector<int> largestDivisibleSubset(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 1), hash(n);
    sort(nums.begin(), nums.end());
    int maxi = 0;
    int lastIdx = 0;
    for (int i = 0; i < n; i++)
    {
        hash[i] = i;
        for (int j = 0; j <= i - 1; j++)
        {
            if (nums[i] % nums[j] == 0 && 1 + dp[j] > dp[i])
            {
                dp[i] = 1 + dp[j];
                hash[i] = j;
            }
        }
        if (dp[i] > maxi)
        {
            maxi = dp[i];
            lastIdx = i;
        }
    }

    vector<int> lis;
    lis.push_back(nums[lastIdx]);
    while (hash[lastIdx] != lastIdx)
    {
        lastIdx = hash[lastIdx];
        lis.push_back(nums[lastIdx]);
    }
    return lis;
}