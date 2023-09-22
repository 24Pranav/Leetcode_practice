//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
#define ll long long
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges,
                 int distanceThreshold) {
                       
        vector<vector<ll>> dist(n,vector<ll>(n,INT_MAX));
        
        for(auto &it:edges)
        {
            dist[it[0]][it[1]]=it[2];
            dist[it[1]][it[0]]=it[2];
        }
        
        for(ll i=0;i<n;i++) dist[i][i]=0;
        
        //FLoyd Warshell
        
        for(ll via=0;via<n;via++)
            for(ll i=0;i<n;i++)
                for(ll j=0;j<n;j++){
                    if(dist[i][via]!=INT_MAX || dist[via][i]!=INT_MAX)
                    dist[i][j]=min(dist[i][j],dist[i][via]+dist[via][j]);
                }
        
        ll countcity=n;
        ll citynumber=-1;
        
        for(ll i=0;i<n;i++)
        {
            ll count=0;
            for(ll j=0;j<n;j++)
            {
                if(dist[i][j]<=distanceThreshold)
                {
                    count++;
                }
            }
            if(count<countcity)
            {
                countcity=count;
                citynumber=i;
            }
            else if(count==countcity)
            {
                citynumber=max(citynumber,i);
            }
            
        }
        return citynumber;
                     
                 }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends