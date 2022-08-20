/*Greedy and hashing*/
//TC: O(N)
//SC: O(N)
bool isPossible(vector<int> &nums)
{
    int n = nums.size();
    // am:availability map
    unordered_map<int, int> am;
    // am:vaccancy map
    unordered_map<int, int> vm;
    for (int i = 0; i < n; i++)
        am[nums[i]]++;

    for (int i = 0; i < n; i++)
    {
        int x = nums[i];
        if (am[x] <= 0)
            continue;
        else if (vm[x] > 0)
        {
            // number consumed
            am[x]--;
            // vaccancy consumed
            vm[x]--;
            // new vaccancy created
            vm[x + 1]++;
        }
        else if (am[x] && am[x + 1] && am[x + 2])
        {
            am[x]--;
            am[x + 1]--;
            am[x + 2]--;
            vm[x + 3]++;
        }
        else
            return false;
    }
    return true;
}

/*Most optimized*/
// TC: O(N)
// SC: O(1)
// https://leetcode.com/problems/split-array-into-consecutive-subsequences/discuss/106495/Java-O(n)-time-and-O(1)-space-solution-greedily-extending-shorter-subsequence
