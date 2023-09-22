class Solution
{
    public:
    int dp[2001][2001];
    bool fun(int i,int j, string &s1, string &s2)
    {
        if(i>=s1.size() && j>=s2.size())
            return true;
        if(i>=s1.size() && j<s2.size())
        {
            for(int k=j;k<s2.size();k++)
                if(s2[k]!='*'){
                    // cout<<"j"<<k<<endl;
                    return false;
                }
            return true;
        }
        if(i<s1.size() && j>=s2.size())
            return false;
        if(dp[i][j]!=-1)
            return dp[i][j];
        bool ans=false;
        if(s1[i]==s2[j] || s2[j]=='?')
            ans|=fun(i+1,j+1,s1,s2);
        if(s2[j]=='*')
        {
            ans|=fun(i+1,j,s1,s2) | fun(i,j+1,s1,s2);
        }
        return dp[i][j]=ans;
    }
    bool isMatch(string &s1, string &s2)
    {
        memset(dp,-1,sizeof(dp));
        return fun(0,0,s1,s2);
    }
};