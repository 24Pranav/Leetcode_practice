//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
        void dfs(vector<vector<char>> &grid, int i,int j, int n, int m)
    {
        if(i<0 || i>=n || j<0 || j>=m)
            return;
        if(grid[i][j]=='0')
            return;
        grid[i][j]='0';
        dfs(grid,i-1,j,n,m);
        dfs(grid,i+1,j,n,m);
        dfs(grid,i,j-1,n,m);
        dfs(grid,i,j+1,n,m);
        dfs(grid,i-1,j-1,n,m);
        dfs(grid,i+1,j+1,n,m);
        dfs(grid,i+1,j-1,n,m);
        dfs(grid,i-1,j+1,n,m);
    }
    void bfs(vector<vector<char>> &grid, int i,int j, int n, int m, vector<vector<int>> &vis)
    {
        vis[i][j]=1;
        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty())
        {
            auto it=q.front();
            int row=it.first;
            int col=it.second;
            q.pop();
            //traversing neighbours
            for(int dr=-1;dr<=1;dr++)
            {
                for(int dc=-1;dc<=1;dc++)
                {
                    int nr=row+dr;
                    int nc=col+dc;
                    if(nr>=0 && nr<n && nc>=0 && nc<m &&!vis[nr][nc] && grid[nr][nc]=='1')
                    {
                        vis[nr][nc]=1;
                        q.push({nr,nc});
                    }
                }
            }
            
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        //dfs
        // int n=grid.size();
        // int m=grid[0].size();
        // int ans=0;
        // for(int i=0;i<n;i++)
        //     for(int j=0;j<m;j++)
        //     {
        //         if(grid[i][j]=='1')
        //             ans++;
        //         dfs(grid,i,j,n,m);
        //     }
        // return ans;
        //bfs
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int ans=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1' && !vis[i][j])
                    {
                        ans++;
                        bfs(grid,i,j,n,m,vis);
                    }
            }
            return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends