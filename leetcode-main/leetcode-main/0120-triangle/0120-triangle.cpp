class Solution {
public:
    // int fun(int i, int j, int m, int n,vector<vector<int>>& grid, vector<vector<int>>& dp)
    // {
    //     if(i==m-1) return grid[m-1][j];
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int d=grid[i][j]+fun(i+1,j,m,n,grid,dp);
    //     int diag=grid[i][j]+fun(i+1,j+1,m,n,grid,dp);
    //     return dp[i][j]=min(d,diag);
    // }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        int n=triangle[0].size();
        vector<vector<int>> dp(m,vector<int>(m,0));
        // return fun(0,0,triangle.size(),triangle[0].size(),triangle,dp);
        //Base Case
        for(int j=0;j<m;j++)
            dp[m-1][j]=triangle[m-1][j];;
        for(int i=m-2;i>=0;i--)
            for(int j=i;j>=0;j--)
            {
                int d=triangle[i][j]+dp[i+1][j];
                int diag=triangle[i][j]+dp[i+1][j+1];
                dp[i][j]=min(d,diag);
            }
        return dp[0][0];
    }
};