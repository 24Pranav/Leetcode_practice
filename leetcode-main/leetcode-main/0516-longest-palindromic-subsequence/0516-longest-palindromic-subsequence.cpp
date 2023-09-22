class Solution {
public:
    //https://leetcode.com/problems/longest-common-subsequence/
    int longestCommonSubsequence(string text1, string text2) {
        //Tabulation
        int n=text1.size(), m=text2.size();
        vector<vector<int>> dp(text1.length()+1,vector<int>(text2.length()+1,0));
        for(int i=0;i<=n;i++)
            dp[i][0]=0;
        for(int j=0;j<=m;j++)
            dp[0][j]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
            if(text1[i-1]==text2[j-1])
            dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
    int longestPalindromeSubseq(string s) {
        string s2="";
        //Reverse
        for(int i=s.size()-1;i>=0;i--)
            s2+=s[i];
        return longestCommonSubsequence(s,s2);
    }
};