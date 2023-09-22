class Graph {
public:
    int size;
    vector<vector<pair<int,int>>> adj;
    Graph(int n, vector<vector<int>>& edges) {
        // vector<pair<int,int>> adj[n];
        adj.resize(n);
        int idx=0;
        for(auto &it:edges)
        {
            adj[it[0]].push_back( {it[1],it[2]} );
        }
        size=n;
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[1],edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(size,1e9);
        dist[node1]=0;
        pq.push({0,node1});
        
        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            int node=it.second;
            int dis=it.first;
            if(node==node2)
                return dis;
            for(auto &it:adj[node])
            {
                int adjnodes=it.first;
                int edgwt=it.second;
                
                if(dis+edgwt<dist[adjnodes])
                {
                    dist[adjnodes]=dis+edgwt;
                    pq.push({dis+edgwt,adjnodes});
                }
            }
        }
        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */