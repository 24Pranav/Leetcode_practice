class Solution {
public:
    int fun(vector<int> &cuts,int i, int j,vector<vector<int>> &dp)
    {
        if(i>j)
            return 0;
        int mini=INT_MAX;
        if(dp[i][j]!=-1)
            return dp[i][j];
        for(int ind=i;ind<=j;ind++)
        {
            int cost=cuts[j+1]-cuts[i-1]+fun(cuts,i,ind-1,dp)+fun(cuts,ind+1,j,dp);
            mini=min(mini,cost);
        }
        return dp[i][j]=mini;
    }
    int minCost(int n, vector<int>& cuts) {
        int c=cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        // vector<vector<int>> dp(c+2,vector<int>(c+2,-1));
        // return fun(cuts,1,c,dp);
        
        //Tabulation
        vector<vector<int>> dp(c+2,vector<int>(c+2,0));
        for(int i=c;i>=1;i--)
            for(int j=0;j<=c;j++)
            {
                if(i>j)
                    continue;
        int mini=INT_MAX;
        for(int ind=i;ind<=j;ind++)
        {
            int cost=cuts[j+1]-cuts[i-1]+dp[i][ind-1]+dp[ind+1][j];
            mini=min(mini,cost);
        }
                dp[i][j]=mini;
        }
        return dp[1][c];
    }
};