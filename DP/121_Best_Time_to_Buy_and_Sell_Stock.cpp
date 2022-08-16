/*Brute force*/
// TC: O(N^2)
// SC: O(1)
// for every element find the maximum element after it and keep updating the maximum profit made till now.

/*Kadane's*/ //(similar)
// TC: O(N)
// SC: O(1)
// Keep updating the minimum find till now and calculate the maxProfit for every day using the minimum find till that day.
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    int mini = prices[0];
    int maxProfit = 0;
    for (int i = 1; i < n; i++)
    {
        int profit = prices[i] - mini;
        mini = min(mini, prices[i]);
        maxProfit = max(profit, maxProfit);
    }
    return maxProfit;
}