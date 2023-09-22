class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n,0);
        
        for(auto &x:edges)
            indegree[x[1]]++;
        
        vector<int> ans;
        int i=0;
        for(auto &x:indegree){
            if(x==0)
                ans.push_back(i);
            i++;
            }
        return ans;
    }
};