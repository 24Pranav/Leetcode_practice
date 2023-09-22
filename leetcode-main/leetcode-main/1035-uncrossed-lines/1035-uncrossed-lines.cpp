class Solution {
public:
    int n;
    int m;
    int dp[501][501];
    int fun(int i,int j,vector<int> &nums1,vector<int> &nums2)
    {
        if(i>=n || j>=m)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(nums1[i]==nums2[j])
        {
            return dp[i][j]=1+fun(i+1,j+1,nums1,nums2);
        }
        else
        {
            return dp[i][j]=max(fun(i,j+1,nums1,nums2),fun(i+1,j,nums1,nums2));
        }
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1,sizeof(dp));
        n=nums1.size();
        m=nums2.size();
        return fun(0,0,nums1,nums2);
    }
};