/*Binary search*/
// TC: O(logN)
// SC: O(1)
int singleNonDuplicate(vector<int> &nums)
{
    int n = nums.size();
    int l = 0, h = n - 1;
    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        if (((mid ^ 1) < n - 1) && nums[mid] == nums[mid ^ 1])
            l = mid + 1;
        else
            h = mid - 1;
    }
    return nums[l];
}