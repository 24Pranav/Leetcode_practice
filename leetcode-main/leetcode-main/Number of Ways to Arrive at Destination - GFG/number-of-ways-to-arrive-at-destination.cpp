//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
#define ll long long
class Solution {
  public:
     const int MOD=1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        // code here
         vector<pair<ll,ll>> adj[n];
        for(auto &it:roads)
        {
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
        vector<ll> dist(n,LLONG_MAX),ways(n,0);
        dist[0]=0;
        ways[0]=1;
        //{weight,node}
        pq.push({0,0});
        
        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            
            ll node=it.second;
            ll dis=it.first;
            
            for(auto &it1:adj[node])
            {
                ll adjnodes=it1.first;
                ll wt=it1.second;
                //first time arriving with shorter distance
                if(dis+wt<dist[adjnodes])
                {
                    dist[adjnodes]=dis+wt;
                    ways[adjnodes]=ways[node];
                    pq.push({dis+wt,adjnodes});
                }
                else if(dis+wt==dist[adjnodes])
                {
                    ways[adjnodes]=(ways[adjnodes]+ways[node])%MOD;
                    // pq.push({dis+wt,adjnodes});
                }
            }
            
        }
        return ways[n-1]%MOD;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends