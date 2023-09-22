class Solution {
public:
        vector<int> dx{1, 2, 1, 2, -1, -2, -1, -2};
        vector<int> dy{2, 1, -2, -1, 2, 1, -2, -1};
    map<pair<pair<int,int>,int>,double> dp;
    double fun(int i,int j,int n,int k)
    {
        if(i<0 || j<0 || i>=n || j>=n)
            return 0;
        if(k==0)
            return 1;
        if(dp.find({{i,j},k})!=dp.end())
            return dp[{{i,j},k}];
        double moves=0;
        for(int ind=0;ind<8;ind++)
        {
            int dr=i+dx[ind];
            int dc=j+dy[ind];
            // cout<<dri<<" "<<dcj;
            moves+=fun(dr,dc,n,k-1);
        }
        return dp[{{i,j},k}]=moves/8;
    }
    double knightProbability(int n, int k, int row, int column) {
        return fun(row,column,n,k);
    }
};