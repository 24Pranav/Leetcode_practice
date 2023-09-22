class Solution {
public:
    bool dfs(int i, vector<int> adj[], vector<int> &vis, vector<int> &pathvis)
    {
        vis[i]=1;
        pathvis[i]=1;
        
        for(auto &x:adj[i])
        {
            if(!vis[x])
            {
            if(dfs(x,adj,vis,pathvis)==true)
            {
            return true;
            }
            }
            else if(vis[x] && pathvis[x])
            return true;
        }
        pathvis[i]=0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for(int i = 0; i < prerequisites.size(); i++) {
            int v = prerequisites[i][0];
            int u = prerequisites[i][1];
            adj[u].push_back(v);
        }
        int V=numCourses;
        vector<int> vis(V,0);
        vector<int> pathvis(V,0);
        
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            if(dfs(i,adj,vis,pathvis))
            return !true;
        }
        return !false;
    }
};