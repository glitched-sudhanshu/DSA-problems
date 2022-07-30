/*Memoization*/
//TC: O(N*SUM(arr))
//SC: O(N*SUM(arr)) + O(N)

bool help(vector<int> &arr, int n, int s, vector<vector<int>> &dp)
{
    if (s == 0)
        return dp[n][s] = true;
    if (n == 0)
        return dp[n][s] = (arr[n] == s);

    if (dp[n][s] != -1)
        return dp[n][s];

    bool notTake = help(arr, n - 1, s, dp);
    bool take = false;
    if (arr[n] <= s)
        take = help(arr, n - 1, s - arr[n], dp);
    return dp[n][s] = take | notTake;
}

int minSubsetSumDifference(vector<int> &arr, int n)
{
    // Write your code here.
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));

    for (int i = 0; i <= sum; i++)
    {
        help(arr, n - 1, i, dp);
    }

    int mini = 1e9;
    for (int i = 0; i <= sum; i++)
    {
        int s2 = sum - i;
        if (dp[n - 1][i] == 1)
        {
            mini = min(mini, abs(i - s2));
        }
    }
    return mini;
}


//rest methods will also be remain the same as Partition_Equal_Subset_Sum or Subset_sum_equal_to_K
//https://www.codingninjas.com/codestudio/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494?