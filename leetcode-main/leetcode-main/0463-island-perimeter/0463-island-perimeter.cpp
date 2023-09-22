class Solution {
public:
    using ll=long long;
    int n;
    int m;
    int dfs(int i,int j,vector<vector<int>> &grid,vector<vector<int>> &vis)
    {
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j]==0)
            return 1;
        if(vis[i][j])
            return 0;
        vis[i][j]=1;
        // int ans=0;
           return dfs(i,j-1,grid,vis)+dfs(i,j+1,grid,vis)+dfs(i-1,j,grid,vis)+dfs(i+1,j,grid,vis);
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        ll ans=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    ans+=dfs(i,j,grid,vis);
                }
            }
        }
        return ans;
    }
};