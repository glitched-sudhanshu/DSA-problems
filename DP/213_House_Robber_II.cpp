// since the only change in question from house robber 1 is that, here house 1 and house n are also neighbour. So, we can either choose one of them. So we can use the same function of house robber 1 but while calling it once we will not pass the 1st house and the other time we will not pass the last house. And calculate the maximum among these 2 options.

/*Space optimized*/
// TC: O(N)
// SC: O(1)
int robh(vector<int> &nums, int s, int n)
{
    int prev = nums[s];
    int prev2 = 0;
    int neg = 0;
    for (int i = s; i < n; i++)
    {
        int inc = nums[i];
        if (i > s + 1)
            inc += prev2;
        int exc = prev;
        prev2 = prev;
        prev = max(inc, exc);
    }
    return prev;
}

int rob(vector<int> &nums)
{

    int n = nums.size();
    if (n == 1)
        return nums[0];
    int ans1 = robh(nums, 0, n - 1);
    int ans2 = robh(nums, 1, n);
    return max(ans2, ans1);
}