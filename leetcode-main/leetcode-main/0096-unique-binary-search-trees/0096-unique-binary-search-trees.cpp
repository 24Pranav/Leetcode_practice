class Solution {
public:
    int dp[20];
    int fun(int n)
    {
        if(n<=1)
            return 1;
        if(n==2)
            return 2;
        if(n==3) return 5;
        int ans=0;
        if(dp[n]!=-1)
            return dp[n];
        for(int i=1;i<=n;i++)
            ans+=fun(i-1)*fun(n-i);
        return dp[n]=ans;
    }
    int numTrees(int n) {
        memset(dp,-1,sizeof(dp));
        return fun(n);
    }
};