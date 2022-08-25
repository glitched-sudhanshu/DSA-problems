/*Array Prefix and Suffix Products*/
// TC: O(N)
// SC: 2*O(N)
vector<int> productExceptSelf(vector<int> &nums)
{
    int n = nums.size();
    vector<int> fwds(n, 0);
    vector<int> bckwds(n, 0);
    fwds[0] = bckwds[n - 1] = 1;
    for (int i = 1; i < n; i++)
    {
        fwds[i] = fwds[i - 1] * nums[i - 1];
    }
    for (int i = n - 2; i >= 0; i--)
    {
        bckwds[i] = bckwds[i + 1] * nums[i + 1];
    }
    for (int i = 0; i < n; i++)
        fwds[i] *= bckwds[i];

    return fwds;
}

/*Optimized*/
// TC: O(N)
// SC: O(1)
vector<int> productExceptSelf(vector<int> &nums)
{
    int n = nums.size();
    vector<int> fwds(n, 0);
    int bckwds = 1;
    fwds[0] = bckwds = 1;
    for (int i = 1; i < n; i++)
    {
        fwds[i] = fwds[i - 1] * nums[i - 1];
    }
    for (int i = n - 2; i >= 0; i--)
    {
        bckwds *= nums[i + 1];
        fwds[i] *= bckwds;
    }
    return fwds;
}