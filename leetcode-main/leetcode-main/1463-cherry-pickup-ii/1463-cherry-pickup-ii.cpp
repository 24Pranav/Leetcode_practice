class Solution {
public:
    int fun(int i, int j1, int j2, int r, int c, vector<vector<int>>& grid, vector<vector<vector<int>>> &dp)
    {
        // Base case 1: Out of bound
        if(j1<0 || j1>=c || j2<0 || j2>=c) return -1e9;
        // Base case 2: Reach the destination
        if(i==r-1)
        {
            if(j1==j2) return grid[i][j1]; // Both on same cell then take only once that element
            else
                return grid[i][j1]+grid[i][j2];
        }
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        int maxi=INT_MIN;
        for(int dj1=-1;dj1<=1;dj1++)
        {
            for(int dj2=-1;dj2<=1;dj2++)
            { int ans;
                if(j1==j2)
                    ans=grid[i][j1]+fun(i+1,j1+dj1,j2+dj2,r,c,grid,dp); // down , downleft , downright direction
                 else{
                    ans=grid[i][j1]+grid[i][j2]+fun(i+1,j1+dj1,j2+dj2,r,c,grid,dp);  // down , downleft , downright direction
                 }
                maxi=max(maxi,ans);
            }
        }
        return dp[i][j1][j2]=maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<vector<int>>> dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
        return fun(0,0,c-1,r,c,grid,dp);
    }
};