class Solution {
public:
    int dp[50001];
    using ll=long long;
    ll fun(int i,vector<int> &nums)
    {
        int n=nums.size();
        if(i>=n)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        ll result=nums[i]-fun(i+1,nums);
        if(i+1<n)
        result=max(result,nums[i]+nums[i+1]-fun(i+2,nums));
        if(i+2<n)
        result=max(result,nums[i]+nums[i+1]+nums[i+2]-fun(i+3,nums));
        return dp[i]=result;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        memset(dp,-1,sizeof(dp));
        int ans=fun(0,stoneValue);
        return (ans<0)?"Bob":(ans>0)?"Alice":"Tie";
    }
};