class Solution {
public:
    int maxProfit(vector<int>& prices) {
        long profit=0;
        int n=prices.size();
        // vector<vector<int>> dp(n,vector<int>(2,-1)); //nx2 dp required only
        // return fun(prices,0,1,profit,dp);
        
        //Tabulation
        vector<vector<int>> dp(n+2,vector<int>(2,0));
        //base case
        dp[n][0]=dp[n][1]=0;
        for(int index=n-1;index>=0;index--)
            {
        {
            long profit1=-prices[index]+dp[index+1][0]; //buy
            long profit2=0+dp[index+1][1]; //not buy this time go for next
            dp[index][1]=max(profit1,profit2);
        }
            
        {     
            long profit1=prices[index]+dp[index+2][1]; //sell
            long profit2=0+dp[index+1][0]; // not sell
            dp[index][0]=max(profit1,profit2);
        }
            }
        return dp[0][1];
    }
};