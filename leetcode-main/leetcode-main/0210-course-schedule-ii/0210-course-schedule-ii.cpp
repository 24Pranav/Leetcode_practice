class Solution {
public:
    vector<int> findOrder(int N, vector<vector<int>>& prerequisites) {
        //Adj list
        vector<int> adj[N];
	    for(auto &x:prerequisites)
	    {
	        adj[x[1]].push_back(x[0]);
	    }
	    
	    
	    vector<int> indegree(N,0),topo;
	    queue<int> q;
	    //indegree
	    for(int i=0;i<N;i++)
	    {
	        for(auto &x:adj[i])
	        indegree[x]++;
	    }
	    //indegree equels to 0 push in queue
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
	        topo.push_back(node);
	        for(auto &it:adj[node])
	        {
	            indegree[it]--;
	            if(indegree[it]==0)
	            q.push(it);
	        }
	    }
	   // for(auto &x:topo)
	   // cout<<x<<" ";
	   // cout<<endl;
        if(topo.size()==N)
            return topo;
        return {};;
    }
};