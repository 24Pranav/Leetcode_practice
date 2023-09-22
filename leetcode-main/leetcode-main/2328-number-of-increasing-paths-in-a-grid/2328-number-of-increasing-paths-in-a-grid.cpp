class Solution {
public:
    const int MOD=1e9+7;
    int n;
    int m;
    int dp[1001][1001];
    vector<vector<int>> dir{{-1,0},{+1,0},{0,-1},{0,+1}};
    bool isValid(int i,int j)
    {
        if(i>=n || i<0 || j>=m || j<0)
            return 0;
        return 1;
    }
    int fun(int i,int j,vector<vector<int>>& grid)
    {
        if(i>=n || i<0 || j>=m || j<0)
            return 0;
        int ans=1; // for len 1 path
        if(dp[i][j]!=-1)
            return dp[i][j];
        for(auto &x:dir)
        {
            int di=i+x[0];
            int dj=j+x[1];
            if(isValid(di,dj))
            {
                if(grid[i][j]>grid[di][dj])
                    ans=(ans+fun(di,dj,grid))%MOD;
            }
        }
        return dp[i][j]=ans%MOD;
    }
    int countPaths(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int ans=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                ans=(ans+fun(i,j,grid))%MOD;
            }
        }
        return ans%MOD;
    }
};