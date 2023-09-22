#define ll long long
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
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