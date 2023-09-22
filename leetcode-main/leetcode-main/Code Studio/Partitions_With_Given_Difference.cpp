#include <bits/stdc++.h> 
//Prince Chaurasia
//@princeforcode
int mod=(int)(1e9+7);
int fun(int i, int sum,vector<int> &nums, vector<vector<int>> &dp)
{
    if(i==0)
    {
        if(sum==0 && nums[0]==0) return 2;
        if(sum==0 || sum==nums[0]) return 1;
        return 0;
    }
    if(dp[i][sum]!=-1) return dp[i][sum];
    int notpick=fun(i-1,sum,nums,dp);
    int pick=0;
    if(nums[i]<=sum)
        pick=fun(i-1,sum-nums[i],nums,dp);
    return dp[i][sum]=(pick+notpick)%mod;
}
int countPartitions(int n, int d, vector<int> &nums) {
    // Write your code here.
    int totsum=0;
    for(auto x:nums) totsum+=x;
    if((totsum-d)%2) return 0;
    vector<vector<int>> dp(nums.size(),vector<int>(totsum,-1));
    int sum=(totsum-d)/2;
    return fun(n-1,sum,nums,dp);
}