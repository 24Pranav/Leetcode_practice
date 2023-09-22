//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  void dfs(int i,int j,vector<vector<int>>& g)
    {
        if(i<0 || j<0 || i>=g.size() || j>=g[0].size())
            return;
        if(g[i][j]==0)
            return;
        g[i][j]=0; //Mark visited
        dfs(i,j+1,g);
        dfs(i,j-1,g);
        dfs(i-1,j,g);
        dfs(i+1,j,g);
    }
    int numberOfEnclaves(vector<vector<int>> &g) {
        // Code here
        int n=g.size();
        int m=g[0].size();
        //1st Row
        for(int i=0;i<m;i++)
            if(g[0][i]==1)
                dfs(0,i,g);
        //last Row
        for(int i=0;i<m;i++)
            if(g[n-1][i]==1)
                dfs(n-1,i,g);
        //1st col
        for(int i=0;i<n;i++)
            if(g[i][0]==1)
                dfs(i,0,g);
        //last col
        for(int i=0;i<n;i++)
            if(g[i][m-1]==1)
                dfs(i,m-1,g);
        int count=0;
        //Counting ones
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(g[i][j]==1)
                    count++;
            }
        }
        return count;
    }
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
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends