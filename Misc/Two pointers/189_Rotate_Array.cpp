/*Brute force*/
// TC: O(N)
// SC: O(N)
void rotate(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<int> ans(nums.size(), 0);

    for (int i = 0; i < n; i++)
    {
        int j = (i + k) % n;
        ans[j] = nums[i];
    }

    for (int i = 0; i < n; i++)
    {
        nums[i] = ans[i];
    }
}

/*Optimized*/
// TC: O(N)
// SC: O(1)
void reverse(vector<int> &num, int i, int j)
{
    while (i < j)
    {
        swap(num[i], num[j]);
        i++;
        j--;
    }
}
void rotate(vector<int> &nums, int k)
{

    int n = (int)nums.size();
    k %= n;
    reverse(nums, 0, n - k - 1);
    reverse(nums, n - k, n - 1);
    reverse(nums, 0, n - 1);
}

/*
Eg. [1,2,3,4,5,6,7]     k=3
    [_,_,_,1,2,3,4] + [5,6,7,_,_,_,_]   <= after k rotations
    5,6,7                   1,2,3,4     <= final ans
    7,6,5                   4,3,2,1     <= reverse each half
    4,3,2,1,7,6,5                       <= add both half (h2+h1)
    5,6,7,1,2,3,4                       <= final ans (reverse again)

    Intution: ulte ka ulta seedha hota h
*/