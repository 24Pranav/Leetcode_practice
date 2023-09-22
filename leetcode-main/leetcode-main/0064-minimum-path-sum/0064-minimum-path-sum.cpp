class Solution {
public:
    int fun(int i, int j, vector<vector<int>> &dp, vector<vector<int>>& grid)
    {
        if(i==0 && j==0)
            return grid[0][0];
        if(i<0 || j<0)
            return 1e8;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int  ans1=fun(i-1,j,dp,grid)+grid[i][j]; //Up
        int  ans2=fun(i,j-1,dp,grid)+grid[i][j]; //Left
        return dp[i][j]=min(ans1,ans2);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int sum=fun(n-1,m-1,dp,grid);
        return sum;
    }
};