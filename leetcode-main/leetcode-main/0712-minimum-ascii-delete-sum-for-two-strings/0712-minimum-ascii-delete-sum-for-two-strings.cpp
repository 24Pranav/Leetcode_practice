class Solution {
public:
    using ll=long long;
    ll dp[1001][1001];
    ll lcs(int i,int j,string &s1,string &s2)
    {
        if(i>=s1.size() || j>=s2.size())
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(s1[i]==s2[j])
            return s1[i]+lcs(i+1,j+1,s1,s2);
        else
            return dp[i][j]=max(lcs(i+1,j,s1,s2),lcs(i,j+1,s1,s2));
    }
    int minimumDeleteSum(string s1, string s2) {
        memset(dp,-1,sizeof(dp));
        ll lcsasci=lcs(0,0,s1,s2);
        int sum=0;
        for(auto &x:s1)
            sum+=x;
        for(auto &x:s2)
            sum+=x;
        return sum-2*lcsasci;
    }
};