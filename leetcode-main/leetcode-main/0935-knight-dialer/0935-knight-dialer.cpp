#define ll long long
class Solution {
public:
    const int MOD=1e9+7;
    long long ans=0;
        vector<int> dr{1, 2, 1, 2, -1, -2, -1, -2};
        vector<int> dc{2, 1, -2, -1, 2, 1, -2, -1};
    long long fun(int i,int j,int n, vector<vector<vector<ll>>> &dp)
    {
        if(i<0 || i>=4 || j<0 || j>=3)
            return 0;
        if( (j==0 && i==3) || (i==3 && j==2) )
            return 0;
        if(n==0)
            return 1;
        if(dp[i][j][n]!=-1)
            return dp[i][j][n];
        
        // for(int k=0;k<8;k++)
        // {
        //     ans=(ans+fun(i+dr[k],j+dc[k],n-1)%MOD)%MOD;
        // }
        // return ans%MOD;
        dp[i][j][n]=(fun(i+dr[0],j+dc[0],n-1,dp)%MOD+fun(i+dr[1],j+dc[1],n-1,dp)%MOD+fun(i+dr[2],j+dc[2],n-1,dp)%MOD+
            fun(i+dr[3],j+dc[3],n-1,dp)%MOD+fun(i+dr[4],j+dc[4],n-1,dp)%MOD+fun(i+dr[5],j+dc[5],n-1,dp)%MOD+
            fun(i+dr[6],j+dc[6],n-1,dp)%MOD+fun(i+dr[7],j+dc[7],n-1,dp)%MOD);
        return dp[i][j][n]%MOD;
    }
    int knightDialer(int n) {
//         int dr[]={1, 2, 1, 2, -1, -2, -1, -2};
//         int dc[]={2, 1, -2, -1, 2, 1, -2, -1};
        
//         int count=0;
//         int k=0;
//         for(int i=0;i<4;i++)
//         {
//             for(int j=0;j<3;j++)
//             {
//                 for(int del=0;del<8;del++)
//                 {
//                 int dx=i+dr[del];
//                 int dy=j+dc[del];
                
//                 if(dx>=0 && dx<4 && dy>=0 && dy<3)
//                 {
//                     k++;
//                     if(k==n){
//                         cout<<i<<" "<<j<<" | ";
//                         cout<<dx<<" "<<dy<<" "<<endl;
//                     count+=1;
//                     k=0;
//                     }
//                 }
                
//             }
//             }
        
        // }
        vector<vector<vector<ll>>> dp(4,vector<vector<ll>>(3,vector<ll>(n+1,-1)));
        int count=0;
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<3;j++)
            {
                count=count%MOD+(fun(i,j,n-1,dp)%MOD);
            }
        }
        return count%MOD;
    }
};