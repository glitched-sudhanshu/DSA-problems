/*longest bitonic subsequence*/
// TC: O(N^2)
// SC: 2*O(N)
vector<int> LIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 1);
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i - 1; j++)
        {
            if (nums[i] > nums[j] && 1 + dp[j] > dp[i])
            {
                dp[i] = 1 + dp[j];
            }
        }
    }
    return dp;
}

int LBS(vector<int> &arr, int n)
{
    vector<int> lis = LIS(arr);
    reverse(arr.begin(), arr.end());
    vector<int> lds = LIS(arr);
    reverse(lds.begin(), lds.end());
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        if (lis[i] != 1 && lds[i] != 1)
            maxi = max(maxi, lis[i] + lds[i] - 1);
    }
    return maxi;
}

int minimumMountainRemovals(vector<int> &nums)
{
    int n = nums.size();
    return n - LBS(nums, n);
}

/*
the numbers which will not be the part of LBS will be deleted.
Therefore, n - LBS(nums, n)
The only change is that we can't have a LBS that is only decreasing or only increasing,
it needs to be increasing->decreasing.
That is why while calculating the maxi length of LBS the condition is introduced:
if (lis[i] != 1 && lds[i] != 1)
            maxi = max(maxi, lis[i] + lds[i] - 1);
*/