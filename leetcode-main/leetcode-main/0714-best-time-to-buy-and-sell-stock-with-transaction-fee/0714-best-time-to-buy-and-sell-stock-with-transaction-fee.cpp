class Solution {
public:
    using ll=long long;
    ll dp[50001][2];
    int fun(int i,vector<int> &nums,int buy,int fee)
    {
        if(i>=nums.size())
            return 0;
        if(dp[i][buy]!=-1)
            return dp[i][buy];
        int ans=0;
        if(buy)
        {
            ll take=-nums[i]+fun(i+1,nums,0,fee); //buy
            ll not_take=0+fun(i+1,nums,1,fee); //not buy
            ans=max(take,not_take);
        }
        else
        {
            ll take=nums[i]+fun(i+1,nums,1,fee)-fee;
            ll not_take=0+fun(i+1,nums,0,fee);
            ans=max(take,not_take);
        }
        return dp[i][buy]=ans;
    }
    int maxProfit(vector<int>& prices, int fee) {
        memset(dp,-1,sizeof(dp));
        return fun(0,prices,1,fee);
    }
};