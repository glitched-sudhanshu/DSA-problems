/*Backtracking*/
//TC:
//SC: 
void help(vector<int> &nums, int tar, int n, vector<int> &t, vector<vector<int>> &ans)
{
    if (tar == 0)
    {
        ans.push_back(t);
        return;
    }
    if (tar < 0)
        return;
    if (n < 0)
        return;
    help(nums, tar, n - 1, t, ans);
    t.push_back(nums[n]);
    help(nums, tar - nums[n], n, t, ans);
    t.pop_back();
}

vector<vector<int>> combinationSum(vector<int> &nums, int tar)
{
    int n = nums.size();
    vector<vector<int>> ans;
    vector<int> t;
    help(nums, tar, n - 1, t, ans);
    return ans;
}