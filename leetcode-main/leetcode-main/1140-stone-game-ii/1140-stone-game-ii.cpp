class Solution {
public:
    int dp[2][101][101];
    using ll=long long;
    ll fun(int p,int i,int m,vector<int> &piles)
    {
        int n=piles.size();
        if(i>=n)
            return 0;
        if(dp[p][i][m]!=-1)
            return dp[p][i][m];
        ll stones=0;
        ll result=(p==1)?-1:INT_MAX; //alice =-1, bob =INT_MAX
        for(int x=1;x<=min(2*m,n-i);x++)
        {
            stones+=piles[i+x-1];
            if(p==1){
                result=max(result,stones+fun(0,i+x,max(m,x),piles));
            }
            else{
                result=min(result,fun(1,i+x,max(m,x),piles));
            }
        }
        return dp[p][i][m]=result;
    }
    int stoneGameII(vector<int>& piles) {
        memset(dp,-1,sizeof(dp));
        return fun(1,0,1,piles);
    }
};