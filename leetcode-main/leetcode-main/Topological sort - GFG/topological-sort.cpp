//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    private:
    void dfs(int i,vector<int> adj[],stack<int> &st,vector<int> &vis)
    {
        vis[i]=1;
        for(auto &adjnodes:adj[i])
        {
            if(!vis[adjnodes])
                dfs(adjnodes,adj,st,vis);
        }
        st.push(i);
    }
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	   // vector<int> ans,vis(V,0);
	   // stack<int> st;
	   // for(int i=0;i<V;i++)
	   // {
	   //     if(!vis[i])
	   //     dfs(i,adj,st,vis);
	   // }
	    
	   // while(!st.empty())
	   // {
	   //     ans.push_back(st.top());
	   //     st.pop();
	   // }
	   // return ans;
	   
	   //Kahn's Algorithm
	   vector<int> indegree(V,0),ans;
	   queue<int> q;
	   
	   //indgree
	   for(int i=0;i<V;i++)
	   {
	       for(auto &x:adj[i])
	       {
	           indegree[x]++;
	       }
	   }
	   //indgree equals to zero push to queue
	   int in=0;
	   for(auto &x:indegree)
	   {
	       if(x==0)
	       q.push(in);
	       in++;
	   }
	   
	   //BFS traversal
	   while(!q.empty())
	   {
	       int node=q.front();
	       q.pop();
	       ans.push_back(node);
	       
	       for(auto &adjnodes:adj[node])
	       {
	           indegree[adjnodes]--;
	           if(indegree[adjnodes]==0)
	           q.push(adjnodes);
	       }
	   }
	   
	   return ans;
	   
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends