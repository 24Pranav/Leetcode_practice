class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        map<int,set<int>> adj;
        
        for(auto &it:roads)
        {
            int u=it[0];
            int v=it[1];
            adj[u].insert(v);
            adj[v].insert(u);
        }
        int maxi=0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int rank1=adj[i].size();
                int rank2=adj[j].size();
                int total=rank1+rank2;
                if(adj[i].find(j)!=adj[i].end() || adj[j].find(i)!=adj[j].end())
                    total--;
                maxi=max(maxi,total);
            }
        }
        return maxi;
    }
};