/*Bit manipulation*/
// TC: O(N)
// SC: O(1)
vector<int> singleNumber(vector<int> &nums)
{
    int cumm_xor = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++)
        cumm_xor ^= nums[i];
    int posi = 0;
    int mask = (1 << posi);
    while (!(cumm_xor & mask))
    {
        posi++;
        mask = (1 << posi);
    }
    int a = 0, b = 0;
    mask = (1 << posi);
    for (int i = 0; i < n; i++)
    {
        if (nums[i] & mask)
            a ^= nums[i];
        else
            b ^= nums[i];
    }
    vector<int> res = {a, b};
    return res;
}