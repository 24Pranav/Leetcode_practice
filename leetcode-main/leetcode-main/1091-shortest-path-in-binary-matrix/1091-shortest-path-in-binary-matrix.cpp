class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
//         pair<int, int> source{0,0};
//         pair<int, int> destination{n-1,m-1};
//         if(grid[0][0]==1)
//             return -1;
//         if(source.first==destination.first && source.second==destination.second) 
//         return 1;
//         queue<pair<int,pair<int,int>>> q;
//         vector<vector<int>> dist(n,vector<int>(m,1e9));
//         dist[source.first][source.second]=1;
//         q.push({1,{source.first,source.second}});
//         int dr[]={-1,0,1,0,-1,1,-1,+1};
//         int dc[]={0,1,0,-1,-1,1,+1,-1};
//         while(!q.empty())
//         {
//             auto it=q.front();
//             int dis=it.first;
//             int r=it.second.first;
//             int c=it.second.second;
//             q.pop();
            
//             for(int i=0;i<8;i++)
//             {
//                 int nrow=r+dr[i];
//                 int ncol=c+dc[i];
//                 if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==0 && dis+1<dist[nrow][ncol])
//                 {
//                     if(nrow==destination.first && ncol==destination.second)
//                     return dis+1;
//                     dist[nrow][ncol]=dis+1;
//                     q.push({dis+1,{nrow,ncol}});
                    
//                 }
//             }
            
//         }
        // return -1;
        
        if(n==1 && m==1 && grid[0][0]!=1)
            return 1;
        if(grid[0][0]==1)
            return -1;
        int dr[]={-1,0,1,0,-1,1,-1,+1};
        int dc[]={0,1,0,-1,-1,1,+1,-1};
        queue<pair<int,pair<int,int>>> q;
        q.push({1,{0,0}});
        
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            int dis=it.first;
            int r=it.second.first;
            int c=it.second.second;
            
            for(int i=0;i<8;i++)
            {
                int nrow=dr[i]+r;
                int ncol=dc[i]+c;
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==0)
                {
                    grid[nrow][ncol]=1; //Mark visited
                    if(nrow==n-1 && ncol==m-1)
                        return dis+1;
                    q.push({dis+1,{nrow,ncol}});
                }
                
            }
        }
        return -1;
    }
};