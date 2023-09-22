//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    //Prince Chaurasia
    void dfs(int i,int j,vector<vector<int>>& grid,vector<vector<bool>> &vis,vector<pair<int,int>> &vec,int i0,int j0)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size())
            return;
        if(vis[i][j] || grid[i][j]!=1)
            return;
        vis[i][j]=true; //Mark visited
        vec.push_back({i-i0,j-j0}); // (cordinates - base cordinates) to identify similar components
        dfs(i,j+1,grid,vis,vec,i0,j0); //Right
        dfs(i,j-1,grid,vis,vec,i0,j0); //Left
        dfs(i-1,j,grid,vis,vec,i0,j0); //Up
        dfs(i+1,j,grid,vis,vec,i0,j0); //Down
    }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        set<vector<pair<int,int>>> st;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!vis[i][j] && grid[i][j]==1)
                {
                    vector<pair<int,int>> vec;
                    dfs(i,j,grid,vis,vec,i,j);
                    st.insert(vec);
                }
            }
        }
        
        // for(auto &x:st)
        // {
        //     for(auto &j:x)
        //     cout<<j.first<<" "<<j.second<<endl;
        //     cout<<"-----------"<<endl;
        // }
        return st.size();
    }
//     void dfs(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &vis, vector<pair<int,int>> &island, pair<int,int> initials){
//         // int i = base.first, j = base.second;
//         if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0 || vis[i][j]) return;
//         vis[i][j] = 1;
//         island.push_back({i-initials.first,j-initials.second});
//         dfs(i+1,j,grid,vis,island,initials);
//         dfs(i,j+1,grid,vis,island,initials);
//         dfs(i-1,j,grid,vis,island,initials);
//         dfs(i,j-1,grid,vis,island,initials);
//     }
//   public:
//     int countDistinctIslands(vector<vector<int>>& grid) {
//         // code here
//         int m = grid.size(), n = grid[0].size(), distinctIslands = 0;
//         vector<vector<int>> vis(m,vector<int>(n,0));
//         set<vector<pair<int,int>>> coordinates;
//         for(int i = 0; i < m; ++i){
//             for(int j = 0; j < n; ++j){
//                 if(grid[i][j] == 1 && !vis[i][j]){
//                     vector<pair<int,int>> island;
//                     pair<int,int> initials = {i,j};
//                     dfs(i,j,grid,vis,island,initials);
//                     coordinates.insert(island);
//                 }
//             }
//         }
//         for(auto &x : coordinates) distinctIslands++;
//         return distinctIslands;
//     }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends