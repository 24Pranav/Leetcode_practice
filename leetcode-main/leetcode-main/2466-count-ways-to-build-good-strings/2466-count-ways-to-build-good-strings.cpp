class Solution {
public:
    using ll=long long;
    const int MOD=1e9+7;
    int dp[100001];
    int fun(int len, int zero, int one)
    {
        if(len==0)
            return 1;
        if(len<=0)
            return 0;
        if(dp[len]!=-1)
            return dp[len];
        int z=fun(len-zero,zero,one);
        int o=fun(len-one,zero,one);
        return dp[len]=(z+o)%MOD;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        memset(dp,-1,sizeof(dp));
        int ans=0;
        for(int i=low;i<=high;i++)
        {
            ans=(ans+fun(i,zero,one))%MOD;
        }
        return ans;
    }
};