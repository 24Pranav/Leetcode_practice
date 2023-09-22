class Solution {
public:
    int dp[201][201];
    bool fun(string s1,string s2, string s3, int i,int j)
    {
        //Base Case
        if(i==s1.size() && j==s2.size() && i+j==s3.size()) //end of string
        {
            return true;
        }
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int k=i+j;
        
        if(i<s1.size() && s1[i]==s3[k])
        {
            bool ans1=fun(s1,s2,s3,i+1,j);
            dp[i][j]=(ans1)?1:0;
            if(ans1)
                return true;
        }
        if(j<s2.size() && s2[j]==s3[k])
        {
            bool ans2=fun(s1,s2,s3,i,j+1);
            dp[i][j]=(ans2)?1:0;
            if(ans2)
                return true;
        }
        dp[i][j]=false;
        return false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+s2.size()!=s3.size())
            return false;
        memset(dp,-1,sizeof(dp));
        return fun(s1,s2,s3,0,0);
    }
};