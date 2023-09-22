class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<pair<int,int>> adj[n+1];
        for(int i=0;i<times.size();i++)
        {
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        
        int time=0;
        vector<int> dist(n+1,1e9);
        queue<pair<int,int>> q;
        //{src,wt}
        q.push({k,0});
        dist[k]=0;
        while(!q.empty())
        {
            auto it=q.front();
            int node=it.first;
            int dis=it.second;
            q.pop();
            for(auto &it:adj[node])
            {
                int adjnodes=it.first;
                int adjdis=it.second;
                if(dis+adjdis<dist[adjnodes])
                {
                    dist[adjnodes]=dis+adjdis;
                    q.push({adjnodes,dist[adjnodes]});
                }
            }
        }
        
        for(int i=1;i<=n;i++)
        {
            if(dist[i]==1e9)
                return -1;
            time=max(time,dist[i]);
        }
        
        return time;
    }
};