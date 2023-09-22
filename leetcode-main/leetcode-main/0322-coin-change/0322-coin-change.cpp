class Solution {
public:
    int fun(int ind,int T, vector<int> &nums, vector<vector<int>> &dp)
    {
    if(ind==0)
    {
        if(T%nums[0]==0) return T/nums[0];
        return 1e9;
    }
    if(dp[ind][T]!=-1) return dp[ind][T];
    int nottake=0+fun(ind-1,T,nums,dp);
    int take=INT_MAX;
    if(nums[ind]<=T)
        take=1+fun(ind,T-nums[ind],nums,dp);
    return dp[ind][T]=min(take,nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
    int ans=fun(coins.size()-1,amount,coins,dp);
    if(ans>=1e9) return -1;
    return ans;
    }
};