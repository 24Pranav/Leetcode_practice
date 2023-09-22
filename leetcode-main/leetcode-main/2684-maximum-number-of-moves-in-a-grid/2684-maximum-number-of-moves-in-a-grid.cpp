class Solution {
public:
    int dp[1001][1001];
    bool isValid(int i,int j,int n,int m)
    {
        if(i>=n || i<0 || j>=m || j<0)
            return false;
        return true;
    }
    int fun(vector<vector<int>> &grid,int i,int j)
    {
        if(i>=grid.size() || j>=grid[0].size() || i<0 || j<0)
            return 0;
        int maxi=0;
        int a,b,c;
        a=b=c=0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(isValid(i-1,j+1,grid.size(),grid[0].size()))
        {
            if(grid[i][j]<grid[i-1][j+1])
                a=1+fun(grid,i-1,j+1);
        }
        if(isValid(i,j+1,grid.size(),grid[0].size()))
        {
            if(grid[i][j]<grid[i][j+1])
                b=1+fun(grid,i,j+1);
        }
        if(isValid(i+1,j+1,grid.size(),grid[0].size()))
        {
            if(grid[i][j]<grid[i+1][j+1])
                c=1+fun(grid,i+1,j+1);
        }
        maxi=max({a,b,c});
        return dp[i][j]=maxi;
    }
    int maxMoves(vector<vector<int>>& grid) {
        int maxi=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<grid.size();i++){
        maxi=max(maxi,fun(grid,i,0));
        }
        return maxi;
    }
};