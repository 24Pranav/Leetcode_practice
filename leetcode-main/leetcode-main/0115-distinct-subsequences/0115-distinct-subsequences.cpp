class Solution {
public:
    int fun(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
    {
        //Base Case
        if(j==0) return 1; // s2 all characters matched in s1
        if(i==0) return 0; // s1 string ended and s2 characters is not matched
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i-1]==s2[j-1])
        {
            return dp[i][j]=fun(i-1,j-1,s1,s2,dp)+fun(i-1,j,s1,s2,dp);
        }
        else
            return dp[i][j]=fun(i-1,j,s1,s2,dp);
    }
    int numDistinct(string &s, string &t) {
        int n=s.size();
        int m=t.size();
        // vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        // return fun(n,m,s,t,dp);
        //Tabulation
        vector<vector<double>> dp(n+1,vector<double>(m+1,0));
        //Base Case
        for(int i=0;i<=n;i++)
            dp[i][0]=1;
        for(int j=1;j<=m;j++) //IMP (Start j from 1 because in above loop we put 1 for j=0)
            dp[0][j]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==t[j-1])
                {
                dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                }
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        return (int)dp[n][m];
    }
};