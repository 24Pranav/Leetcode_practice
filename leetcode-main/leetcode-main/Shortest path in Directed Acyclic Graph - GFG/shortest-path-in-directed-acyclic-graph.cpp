//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
    private:
    //toposort using dfs
    void toposort(int i,vector<pair<int,int>> adj[],vector<int> &vis,stack<int> &st)
    {
        vis[i]=1;
        
        for(auto &x:adj[i])
        {
            int adjnodes=x.first;
            if(!vis[adjnodes])
            toposort(adjnodes,adj,vis,st);
        }
        st.push(i);
    }
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<pair<int,int>> adj[N];
        //making adj matrix
        for(int i=0;i<M;i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            adj[u].push_back({v,w});
        }
        vector<int> vis(N,0);
        stack<int> st;
        
        //toposort
        for(int i=0;i<N;i++){
        if(!vis[i])
        toposort(i,adj,vis,st);
        }
        
        vector<int> dist(N,1e9);
        //src node=0
        dist[0]=0;
        
        while(!st.empty())
        {
            int node=st.top();
            st.pop();
            if(node!=1e9)
            for(auto &it:adj[node])
            {
                int u=it.first;
                int w=it.second;
                
                
                dist[u]=min(dist[u],dist[node]+w);
            }
        }
        for(auto &x:dist)
        if(x==1e9)
        x=-1;
        return dist;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends