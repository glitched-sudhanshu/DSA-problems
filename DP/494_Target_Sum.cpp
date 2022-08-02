/*Space optimized*/
//TC: O(N*target)
//SC: 2*O(target)
int findWays(vector<int> &num, int tar)
{
    // Write your code here.
    int n = num.size();
    vector<int> prev(tar + 1, 0);
    vector<int> cur(tar + 1, 0);
    if (num[0] == 0)
        prev[0] = cur[0] = 2;
    else
        prev[0] = cur[0] = 1;
    if (num[0] <= tar && num[0] != 0)
        prev[num[0]] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= tar; j++)
        {
            int pick = 0;
            if (num[i] <= j)
                pick = prev[j - num[i]];
            int notPick = prev[j];
            cur[j] = (pick + notPick);
        }
        prev = cur;
    }
    return prev[tar];
}

int countPartitions(int n, int d, vector<int> &arr)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    if ((sum - d < 0) || (sum + d < 0) || (sum + d) % 2 != 0)
        return 0;
    return findWays(arr, (sum + d) / 2);
}

int findTargetSumWays(vector<int> &nums, int target)
{
    return countPartitions(nums.size(), target, nums);
}




/*
In this question we have to append +/- and sum them up to make them equal to the target.
If there are N elements and we append + to x elements and - to (N-x) elements and if we add them up it should give target
so it is basically Summation(x) + Summation(n-x), since (n-x) are all -ves so
Summation(x) - Summation(n-x) = t
s1 - s2 = t
this is exactly the same question as Count_partition_with_given_difference
*/