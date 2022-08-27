/*Cummulative XOR*/
//TC: O(N)
//SC: O(1)
int singleNumber(vector<int> &nums)
{
    int cumm_xor = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        cumm_xor = cumm_xor ^ nums[i];
    }
    return cumm_xor;
}