class Solution {
public:
    bool bfs(int start,vector<vector<int>>& graph,vector<int> &color)
    {
        int N=graph.size();
        queue<int> q;
        q.push(start);
        color[start]=0; //Initial color start with 0 or 1
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            
            for(auto &it:graph[node])
            {
                if(color[it]==-1) // If adj nodes is not colored assign oppsite color of node
                {
                    color[it]=!color[node];
                    q.push(it);
                }
                else if(color[it]==color[node]) //Aready visited and colored from some other path and form odd cycle
                    return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        bool ans;
        int N=graph.size();
        vector<int> color(N,-1);
        for(int i=0;i<N;i++) //If graph have multiple compinent
        {
            if(color[i]==-1)
            if(!bfs(i,graph,color))
                return false;
        }
        return true;
    }
};