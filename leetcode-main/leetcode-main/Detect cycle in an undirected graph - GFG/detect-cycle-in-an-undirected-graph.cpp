//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    bool dfs(int src,int parent,vector<int> adj[],int vis[])
    {
        vis[src]=1;
        
        for(auto adjnodes:adj[src])
        {
            if(!vis[adjnodes])
            {
                vis[adjnodes]=1;
                if(dfs(adjnodes,src,adj,vis)) //src become parent for adjnodes
                return true;
            }
            else if(adjnodes!=parent) return true;
        }
        return false;
    }
    bool bfs(int src,vector<int> adj[],int vis[])
    {
        vis[src]=1;
        
        queue<pair<int,int>> q;
        q.push({src,-1});
        while(!q.empty())
        {
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            //traverse adjacent nodes
            for(auto adjnodes:adj[node])
            {
                if(!vis[adjnodes])
                {
                    vis[adjnodes]=1;
                    q.push({adjnodes,node});
                }
                else if(parent!=adjnodes)
                {
                    return true;
                }
            }
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        int vis[V]={0};
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                //bfs
                // if(bfs(i,adj,vis))
                // return true;
                //dfs
                if(dfs(i,-1,adj,vis))
                return true;
            }
        }
        return false;
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends