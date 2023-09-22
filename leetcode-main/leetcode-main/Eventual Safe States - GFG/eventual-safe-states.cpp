//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
     bool dfs(int i,vector<int> graph[],vector<bool> &vis, vector<bool> &pathvis,vector<bool> &check)
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
    vector<int> eventualSafeNodes(int V, vector<int> graph[]) {
        // code here
         int n=V;
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


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends