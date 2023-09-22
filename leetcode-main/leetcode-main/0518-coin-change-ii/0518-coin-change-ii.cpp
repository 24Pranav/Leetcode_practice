class Solution {
public:
    //Memoization
    int fun(int ind, vector<int> &coins, int T, vector<vector<int>> &dp)
    {
        if(ind==0) {
                return T%coins[0]==0;
        }
        if(dp[ind][T]!=-1) return dp[ind][T];
        int nottake=fun(ind-1,coins,T,dp);
        int take=0;
        if(coins[ind]<=T)
            take=fun(ind,coins,T-coins[ind],dp);
        return dp[ind][T]=take+nottake;
    }
    int change(int amount, vector<int>& coins) {
        // vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        // return fun(coins.size()-1,coins,amount,dp);
        //Tabulation
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,0));
        int n=coins.size();
        for(int T=0;T<=amount;T++)
            dp[0][T]=(T%coins[0]==0);
        for(int ind=1;ind<n;ind++)
            for(int T=0;T<=amount;T++)
            {
                int nottake=dp[ind-1][T];
                int take=0;
                if(coins[ind]<=T)
                    take=dp[ind][T-coins[ind]];
                dp[ind][T]=take+nottake;
            }
        return dp[n-1][amount];
    }
};