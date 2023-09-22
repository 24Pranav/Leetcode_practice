class Solution {
public:
    long fun(vector<int> &prices, int index, int buy, int cap, vector<vector<vector<int>>> &dp, long profit)
    {
        if(index==prices.size())
            return 0;
        if(cap==0)
            return 0;
        if(dp[index][buy][cap]!=-1)
            return dp[index][buy][cap];
        if(buy)
        {
            //buy
            long profit1=-prices[index]+fun(prices,index+1,0,cap,dp,profit);
            long profit2=0+fun(prices,index+1,1,cap,dp,profit);
            profit= max(profit1,profit2);
        }
        else
        {
            //sell
            long profit1=prices[index]+fun(prices,index+1,1,cap-1,dp,profit);
            long profit2=0+fun(prices,index+1,0,cap,dp,profit);
            profit= max(profit1,profit2);
        }
        return dp[index][buy][cap]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        long profit=0;
        //n-> size 2-> 0/1 buy or not buy cap-> 0/1/2
         // vector<vector<vector<int> > > dp(n, vector<vector<int> >(2, vector<int>(3, -1)));
        // return fun(prices,0,1,2,dp,profit);
        //Tabulation
         vector<vector<vector<int> > > dp(n+1, vector<vector<int> >(2, vector<int>(3,0)));
        //Base Case
        // for(int i=0;i<n;i++)
        //     for(int j=0;j<=2;j++)
        //         dp[i][j][0]=0;
        // for(int j=0;j<=1;j++)
        //     for(int cap=0;cap<=2;cap++)
        //         dp[n][j][cap]=0;
        
        for(int index=n-1;index>=0;index--)
            for(int buy=0;buy<=1;buy++)
                for(int cap=1;cap<=2;cap++)
                {
                    if(buy)
        {
            //buy
            long profit1=-prices[index]+dp[index+1][0][cap];
            long profit2=0+dp[index+1][1][cap];
            profit= max(profit1,profit2);
        }
        else
        {
            //sell
            long profit1=prices[index]+dp[index+1][1][cap-1];
            long profit2=0+dp[index+1][0][cap];
            profit= max(profit1,profit2);
        }
        dp[index][buy][cap]=profit;
                }
        return dp[0][1][2];
    }
};