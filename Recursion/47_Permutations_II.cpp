/*Brute force*/
// TC: O(N*N!)
// SC: O(N) + O(N!)

void help(set<vector<int>> &ans, vector<int> &nums, int idx)
{
    if (idx == nums.size())
    {
        ans.insert(nums);
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

vector<vector<int>> permute(vector<int> &nums)
{
    set<vector<int>> ans;

    help(ans, nums, 0);

    vector<vector<int>> temp(ans.begin(), ans.end());
    return temp;
}

vector<vector<int>> permuteUnique(vector<int> &nums)
{
    return permute(nums);
}


/*
Need to do the optimized solution of iteration
*/