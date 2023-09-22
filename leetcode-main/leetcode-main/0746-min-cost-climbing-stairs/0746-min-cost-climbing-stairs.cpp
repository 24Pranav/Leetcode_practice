class Solution {
public:
    int ans=INT_MAX;
    int fun(vector<int>&nums,int n,int i,vector<int> &dp)
    {
        if(i>=n)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int one=fun(nums,n,i+1,dp)+nums[i];
        int two=fun(nums,n,i+2,dp)+nums[i];
        ans=min(one,two);
        return dp[i]=ans;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1,-1);
        return min(fun(cost,cost.size(),0,dp),fun(cost,cost.size(),1,dp)); //can start from index 0 or 1 
    }
};