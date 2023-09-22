class Solution {
public:
    int n,m,dp[101][101];
    bool isValid(int i,int j)
    {
        if(i<0 || i>=n || j<0 || j>=m)
            return false;
        return true;
    }
    int fun(int i, int j,vector<vector<int>> &grid)
    {
        if(!isValid(i,j) || grid[i][j]==1)
            return 0;
        if(i==n-1 && j==m-1)
            return 1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        return dp[i][j]=fun(i+1,j,grid)+fun(i,j+1,grid);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        memset(dp,-1,sizeof(dp));
        n=obstacleGrid.size();
        m=obstacleGrid[0].size();
        return fun(0,0,obstacleGrid);
    }
};