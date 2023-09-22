//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        // Code here
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        //src
        dist[0][0]=0;
        pq.push({0,{0,0}});
        int dr[]={0,0,-1,1};
        int dc[]={-1,+1,0,0};
        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            int r=it.second.first;
            int c=it.second.second;
            int dis=it.first;
            
            if(r==n-1 && c==m-1)
                return dis;
            
            
            for(int i=0;i<4;i++)
            {
                int nrow=r+dr[i];
                int ncol=c+dc[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol>=0 && ncol<m && (dist[nrow][ncol]>(abs(heights[r][c]-heights[nrow][ncol]),dis) ))
                {
                    int calc=max(abs(heights[r][c]-heights[nrow][ncol]),dis);
                    dist[nrow][ncol]=calc;
                    pq.push({calc,{nrow,ncol}});
                }
                
                
                
            }
            
            
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends