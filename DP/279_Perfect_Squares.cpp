/*Recursion*/
// TC: O(Exponential)
// SC: O(n)
//for questions of infinite supply you cant tell accurate TC and SC
int help(vector<int> &nums, int n, int tar)
{
    if (n == 0)
    {
        return tar;
    }

    if (tar == 0)
        return 0;

    int notTake = help(nums, n - 1, tar);
    int take = 1e9;
    if (nums[n] <= tar)
        take = 1 + help(nums, n, tar - nums[n]);

    return min(take, notTake);
}

int numSquares(int n)
{
    // vector of possible nums
    vector<int> nums;
    int temp = 1;
    while ((temp * temp) <= n)
    {
        nums.push_back(temp * temp);
        temp++;
    }
    int m = nums.size();
    return help(nums, m - 1, n);
}

/*Memoization*/
//TC: O(N*tar)
//SC: O(N*tar) + O(N)
//here N is number of perfect sq less than N
int help(vector<int> &nums, int n, int tar, vector<vector<int>> &dp)
{
    if (n == 0)
    {
        return tar;
    }

    if (tar == 0)
        return 0;

    if (dp[n][tar] != -1)
        return dp[n][tar];

    int notTake = help(nums, n - 1, tar, dp);
    int take = 1e9;
    if (nums[n] <= tar)
        take = 1 + help(nums, n, tar - nums[n], dp);

    return dp[n][tar] = min(take, notTake);
}

/*Tabulation*/
//TC: O(N*tar)
//SC: O(N*tar)
int numSquares(int n)
{
    // vector of possible nums
    vector<int> nums;
    int temp = 1;
    while ((temp * temp) <= n)
    {
        nums.push_back(temp * temp);
        temp++;
    }
    int m = nums.size();

    // dp portion
    vector<vector<int>> dp(m, vector<int>(n + 1, 0));
    // base case
    for (int i = 0; i <= n; i++)
        dp[0][i] = i;
    for (int i = 0; i < m; i++)
        dp[i][0] = 0;

    for (int i = 1; i < m; i++)
    {
        for (int t = 0; t <= n; t++)
        {
            int notTake = dp[i - 1][t];
            int take = 1e9;
            if (nums[i] <= t)
                take = 1 + dp[i][t - nums[i]];
            dp[i][t] = min(take, notTake);
        }
    }
    return dp[m - 1][n];
}

/*Space optimization*/
//TC: O(N*tar)
//SC: 2*O(tar)
int numSquares(int n)
{
    // vector of possible nums
    vector<int> nums;
    int temp = 1;
    while ((temp * temp) <= n)
    {
        nums.push_back(temp * temp);
        temp++;
    }
    int m = nums.size();

    // dp portion
    vector<int> prev(n + 1, 0);
    vector<int> cur(n + 1, 0);
    // base case
    for (int i = 0; i <= n; i++)
        prev[i] = i;
    cur[0] = prev[0] = 0;

    for (int i = 1; i < m; i++)
    {
        for (int t = 0; t <= n; t++)
        {
            int notTake = prev[t];
            int take = 1e9;
            if (nums[i] <= t)
                take = 1 + cur[t - nums[i]];
            cur[t] = min(take, notTake);
        }
        prev = cur;
    }
    return prev[n];
}

/*Space optimization - 1D array*/
//TC: O(N*tar)
//SC: O(tar)
int numSquares(int n)
{
    vector<int> nums;
    int temp = 1;
    while ((temp * temp) <= n)
    {
        nums.push_back(temp * temp);
        temp++;
    }
    int m = nums.size();

    vector<int> prev(n + 1, 0);
    for (int i = 0; i <= n; i++)
        prev[i] = i;

    for (int i = 1; i < m; i++)
    {
        for (int t = 0; t <= n; t++)
        {
            int notTake = prev[t];
            int take = 1e9;
            if (nums[i] <= t)
                take = 1 + prev[t - nums[i]];
            prev[t] = min(take, notTake);
        }
    }
    return prev[n];
}

/*Mathematics*/

int is_square(int n)
{
    int sqrt_n = (int)(sqrt(n));
    return (sqrt_n * sqrt_n == n);
}

// Based on Lagrange's Four Square theorem, there
// are only 4 possible results: 1, 2, 3, 4.
int numSquares(int n)
{
    // If n is a perfect square, return 1.
    if (is_square(n))
    {
        return 1;
    }

    // The result is 4 if and only if n can be written in the
    // form of 4^k*(8*m + 7). Please refer to
    // Legendre's three-square theorem.
    while ((n & 3) == 0) // n%4 == 0
    {
        n >>= 2;
    }
    if ((n & 7) == 7) // n%8 == 7
    {
        return 4;
    }

    // Check whether 2 is the result.
    int sqrt_n = (int)(sqrt(n));
    for (int i = 1; i <= sqrt_n; i++)
    {
        if (is_square(n - i * i))
        {
            return 2;
        }
    }

    return 3;
}
