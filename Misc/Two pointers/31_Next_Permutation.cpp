/*Using STL*/
// TC: O(N)
// SC: O(1)
void nextPermutation(vector<int> &nums)
{
    next_permutation(nums.begin(), nums.end());
}

// The interview required solution is the implementation of this function.
void nextPermutation(vector<int> &nums)
{
    int n = nums.size();
    int idx = 0;
    for (idx = n - 2; idx >= 0; idx--)
    {
        if (nums[idx] < nums[idx + 1])
            break;
    }
    if (idx < 0)
        reverse(nums.begin(), nums.end());
    else
    {
        int l = n - 1;
        int k = idx;
        for (l = n - 1; l > k; l--)
            if (nums[l] > nums[k])
                break;
        swap(nums[l], nums[k]);
        reverse(nums.begin() + k + 1, nums.end());
    }
}

// For intution : https://www.youtube.com/watch?v=LuLCLgMElus

/*
Brute force:
Find all the permutations.
Then find the given permutation.
Return the next permutation.
*/
