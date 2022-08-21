/*Lis and Lds*/
//TC: O(N^2)
//SC: 2*O(N)
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

int longestBitonicSequence(vector<int> &arr, int n)
{
    vector<int> lis = LIS(arr);
    reverse(arr.begin(), arr.end());
    vector<int> lds = LIS(arr);
    reverse(lds.begin(), lds.end());
    // vector<int> lbs(n, 0);
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        // lbs[i] = lis[i] + lds[i] - 1;
        // maxi = max(maxi, lbs[i]);
        maxi = max(maxi, lis[i] + lds[i] - 1);
    }
    return maxi;
}

//lis: longest increasing subsequence
//lis: longest decreasing subsequence
//lbs: longest bitonic subsequence

