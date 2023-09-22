class Solution {
public:
    vector<vector<int>> dp;
    int fun(int i,int j,vector<vector<char>> &matrix)
    {
        int n=matrix.size();
        int m=matrix[0].size();
        if(i>=n || j>=m)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(matrix[i][j]=='1')
        {
            int a=1+fun(i+1,j+1,matrix);
            int b=1+fun(i+1,j,matrix);
            int c=1+fun(i,j+1,matrix);
            return dp[i][j]=min({a,b,c});
        }
        else
        {
            return dp[i][j]=0;
        }
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxi=0;
        int n=matrix.size();
        int m=matrix[0].size();
        dp.resize(n,vector<int>(m,-1));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]=='1')
                {
                    maxi=max(maxi,fun(i,j,matrix));
                }
            }
        }
        return maxi*maxi;
    }
};