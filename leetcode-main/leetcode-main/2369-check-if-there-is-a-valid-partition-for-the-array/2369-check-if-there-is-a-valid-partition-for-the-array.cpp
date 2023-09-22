class Solution {
public:
    int dp[100001];
    bool fun(int i,vector<int> &nums)
    {
        if(i>=nums.size())
            return 1;
        if(dp[i]!=-1)
            return dp[i];
        bool ans=false;
        //Rule 1
        if(i+1<nums.size() && nums[i]==nums[i+1])
            ans|=fun(i+2,nums);
        //Rule 2
        if(i+2<nums.size() && nums[i]==nums[i+1] && nums[i+1]==nums[i+2])
            ans|=fun(i+3,nums);
        //Rule 3
        if(i+2<nums.size() && nums[i+1]-nums[i]==1 && nums[i+2]-nums[i+1]==1)
            ans|=fun(i+3,nums);
        return dp[i]=ans;
    }
    bool validPartition(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return fun(0,nums);
    }
};