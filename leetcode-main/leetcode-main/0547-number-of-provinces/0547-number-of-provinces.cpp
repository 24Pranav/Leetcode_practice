class Solution {
public:
    void dfs(int i,vector<vector<int>> &graph,vector<int> &vis)
    {
        vis[i]=1;
        for(int j=0;j<graph.size();j++)
            if(graph[i][j] && !vis[j])
                dfs(j,graph,vis);
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int m=isConnected[0].size();
        int ans=0;
        vector<int> vis(n,0);
            for(int i=0;i<n;i++)
            {
                if(!vis[i])
                {
                    ans++;
                    dfs(i,isConnected,vis);
                }
            }
        return ans;
    }
};