class Solution {
public:
    int size;
    int fun(vector<int> &nums, int i,int dp[])
    {
        if(i>=size)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        int take=nums[i]+fun(nums,i+2,dp);
        int not_take=0+fun(nums,i+1,dp);
        return dp[i]=max(take,not_take);
    }
    int rob(vector<int>& nums) {
        int ans=0;
        if(nums.size()==1)
            return nums[0];
        size=nums.size()-1;
        int dp[200];
        memset(dp,-1,sizeof(dp));
        ans=fun(nums,0,dp); //0 to n-1
        size=nums.size();
        memset(dp,-1,sizeof(dp));
        ans=max(ans,fun(nums,1,dp)); //1 to n
        return ans;
    }
};