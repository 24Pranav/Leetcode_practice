class Solution {
public:
    using ll=long long;
    ll n;
    ll dp[100001];
    ll fun(int i,vector<vector<int>> &nums)
    {
        if(i>=n)
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        ll take=fun(i+nums[i][1]+1,nums)+nums[i][0];
        ll skip=fun(i+1,nums);
        return dp[i]=max(take,skip);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        n=questions.size();
        memset(dp,-1,sizeof(dp));
        return fun(0,questions);
    }
};