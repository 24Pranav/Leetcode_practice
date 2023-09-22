class Solution {
public:
    const int MOD=1e9+7;
    int dp[101][201];
    int fun(int i,vector<int> &nums,int finish,int fuel)
    {
        if(i<0 || i>nums.size())
            return 0;
        if(fuel<0)
            return 0;
        if(dp[i][fuel]!=-1)
            return dp[i][fuel];
        int ans=0;
        if(i==finish)
            ans++;
        for(int k=0;k<nums.size();k++)
            if(i!=k)
                ans=(ans+fun(k,nums,finish,fuel-abs(nums[i]-nums[k])))%MOD;
        return dp[i][fuel]=ans;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        memset(dp,-1,sizeof(dp));
        return fun(start,locations,finish,fuel);
    }
};