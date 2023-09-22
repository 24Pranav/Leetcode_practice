class Solution {
public:
    int fun(vector<int> &nums,int i,vector<int> &dp)
    {
        if(i>=nums.size())
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int take=nums[i]+fun(nums,i+2,dp);
        int not_take=0+fun(nums,i+1,dp);
        return dp[i]=max(take,not_take);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1);
        return fun(nums,0,dp);
    }
};