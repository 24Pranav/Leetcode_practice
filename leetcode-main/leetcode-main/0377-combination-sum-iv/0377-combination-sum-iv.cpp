class Solution {
public:
    int dp[1001];
    int fun(int i,vector<int>& nums, int target)
    {
        if(target==0)
        return 1;
        if(i>=nums.size() || target <0)
            return 0;
        if(dp[target]!=-1)
            return dp[target];
        int take=fun(0,nums,target-nums[i]); // If taken next element will start from index 1
        int not_take=fun(i+1,nums,target);
        return dp[target]=take+not_take;
    }
    int combinationSum4(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        return fun(0,nums,target);
    }
};