//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        
        // {{r,c},t}
        queue<pair<pair<int,int>,int>> q;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        
        //Mark vis rotten oranges and and push into the queue with time 0
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},0});
                    vis[i][j]=true;
                }
            }
        }
        
        //bfs traversal
        
        int time=0;
        int drow[]={-1,0,+1,0};
        int dcol[]={0,1,0,-1};
        while(!q.empty())
        {
            auto it=q.front();
            int row=it.first.first;
            int col=it.first.second;
            int tm=it.second;
            time=max(time,tm);
            q.pop();
            for(int i=0;i<4;i++)// 4 directions
            {
                int nr=row+drow[i];
                int nc=col+dcol[i];
                if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc]==1 && !vis[nr][nc])
                {
                    q.push({{nr,nc},tm+1});
                    vis[nr][nc]=true;
                    grid[nr][nc]=2;
                }
            }
        }
        
        // for(int i=0;i<n;i++){
        // for(int j=0;j<m;j++)
        // {
        //     cout<<vis[i][j]<<" ";
        // }
        // cout<<endl;
        // }
        
        // cout<<"---------------------"<<endl;
        //         for(int i=0;i<n;i++){
        // for(int j=0;j<m;j++)
        // {
        //     cout<<grid[i][j]<<" ";
        // }
        // cout<<endl;
        // }
        
        
        //check if all are rooten or not
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            if(!vis[i][j] && grid[i][j]==1)
            return -1;
        }
        return time;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends