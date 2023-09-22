class Solution {
public:
    bool dfs(int i,vector<vector<int>> &graph,vector<bool> &vis, vector<bool> &pathvis,vector<bool> &check)
    {
        vis[i]=true;
        pathvis[i]=true;
        for(auto &adjnodes:graph[i])
        {
            if(!vis[adjnodes]){
                if(dfs(adjnodes,graph,vis,pathvis,check)==true){
                    return true;}
            }
            else if(vis[adjnodes] && pathvis[adjnodes]){
                return true;}
        }
        pathvis[i]=false;
        check[i]=true; // If not a part of a cycle or connects to a cycle then only its a safe node
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<bool> vis(n,false),pathvis(n,false),check(n,false);
        vector<int> ans;
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            dfs(i,graph,vis,pathvis,check);
        }
        
        for(int i=0;i<n;i++)
            if(check[i])
                ans.push_back(i);
        
        return ans;
    }
};