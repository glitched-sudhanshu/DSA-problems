/*Recursion*/
//TC: O(2^n)
//SC: O(N)
int help(vector<int> &prices, int n, bool buy)
{
    if (n == prices.size())
        return 0;

    if (dp[n][buy] != -1)
        return dp[n][buy];

    int profit = 0;
    if (buy)
    {
        profit = max(-prices[n] + help(prices, n + 1, 0), 0 + help(prices, n + 1, 1));
    }
    else
    {
        profit = max(prices[n] + help(prices, n + 1, 1), 0 + help(prices, n + 1, 0));
    }
    return profit;
}

/*Memoization*/
//TC: O(2*N) ~ O(N)
//SC: O(2*N) + O(N)
int help(vector<int> &prices, int n, bool buy, vector<vector<int>> &dp)
{
    if (n == prices.size())
        return 0;

    if (dp[n][buy] != -1)
        return dp[n][buy];

    int profit = 0;
    if (buy)
    {
        profit = max(-prices[n] + help(prices, n + 1, 0, dp), 0 + help(prices, n + 1, 1, dp));
    }
    else
    {
        profit = max(prices[n] + help(prices, n + 1, 1, dp), 0 + help(prices, n + 1, 0, dp));
    }
    return dp[n][buy] = profit;
}

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return help(prices, 0, 1, dp);
}

/*Tabulation*/
//TC: O(2*N) ~ O(N)
//SC: O(2*N)
int maxProfit(vector<int>& prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(2,0));
        dp[n][0] = dp[n][1] = 0;
        for(int i=n-1; i>=0; i--)
        {
            for(int j=0; j<=1; j++)
            {
                int profit = 0;
                if(j)
                    profit = max(-prices[i] + dp[i+1][0], dp[i+1][1]);
                else 
                    profit = max(prices[i] + dp[i+1][1], dp[i+1][0]);
                
                dp[i][j] = profit;
            }
        }
        return dp[0][1];
    }

/*Space otimized*/
//TC: O(2*N) ~ O(N)
//SC: O(1) ~ 2*(2)
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();
        vector<int> ahead(2,0), cur(2,0);
        ahead[0] = ahead[1] = 0;
        for(int i=n-1; i>=0; i--)
        {
            for(int j=0; j<=1; j++)
            {
                int profit = 0;
                if(j)
                    profit = max(-prices[i] + ahead[0], ahead[1]);
                else 
                    profit = max(prices[i] + ahead[1], ahead[0]);
                
                cur[j] = profit;
            }
            ahead = cur;
        }
        return ahead[1];
    }



/*Varibles only*/
//TC: O(N) ~ O(N)
//SC: O(1) 
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();
        int aheadBuy=0, aheadNotBuy = 0;
        int curBuy=0, curNotBuy = 0;
        for(int i=n-1; i>=0; i--)
        {
            curBuy = max(-prices[i] + aheadNotBuy, aheadBuy);
            curNotBuy = max(prices[i] + aheadBuy, aheadNotBuy);
            aheadBuy = curBuy;
            aheadNotBuy = curNotBuy;
        }
        return aheadBuy;
    }
