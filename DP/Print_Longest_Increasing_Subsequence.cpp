/*Hash and backtrack*/
//TC: O(N*N)
//SC: O(N)
void printLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 1), hash(n);
    int maxi = 0;
    int lastIdx = 0;
    for (int i = 0; i < n; i++)
    {
        hash[i] = i;
        for (int j = 0; j <= i - 1; j++)
        {
            if (nums[i] > nums[j] && 1 + dp[j] > dp[i])
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
    reverse(lis.begin(), lis.end());

    for (auto num : lis)
        cout << num << " ";
}