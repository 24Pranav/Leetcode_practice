class Solution {
public:
    // int fun(int n,vector<int> dp)
    // {
    //     if(n<0) return 0;
    //     if(n==0) return 1;
    //     if(dp[n]!=-1) return dp[n];
    //     int onestep=fun(n-1,dp);
    //     int twostep=fun(n-2,dp);
    //     return dp[n]=onestep+twostep;
    // }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        // return fun(n,dp);
        dp[0]=1;
        dp[1]=2;
        for(int i=2;i<n;i++)
        {
            dp[i]=dp[i-1]+dp[i-2];;
        }
        return dp[n-1];
    }
};