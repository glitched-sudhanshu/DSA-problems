/*Bit manipulation*/
//TC: O(N)
//SC: O(1)
int singleNumber(vector<int> &nums)
{
    int n = nums.size();
    int arr[32] = {0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 32; j++)
        {
            int mask = (1 << j);
            if (nums[i] & mask)
                arr[j]++;
        }
    }
    int num = 0;
    for (int i = 0; i < 32; i++)
    {
        num += (arr[i] % 3) * (1 << i);
    }
    return num;
}