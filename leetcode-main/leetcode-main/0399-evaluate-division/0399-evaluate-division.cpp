class Solution {
public:
    void dfs(unordered_map<string,vector<pair<string,double>>> &adj,string &src,string &dst,double prod,double &ans,set<string> &vis)
    {
        if(vis.find(src)!=vis.end())
        {
            return;
        }
        
        vis.insert(src);
        
        if(src==dst)
        {
            ans=prod;
            return;
        }
        
        for(auto &x:adj[src])
        {
            string v=x.first;
            double val=x.second;
            dfs(adj,v,dst,prod*val,ans,vis);
        }
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        int n=equations.size();
        unordered_map<string,vector<pair<string,double>>> adj;
        for(int i=0;i<n;i++)
        {
            string u=equations[i][0];
            string v=equations[i][1];
            double val=values[i];
            //a {b,val}
            adj[u].push_back({v,val});
            adj[v].push_back({u,1.0/val});
        }
        
        vector<double> result;
        
        for(auto &x:queries)
        {
            //source
            string src=x[0];
            //destination
            string dst=x[1];
            double ans=-1.0;
            double prod=1.0;
            //visited
            set<string> vis;
            if(adj.find(src)!=adj.end())
            {
                dfs(adj,src,dst,prod,ans,vis);
            }
            result.push_back(ans);
        }
        return result;
    }
};