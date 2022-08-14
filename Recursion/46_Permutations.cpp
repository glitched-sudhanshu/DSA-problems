/*Brute force*/
//TC: O(N*N!)
//SC: O(N) + O(N)
void help(vector<vector<int>> &ans, vector<int> &res, vector<int> &nums, int vis[])
{
    if (res.size() == nums.size())
    {
        ans.push_back(res);
        return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if (!vis[i])
        {
            vis[i] = 1;
            res.push_back(nums[i]);
            help(ans, res, nums, vis);
            vis[i] = 0;
            res.pop_back();
        }
    }
    return;
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> res;
    int n = nums.size();
    int vis[n];
    for (int i = 0; i < n; i++)
        vis[i] = 0;
    help(ans, res, nums, vis);
    return ans;
}


/*Space optimized*/
//TC: O(N*N!)
//SC: O(N)
void help(vector<vector<int>> &ans, vector<int> &nums, int idx)
{
    if (idx == nums.size())
    {
        ans.push_back(nums);
        return;
    }

    for (int i = idx; i < nums.size(); i++)
    {
        swap(nums[idx], nums[i]);
        help(ans, nums, idx + 1);
        swap(nums[idx], nums[i]);
    }
    return;
}
