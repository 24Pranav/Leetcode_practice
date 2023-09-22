class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        if(n==1)
            return {};
        int vis[n];
        memset(vis,0,sizeof(vis));
        int i=0;
        int j=1;
        while(true)
        {
            if(vis[i%n]==1)
                break;
            vis[i%n]=1;
            i+=((j++)*k);
        }
        vector<int> a;
        for(int i=0;i<n;i++)
        {
            // cout<<vis[i]<<"|"<<i<<" ";
            if(vis[i]!=1)
                a.push_back(i+1);
        }
        return a;
    }
};